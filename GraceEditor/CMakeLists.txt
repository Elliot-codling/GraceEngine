cmake_minimum_required(VERSION 3.25)
project(GraceEditor)

# Add all the files for the engine
add_executable(${PROJECT_NAME} main.cpp)

#Make everything in the library static
#Static link gcc runtime and c++ standard library
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    #GNU SPECIFIC WINDOWS SPECIFIC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

#Link with GraceEngine
target_link_libraries(${PROJECT_NAME} PRIVATE GraceEngine)

# Include engine headers
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/GraceEngine/src
)

# Include the assets required to run the project - change if necessary
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/assets ${CMAKE_BINARY_DIR}/bin/assets
)
