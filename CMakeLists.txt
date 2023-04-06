cmake_minimum_required(VERSION 3.22)

project(ex2)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
    src/main.cpp
    src/Board.cpp
    src/Chess.cpp
    src/Factory.cpp
    src/SrcPieces/Piece.cpp
    src/SrcPieces/Bishop.cpp
    src/SrcPieces/King.cpp
    src/SrcPieces/Knight.cpp
    src/SrcPieces/Pawn.cpp
    src/SrcPieces/Queen.cpp
)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})


include_directories (include)
include_directories (src)
