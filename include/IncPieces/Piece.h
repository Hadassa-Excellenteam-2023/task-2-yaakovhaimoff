#pragma once

#include "macros.h"
#include "Factory.h"

class Piece {
    bool m_killed = false;
    bool m_white = false;
    bool m_isEmpty = false;

public:
    Piece(bool white) : m_white(white) {};

    bool isWhite() const { return m_white; }

    void setWhite(const bool white) { m_white = white; };

    bool isEmpty() const { return m_isEmpty; }

    void setEmpty(const bool empty) { m_isEmpty = empty; }

    bool isKilled() const { return m_killed; };

    void setKilled(bool killed) { m_killed = killed; };

    virtual bool canMove(const pair<int, int> &, const pair<int, int> &) = 0;
};