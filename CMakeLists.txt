cmake_minimum_required(VERSION 3.30.2)

project(chronos VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(src/include)

file(GLOB SOURCES "src/*.c" )

add_executable(chronos ${SOURCES})