#include "Spot.h"
#include "IncPieces/Piece.h"

Spot::Spot(const int &x, const int &y, const char& name)
        : x(x), y(y) {
    this->m_piece = Factory<Piece>::create(name);
}

bool Spot::canPieceMove(const pair<int, int>&src, const pair<int, int>&dst) const {
    cout << "x: " << x << " y: " << y  << " ";
    return this->m_piece->canMove(src, dst);
}

bool Spot::isPieceWhite() const {
    return this->m_piece->isWhite();
}

void Spot::setPiece(unique_ptr<Piece> p) {
    this->m_piece = std::move(p);
}

int Spot::getX() const {
    return this->x;
}

void Spot::setX(const int x) {
    this->x = x;
}

int Spot::getY() const {
    return this->y;
}

void Spot::setY(const int y) {
    this->y = y;
}
