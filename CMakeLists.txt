cmake_minimum_required(VERSION 3.0)

project(effective-cpp)

add_executable(effective-cpp main.cpp)

install(TARGETS effective-cpp RUNTIME DESTINATION bin)
