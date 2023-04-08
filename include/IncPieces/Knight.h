#include "IncPieces/Piece.h"

class Knight : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;

public:
    Knight(const bool &white) : Piece(white) {
//        cout << "Knight created";
    };

    bool canMove(const pair<int, int> &, const pair<int, int> &, const bool) override;
};