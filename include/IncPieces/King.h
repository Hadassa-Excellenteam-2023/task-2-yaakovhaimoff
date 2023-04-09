#include "IncPieces/Piece.h"

class King : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;

public:
    King(const bool &white) : Piece(white) {
//        cout << "King created";
    };

    bool canMove(const Position&, const Position&, const bool) override;
};