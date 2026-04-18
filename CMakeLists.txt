cmake_minimum_required(VERSION 3.29)
project(Math_Graph)

set(CMAKE_CXX_STANDARD 20)
find_package(raylib CONFIG REQUIRED)
add_executable(Math_Graph main.cpp
        Ball.cpp
        Ball.h
        Paddle.cpp
        Paddle.h
        CpuPaddle.cpp
        CpuPaddle.h)
target_link_libraries(Math_Graph PRIVATE raylib)