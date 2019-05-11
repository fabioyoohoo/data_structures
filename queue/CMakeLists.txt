cmake_minimum_required(VERSION 3.13)
project(Lecturer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lecturer main.cpp Lecturer.cpp Lecturer.h Stack.h Node.h Queue.h)