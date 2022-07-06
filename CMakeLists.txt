cmake_minimum_required(VERSION 3.2)
project(maze-solver)
include_directories(src/include)
add_executable(maze-solver
  main.cpp
  src/coordinate.cpp
  src/maze.cpp
  src/node.cpp
  src/stackfrontier.cpp
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")