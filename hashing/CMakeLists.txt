cmake_minimum_required(VERSION 3.13)
project(Hashing)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hashing main.cpp LinearProbing.h Crime.cpp Crime.h BlindHashing.h SeparateChaining.h QuadraticProbing.h QuadraticFreddieHash.h SeparateChainingFreddieHash.h)