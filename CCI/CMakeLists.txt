cmake_minimum_required(VERSION 3.0.0)
project (CCI)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(CCI SHARED 
                src/Examples.cpp 
                # src/BigO.cpp 
                # src/SortingAndSearching.cpp 
                src/Chapter16-Moderate)