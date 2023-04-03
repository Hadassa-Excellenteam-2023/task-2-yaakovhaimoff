#include "Spot.h"
#include "IncPieces/Piece.h"

Spot::Spot(const int &x, const int &y, Piece *piece)
        : x(x), y(y), piece(piece) {}

Piece *Spot::getPiece() const {
    return this->piece;
}

void Spot::setPiece(Piece *p) {
    this->piece = p;
}

int Spot::getX() const {
    return this->x;
}

void Spot::setX(int x) {
    this->x = x;
}

int Spot::getY() const {
    return this->y;
}

void Spot::setY(int y) {
    this->y = y;
}
