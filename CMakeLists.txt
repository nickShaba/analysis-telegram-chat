cmake_minimum_required(VERSION 3.27)
project(reader)

set(CMAKE_CXX_STANDARD 17)

add_executable(reader
        timeChecker.cpp
        main.cpp)
