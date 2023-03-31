cmake_minimum_required(VERSION 3.0.0)
project(Main VERSION 0.1.0)
add_subdirectory(CCI)
add_subdirectory(googletest)
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

include(CTest)
enable_testing()

add_executable(Main main.cpp)
target_link_libraries(Main CCI)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
