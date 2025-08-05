cmake_minimum_required(VERSION 3.31)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Gui)
target_link_libraries(TicTacToe PRIVATE Qt6::Gui)

add_executable(TicTacToe main.cpp
        src/Field.cpp
        src/Field.h
        src/Logic.cpp
        src/Logic.h
        src/FieldUI.cpp
        src/FieldUI.h
        src/LogicSlave.cpp
        src/LogicSlave.h)
