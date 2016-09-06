cmake_minimum_required(VERSION 3.5)
project(cpp_practical_lab)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CustomVector.cpp CustomVector.h CustomStruct.h CustomStruct.cpp XTestRunnerDaemon.cpp XTestRunnerDaemon.h XTest.h XTestPractice.h XTestPractice.cpp XTestRunner.h)
add_executable(cpp_practical_lab ${SOURCE_FILES})
