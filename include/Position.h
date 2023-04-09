#pragma once 

#include <iostream>

//Struct Position{
//	std::pair <int, int> m_position;
//	Position(const int x, const int y) : m_position(x,y) {}
//};
struct Position {
    int x;
    int y;

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }

};