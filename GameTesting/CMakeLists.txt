cmake_minimum_required(VERSION 3.30)
project(GameTesting)

# Add all the files for the engine
add_executable(GameTesting main.cpp)

#Link with GraceEngine
target_link_libraries(GameTesting PRIVATE GraceEngine)

# Include engine headers
target_include_directories(GameTesting PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/GraceEngine/src
)

# Include the assets required to run the project
add_custom_command(
        TARGET GameTesting POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/assets ${CMAKE_BINARY_DIR}/bin/assets
)
