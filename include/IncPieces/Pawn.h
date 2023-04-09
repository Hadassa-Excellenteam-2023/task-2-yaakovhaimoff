#include "IncPieces/Piece.h"

class Pawn : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;
    bool m_hasMoved = false;

public:
    Pawn(const bool &white) : Piece(white) {
//        cout << "Pawn created";
    };

    bool canMove(const Position&, const Position&, const bool) override;
};