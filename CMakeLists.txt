cmake_minimum_required(VERSION 3.6)
project(Visitor)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp visitor.h visitable.h client.h)
add_executable(Visitor ${SOURCE_FILES})
