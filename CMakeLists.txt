cmake_minimum_required(VERSION 3.14)
project(GraceEditor)

# Set the binary exe file to a bin folder inside the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories
add_subdirectory(core)


file(GLOB SOURCE src/*.cpp include/*.h)

# Add all the files for the engine
add_executable(${PROJECT_NAME} ${SOURCE})

#Remove terminal in windows if on release build
##if (WIN32)
##    if (MSVC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC")
##        # MSVC or Clang-cl (Visual Studio)
##        set_target_properties(${PROJECT_NAME} PROPERTIES
##                LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS"
##                LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS"
##        )
##    elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
##        # MinGW GCC or Clang (MinGW-style)
##        set_target_properties(${PROJECT_NAME} PROPERTIES
##                LINK_FLAGS_RELEASE "-mwindows"
##        )
##    endif()
##endif()
#Make everything in the library static
#Static link gcc runtime and c++ standard library
if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")  AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    #GNU SPECIFIC WINDOWS SPECIFIC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

#Link with GraceEngine
target_link_libraries(${PROJECT_NAME} PRIVATE GraceEngine)

# Include engine source files
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

# Include the assets required to run the project - change if necessary
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/bin/assets
)
