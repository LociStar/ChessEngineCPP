cmake_minimum_required(VERSION 3.17)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessEngine main.cpp chesslib/Piece.cpp chesslib/Piece.h chesslib/PieceTypeClass.cpp chesslib/PieceTypeClass.h)