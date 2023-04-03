#include "IncPieces/Piece.h"

class Queen : public Piece {
public:
    Queen(bool white);

    bool canMove(const pair<int, int>&, const pair<int, int>&) override;
};