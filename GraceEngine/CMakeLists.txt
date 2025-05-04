cmake_minimum_required(VERSION 3.29)
project(GraceEngine)
set(CMAKE_CXX_STANDARD 17)

#Grab all cpp files from src
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

#Make Grace Engine a static library
add_library(GraceEngine STATIC ${ENGINE_SRC})

#Include the directories src for the cpp files
target_include_directories(GraceEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#Set sfml as static
set(SFML_STATIC_LIBRARIES TRUE)
# Find SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/sfml-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)

#Keep private - SFML static only used for graceEngine
target_compile_definitions(GraceEngine PRIVATE SFML_STATIC)

# Link SFML - must be public for game to use
target_link_libraries(GraceEngine PUBLIC sfml-graphics sfml-window sfml-system)