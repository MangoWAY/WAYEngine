cmake_minimum_required(VERSION 2.8)
project(test_opengl)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(/usr/local/include)
include_directories(./include)
aux_source_directory("./src" SRCS)

set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wformat")

link_directories(/usr/local/Cellar/glfw/3.3.6/lib)
add_executable(test_opengl ${SRCS} ${HDRS})

target_link_libraries(test_opengl GLFW)