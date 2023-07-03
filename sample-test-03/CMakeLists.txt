cmake_minimum_required(VERSION 3.5)

project(sample-test3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sample-test3 main.cpp header.h source-test3.cpp)

install(TARGETS sample-test3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
