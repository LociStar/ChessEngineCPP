cmake_minimum_required(VERSION 3.17)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)

#add_library(test_libary STATIC src/chess_engine.cpp src/position.h src/position.cpp src/tables.h src/tables.cpp
#        src/types.h src/types.cpp)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(ChessEngine main.cpp engine.h engine.cpp
        src/chess_engine.cpp src/position.h src/position.cpp src/tables.h src/tables.cpp
        src/types.h src/types.cpp engine.cpp engine.h src/LinkedListDoubly.cpp positionTables.cpp positionTables.h UCI.cpp UCI.h src/transpositionTable.h src/pvTable.h)