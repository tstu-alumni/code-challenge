cmake_minimum_required(VERSION 3.6)
project(ChemProcess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ChProcess.cpp ProcessFacade.cpp ProcessFacade.h)
add_executable(ChemProcess ${SOURCE_FILES})