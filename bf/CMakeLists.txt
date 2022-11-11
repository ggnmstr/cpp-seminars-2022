cmake_minimum_required(VERSION 3.21)

project(bfinterpret VERSION 1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(main main.cpp)

SET(WARN_FLAGS "-Wall -Wpedantic -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} -g ")