cmake_minimum_required(VERSION 2.8)
project(List)
file(GLOB src List1.c)
add_executable(${PROJECT_NAME} ${src})