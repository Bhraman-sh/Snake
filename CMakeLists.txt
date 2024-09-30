cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(snake VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the Raylib library and include directory
set(RAYLIB_DIR /home/bhraman/raylib/build/raylib)  # Path to raylib .so file
set(RAYLIB_INCLUDE_DIR /home/bhraman/raylib/src)   # Path to raylib headers

# Add source files from the src directory
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Add executable target (main.cpp in root + sources from src/)
add_executable(snake main.cpp ${SOURCES})

# Add the include directory for the project's headers
target_include_directories(snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add Raylib's include directory
target_include_directories(snake PUBLIC ${RAYLIB_INCLUDE_DIR})

# Link Raylib's shared library (.so) and other required libraries
target_link_libraries(snake ${RAYLIB_DIR}/libraylib.so pthread dl m rt X11)

# Optionally, set output directory for the executable
#set_target_properties(raylib_project PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
