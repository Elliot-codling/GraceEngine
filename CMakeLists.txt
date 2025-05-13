cmake_minimum_required(VERSION 3.25)
project(GraceEngine)
set(CMAKE_CXX_STANDARD 17)

# Set the binary exe file to a bin folder inside the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories
add_subdirectory(GameTesting)
add_subdirectory(GraceEngine)