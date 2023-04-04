#ifndef SPOT_H
#define SPOT_H

#include "IncPieces/Piece.h"
#include "Factory.h"


class Spot {

private:

    unique_ptr<Piece> m_piece;
    int x;
    int y;

public:

    Spot(const int &, const int &, const char &);

    bool canPieceMove(const pair<int, int> &, const pair<int, int> &) const;

    bool isPieceWhite() const;

    bool isPieceEmpty() const;

    void setPiece(unique_ptr<Piece>);

    int getX() const;

    void setX(const int);

    int getY() const;

    void setY(const int);
};

#endif //SPOT_H