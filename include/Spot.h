#ifndef SPOT_H
#define SPOT_H

#include "IncPieces/Piece.h"
#include "Factory.h"


class Spot {

private:

    unique_ptr<Piece> m_piece;
    pair<int, int> m_coordinates;

public:

    Spot(const int &, const int &, const char &);

    bool canPieceMove(const pair<int, int> &, const pair<int, int> &) const;

    bool isPieceWhite() const;

    bool isPieceEmpty() const;

    void setPiece(unique_ptr<Piece>);

    pair<int, int> getCoordinates() const { return m_coordinates; }

    void setCoordinates(const pair<int, int>& newCoordinates) { m_coordinates = newCoordinates;  }
};

#endif //SPOT_H