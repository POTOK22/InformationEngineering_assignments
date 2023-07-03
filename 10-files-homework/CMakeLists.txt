cmake_minimum_required(VERSION 3.5)

project(files-01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(files-01 main.cpp)

install(TARGETS files-01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
