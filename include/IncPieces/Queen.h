#include "IncPieces/Piece.h"

class Queen : public Piece {

    static bool m_registerIt1;
    static bool m_registerIt2;

public:
    Queen(const bool &white) : Piece(white) {
//        cout << "Queen created" << endl;
    };

    bool canMove(const pair<int, int> &, const pair<int, int> &, const bool) override;
};