cmake_minimum_required(VERSION 3.10)

project(chronos VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CJSON REQUIRED libcjson)

include_directories(src/include)

file(GLOB SOURCES "src/*.c" )

add_executable(chronos ${SOURCES})

target_link_libraries(chronos ${CJSON_LIBRARIES})