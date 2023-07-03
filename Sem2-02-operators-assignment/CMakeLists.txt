cmake_minimum_required(VERSION 3.5)

project(hw-operators-2-assignment LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw-operators-2-assignment main.cpp header.h operators.cpp)

install(TARGETS hw-operators-2-assignment
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
