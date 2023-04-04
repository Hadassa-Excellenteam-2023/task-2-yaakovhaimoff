#include "IncPieces/Piece.h"

class Bishop : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;

public:
    Bishop(const bool &white) : Piece(white) {
//        cout << "Bishop created";
    };

    bool canMove(const pair<int, int> &, const pair<int, int> &) override;
};