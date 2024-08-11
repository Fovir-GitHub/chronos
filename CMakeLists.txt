cmake_minimum_required(VERSION 3.30.2)

project(chronos VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(src/include/cjson)
include_directories(src/include)

add_executable(chronos src/main.c)