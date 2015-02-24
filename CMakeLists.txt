cmake_minimum_required(VERSION 2.6)
project(euler)

add_executable(euler main.cpp)

install(TARGETS euler RUNTIME DESTINATION bin)
