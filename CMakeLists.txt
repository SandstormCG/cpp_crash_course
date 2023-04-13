cmake_minimum_required(VERSION 3.0)

project(crash_course_cpp)

add_executable(crash_course_cpp main.cpp)

install(TARGETS crash_course_cpp RUNTIME DESTINATION bin)
