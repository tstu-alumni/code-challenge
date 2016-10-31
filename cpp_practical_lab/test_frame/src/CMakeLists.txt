set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
include_directories(${PROJECT_SOURCE_DIR}/headers)
set(SOURCE_FILES main.cpp
        CustomVector.cpp
        CustomStruct.cpp
        XTestRunnerDaemon.cpp
        XTestPractice.cpp)
add_executable(test_frame ${SOURCE_FILES})