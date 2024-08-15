file(GLOB SOURCES "*.c")

include_directories(${CMAKE_SOURCE_DIR}/src/main/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CJSON REQUIRED libcjson)

add_executable(chronos ${SOURCES})

target_link_libraries(chronos ${CJSON_LIBRARIES})