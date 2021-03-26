cmake_minimum_required(VERSION 3.5)

project(Transporter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_library(
    core
    Mesh.hpp
    Mesh.cpp
    Transporter.cpp
    Transporter.hpp
    Grid.hpp
    Grid.cpp
    )

add_executable(Transporter main.cpp)
target_link_libraries(Transporter PRIVATE core)
