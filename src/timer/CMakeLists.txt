set(SOURCES timer.c)

include_directories(${CMAKE_SOURCE_DIR}/src/timer/include)

add_executable(timer ${SOURCES})