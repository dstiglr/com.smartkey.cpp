cmake_minimum_required(VERSION 3.14)

project(FluidSimulation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Particle.cpp src/Vector2d.cpp)
add_executable(FluidSimulation ${SOURCE_FILES})
include_directories(/usr/local/include)
add_library(KdTree
   ../KdTree/include/Point.h
   ../KdTree/src/Point.cpp
)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(FluidSimulation KdTree sfml-system sfml-window sfml-graphics sfml-audio sfml-network)