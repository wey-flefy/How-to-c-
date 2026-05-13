cmake_minimum_required(VERSION 3.10)
project(TEST_Speed)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_subdirectory(tests)

add_library(drehzahlueberwachung src/drehzahlueberwachung.cpp)
target_include_directories(drehzahlueberwachung PUBLIC inc)

add_test(NAME TEST_Speed COMMAND TEST_Speed)


add_executable(main main.cpp)
target_link_libraries(main drehzahlueberwachung)

