cmake_minimum_required(VERSION 3.5)

project(sample-test-2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sample-test-2 main.cpp test-header.h source-file.cpp)

install(TARGETS sample-test-2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
