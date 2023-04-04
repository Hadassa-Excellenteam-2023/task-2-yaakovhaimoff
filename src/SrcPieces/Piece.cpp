#include "IncPieces/Piece.h"

Piece::Piece(bool white) {
    this->m_white = white;
}

bool Piece::isWhite() const{
    return this->m_white;
}

void Piece::setWhite(bool white) {
    this->m_white = white;
}

bool Piece::isKilled() const{
    return this->m_killed;
}

void Piece::setKilled(bool killed) {
    this->m_killed = killed;
}
