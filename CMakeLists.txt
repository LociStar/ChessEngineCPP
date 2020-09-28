cmake_minimum_required(VERSION 3.17)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 14)

#add_library(test_libary STATIC src/chess_engine.cpp src/position.h src/position.cpp src/tables.h src/tables.cpp
#        src/types.h src/types.cpp)

add_executable(ChessEngine main.cpp src/chess_engine.cpp src/position.h src/position.cpp src/tables.h src/tables.cpp
        src/types.h src/types.cpp)