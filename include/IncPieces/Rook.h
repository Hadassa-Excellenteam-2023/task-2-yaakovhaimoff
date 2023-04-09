#include "IncPieces/Piece.h"

class Rook : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;

public:
    Rook(const bool &white) : Piece(white) {
//        cout << "Rook created" << endl;
    };

    bool canMove(const Position&, const Position&, const bool) override;
};