cmake_minimum_required(VERSION 3.31)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe main.cpp
        src/Field.cpp
        src/Field.h
        src/Logic.cpp
        src/Logic.h)
