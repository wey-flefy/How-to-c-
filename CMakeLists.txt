cmake_minimum_required(VERSION 3.10)
project(TEST_Speed)

set(CMAKE_CXX_STANDARD 11)

# Enable testing
include(CTest)
enable_testing()


# Add the tests
add_subdirectory(tests)

# add library for drehzahlueberwachung
add_library(drehzahlueberwachung src/drehzahlueberwachung.cpp)
add_library(highflow src/highflow.cpp)
# Include directory for drehzahlueberwachung for all targets that link to it
target_include_directories(drehzahlueberwachung PUBLIC inc)
target_include_directories(highflow PUBLIC inc)

# add TEST_Speed to tests
add_test(NAME TEST_Speed COMMAND TEST_Speed)
add_test(NAME TEST_highflow COMMAND TEST_highflow)


add_executable(main main.cpp)
target_link_libraries(main drehzahlueberwachung)

