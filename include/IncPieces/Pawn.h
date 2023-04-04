#include "IncPieces/Piece.h"

class Pawn : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;

public:
    Pawn(const bool &white) : Piece(white) {
//        cout << "Pawn created";
    };

    bool canMove(const pair<int, int> &, const pair<int, int> &) override;
};