cmake_minimum_required(VERSION 3.25)
project(GraceEngine)
set(CMAKE_CXX_STANDARD 17)

set(CXX_COMPILER ${CMAKE_CXX_COMPILER_ID})

#Download SFML
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.2
)
set(SFML_STATIC_LIBRARIES TRUE CACHE BOOL "Use SFML as static" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libs" FORCE)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_USE_SYSTEM_DEPS OFF CACHE BOOL "Use system dependencies" FORCE)

FetchContent_MakeAvailable(SFML)

#Grab all cpp files from src
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

#Make Grace Engine a static library
add_library(GraceEngine STATIC ${ENGINE_SRC})

#Include the directories src for the cpp files
target_include_directories(GraceEngine PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
)
#Set sfml as static UNLESS os is linux
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

#Keep public - SFML static must be  known to all files
target_compile_definitions(GraceEngine PUBLIC SFML_STATIC)

# Link SFML - must be public for game to use
target_link_libraries(GraceEngine PUBLIC sfml-graphics sfml-window sfml-system)