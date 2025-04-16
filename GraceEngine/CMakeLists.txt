cmake_minimum_required(VERSION 3.30)
project(GraceEngine)

set(CMAKE_CXX_STANDARD 17)

#Grab all cpp files from src
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)

add_library(GraceEngine STATIC ${ENGINE_SRC})

target_include_directories(GraceEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Find SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/sfml-2.6.2/lib/cmake/SFML")  # Adjust path if necessary
find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)

target_compile_definitions(GraceEngine PUBLIC SFML_STATIC)

# Link SFML
target_link_libraries(GraceEngine PUBLIC sfml-graphics sfml-window sfml-system)