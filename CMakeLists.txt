cmake_minimum_required(VERSION 3.27)
project(serialization_tools)

set(CMAKE_CXX_STANDARD 11)

add_executable(serialization_tools main.cpp
        string_serializer.h
        src/buffer.hpp
        src/byte_serializer.hpp)
