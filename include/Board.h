#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Factory.h"
#include "Spot.h"

class Board {
private:
    Board(const std::string &board) { setBoard(board); }

    void setBoard(const std::string &);

    bool whiteMove = true;

    std::vector<std::vector<unique_ptr<Spot>>> spots; // 2D vector of unique pointers to Spot objects
};