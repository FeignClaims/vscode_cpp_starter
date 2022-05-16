cmake_minimum_required(VERSION 3.22.2)
project(cpp-practice)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -g -pthread -pedantic -Wall -Wcast-align -Wdouble-promotion -Wextra -Wformat=2 -Wimplicit-fallthrough -Wmisleading-indentation -Wnon-virtual-dtor -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wshadow -Wunused"
)

file(GLOB_RECURSE files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(structure ${files})
