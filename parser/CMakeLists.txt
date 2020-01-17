cmake_minimum_required(VERSION 3.15)
project(parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(parser main.cpp Student.h Group.h Student.cpp Group.cpp Dean.h Dean.cpp)