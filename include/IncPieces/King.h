#include "IncPieces/Piece.h"

class King : public Piece {
public:
    King(bool white);

    bool canMove(const pair<int, int>&, const pair<int, int>&) override;
};