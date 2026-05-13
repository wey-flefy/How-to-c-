cmake_minimum_required(VERSION 3.10)
project(TEST_Speed)

set(CMAKE_CXX_STANDARD 11)


add_library(drehzahlueberwachung src/drehzahlueberwachung.cpp)

add_executable(TEST_Speed TEST_Speed.cpp)
target_link_libraries(TEST_Speed drehzahlueberwachung)