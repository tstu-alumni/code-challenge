cmake_minimum_required(VERSION 3.5)
project(cpp_practical_lab)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CustomVector.cpp CustomVector.h CustomStruct.h CustomStruct.cpp TestPractice.cpp TestPractice.h XTest.h)
add_executable(cpp_practical_lab ${SOURCE_FILES})
