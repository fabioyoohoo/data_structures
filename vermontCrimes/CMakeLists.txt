cmake_minimum_required(VERSION 3.13)
project(VermontCrimes)

set(CMAKE_CXX_STANDARD 14)

add_executable(VermontCrimes main.cpp Crime.cpp Crime.h Node.h Stack.h Queue.h)