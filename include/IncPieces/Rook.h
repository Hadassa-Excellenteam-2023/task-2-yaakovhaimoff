#include "IncPieces/Piece.h"

class Rook : public Piece {
public:
    Rook(bool white);

    bool canMove(const pair<int, int>&, const pair<int, int>&) override;
};