#pragma once

#include "macros.h"
#include "Factory.h"
#include "Spot.h"

using std::vector;

class Board {

    void setBoard(const std::string &);

    bool checkIfNextStepClear(const pair<int, int> &, const pair<int, int> &);

    bool isOutOfBounds(const int x, const int y);

    bool m_whiteMove = true;

    vector<vector<unique_ptr<Spot>>> m_spots; // 2D vector of unique pointers to Spot objects

public:

    Board(const std::string &board) { setBoard(board); }

    int getResponse(const std::string &input);
};