set(SOURCES timer.c)

include_directories(${CMAKE_SOURCE_DIR}/src/timer/include)
include_directories(${CMAKE_SOURCE_DIR}/src/main/include)

add_executable(timer ${SOURCES})