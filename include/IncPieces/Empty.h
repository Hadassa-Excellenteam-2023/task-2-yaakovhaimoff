#include "IncPieces/Piece.h"

class Empty : public Piece {

    static bool m_registerIt;

public:
    Empty(const bool &white) : Piece(white) {
        setEmpty(true);
//        cout << "Empty created";
    };

    bool canMove(const pair<int, int> &, const pair<int, int> &) override;
};