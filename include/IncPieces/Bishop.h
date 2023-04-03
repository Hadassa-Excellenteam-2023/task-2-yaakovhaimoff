#include "IncPieces/Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool white);

    bool canMove(const pair<int, int>&, const pair<int, int>&) override;
};