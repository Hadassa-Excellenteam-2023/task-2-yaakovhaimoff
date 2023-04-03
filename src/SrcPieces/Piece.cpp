#include "IncPieces/Piece.h"

Piece::Piece(bool white) {
    this->setWhite(white);
}

bool Piece::isWhite() {
    return this->white;
}

void Piece::setWhite(bool white) {
    this->white = white;
}

bool Piece::isKilled() {
    return this->killed;
}

void Piece::setKilled(bool killed) {
    this->killed = killed;
}
