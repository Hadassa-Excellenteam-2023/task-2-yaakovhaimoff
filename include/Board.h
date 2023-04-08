#pragma once

#include "macros.h"
#include "Factory.h"
#include "IncPieces/Piece.h"

using std::vector;

class Board {

    void setBoard(const std::string &);

    bool checkIfNextStepClear(const pair<int, int> &, const pair<int, int> &);

    bool m_whiteMove = true;

    vector<vector<unique_ptr<Piece>>> m_piece; // 2D vector of unique pointers to Spot objects

public:

    Board(const std::string &board) { setBoard(board); }

    int getResponse(const std::string &input);
};