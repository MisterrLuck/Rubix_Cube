cmake_minimum_required(VERSION 4.2)
project(Rubix)

include_directories(include/)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubix src/main.cpp
				src/cube.cpp
				src/move.cpp
				include/cube.hpp
				include/move.hpp)
