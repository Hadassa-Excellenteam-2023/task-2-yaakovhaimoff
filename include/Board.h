#pragma once

#include "macros.h"
#include "Factory.h"
#include "Spot.h"

using std::vector;

class Board {

    void setBoard(const std::string &);

    bool whiteMove = true;

    vector<vector<unique_ptr<Spot>>> m_spots; // 2D vector of unique pointers to Spot objects

public:

    Board(const std::string &board) { setBoard(board); }

    int getResponse(const std::string &input);
};