file(GLOB TIMER_SRC "${CMAKE_SOURCE_DIR}/src/timer/*.c")
file(GLOB MAIN_SRC "${CMAKE_SOURCE_DIR}/src/main/*.c")
list(REMOVE_ITEM MAIN_SRC "${CMAKE_SOURCE_DIR}/src/main/main.c")

include_directories(${CMAKE_SOURCE_DIR}/src/timer/include)
include_directories(${CMAKE_SOURCE_DIR}/src/main/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CJSON REQUIRED libcjson)

add_executable(chronos-timer ${TIMER_SRC} ${MAIN_SRC})

target_link_libraries(chronos-timer ${CJSON_LIBRARIES})