cmake_minimum_required(VERSION 3.0.0)
project (CCI)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(CCI SHARED 
                src/Examples.cpp 
                src/Objects.cpp
                # src/BigO.cpp 
                src/Chapter1-ArraysAndStrings.cpp 
                src/Chapter2-LinkedLists.cpp 
                src/Chapter3-StacksAndQueues.cpp 
                src/Chapter4-TreesAndGraphs.cpp 
                src/Chapter5-BitManipulation.cpp 
                src/Chapter6-MathAndLogicPuzzles.cpp 
                src/Chapter7-ObjectOrientedDesign.cpp 
                src/Chapter8-RecursionAndDynamicProgramming.cpp 
                src/Chapter9-SystemDesignAndScalability.cpp 
                src/Chapter10-SortingAndSearching.cpp 
                src/Chapter11-Testing.cpp
                src/Chapter12-CandCplusplus.cpp
                src/Chapter13-Java.cpp
                src/Chapter14-Databases.cpp
                src/Chapter15-ThreadsAndLocks.cpp
                src/Chapter16-Moderate.cpp
                src/Chapter17-Hard.cpp
                )

add_executable(Chapter1 tests/Chapter1.cpp) # add this executable
add_executable(Chapter2 tests/Chapter2.cpp) # add this executable
add_executable(Chapter3 tests/Chapter3.cpp) # add this executable
add_executable(Chapter4 tests/Chapter4.cpp) # add this executable
add_executable(Chapter16 tests/Chapter16.cpp) # add this executable
# add_executable(AllTests tests/Chapter1.cpp tests/Chapter2.cpp tests/Chapter3.cpp) # add this executable
target_link_libraries(Chapter1 PUBLIC CCI PRIVATE gtest)
target_link_libraries(Chapter2 PUBLIC CCI PRIVATE gtest)
target_link_libraries(Chapter3 PUBLIC CCI PRIVATE gtest)
target_link_libraries(Chapter4 PUBLIC CCI PRIVATE gtest)
target_link_libraries(Chapter16 PUBLIC CCI PRIVATE gtest)

