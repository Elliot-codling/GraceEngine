cmake_minimum_required(VERSION 3.29)
project(GraceEngine)
set(CMAKE_CXX_STANDARD 17)

set(CXX_COMPILER ${CMAKE_CXX_COMPILER_ID})

#Grab all cpp files from src
if(CXX_COMPILER STREQUAL "MSVC")
    set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external/sfml-2.6.2-msvc")    #MSVC SPECIFIC
endif()

file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

#Make Grace Engine a static library
add_library(GraceEngine STATIC ${ENGINE_SRC})

#Include the directories src for the cpp files
if(CXX_COMPILER STREQUAL "MSVC")
    #MSVC SPECIFIC
    target_include_directories(GraceEngine PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${SFML_ROOT}/include
    )
    target_link_directories(GraceEngine PUBLIC ${SFML_ROOT}/lib)           #NEEDED - MSVC
endif()
if(CXX_COMPILER STREQUAL "GNU")
    #GNU SPECIFIC
    target_include_directories(GraceEngine PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
endif()

#Set sfml as static UNLESS os is linux
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

# Find SFML
if(CXX_COMPILER STREQUAL "GNU")
    #GNU SPECIFIC
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/sfml-2.6.2-gcc/lib/cmake/SFML")
    find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)
endif()

#Keep public - SFML static must be  known to all files
target_compile_definitions(GraceEngine PUBLIC SFML_STATIC)

# Link SFML - must be public for game to use
if(CXX_COMPILER STREQUAL "GNU")
    #GNU SPECIFIC
    target_link_libraries(GraceEngine PUBLIC sfml-graphics sfml-window sfml-system)
endif()
if(CXX_COMPILER STREQUAL "MSVC")
    #MSVC SPECIFIC
    target_link_libraries(GraceEngine PUBLIC sfml-graphics-s sfml-window-s sfml-system-s freetype opengl32 winmm gdi32)
endif()