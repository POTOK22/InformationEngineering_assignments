cmake_minimum_required(VERSION 3.5)

project(homework-operators LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(homework-operators main.cpp header.h operators.cpp)

install(TARGETS homework-operators
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
