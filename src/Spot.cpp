#include "Spot.h"
#include "IncPieces/Piece.h"

Spot::Spot(const int &x, const int &y, const char& name)
        : m_coordinates(x, y), m_piece(Factory<Piece>::create(name)) {
    //this->m_piece = Factory<Piece>::create(name);
}

bool Spot::canPieceMove(const pair<int, int>&src, const pair<int, int>&dst) const {
    return this->m_piece->canMove(src, dst);
}

bool Spot::isPieceWhite() const {
    return this->m_piece->isWhite();
}

bool Spot::isPieceEmpty() const {
    return this->m_piece == nullptr;
}

void Spot::setPiece(unique_ptr<Piece> p) {
    this->m_piece = std::move(p);
}