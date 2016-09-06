set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
include_directories(${PROJECT_SOURCE_DIR}/headers)
#link_directories($(cpp_practical_lab_SOURCE_DIR)/src)
set(SOURCE_FILES main.cpp
        CustomVector.cpp
        CustomStruct.cpp
        XTestRunnerDaemon.cpp
        XTestPractice.cpp)
add_executable(cpp_practical_lab ${SOURCE_FILES})