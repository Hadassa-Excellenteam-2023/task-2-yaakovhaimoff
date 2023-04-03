#pragma once

#include <utility>

using std::pair;

class Piece {
    bool killed = false;
    bool white = false;

public:
    Piece(bool white);

    bool isWhite();

    void setWhite(bool white);

    bool isKilled();

    void setKilled(bool killed);

    virtual bool canMove(const pair<int, int>&, const pair<int, int>&) = 0;
};