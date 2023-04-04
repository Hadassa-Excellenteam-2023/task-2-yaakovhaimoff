#pragma once

#include "macros.h"
#include "Factory.h"

class Piece {
    bool m_killed = false;
    bool m_white = false;

public:
    Piece(bool white);

    bool isWhite() const;

    void setWhite(bool white);

    bool isKilled() const;

    void setKilled(bool killed);

    virtual bool canMove(const pair<int, int>&, const pair<int, int>&) = 0;
};