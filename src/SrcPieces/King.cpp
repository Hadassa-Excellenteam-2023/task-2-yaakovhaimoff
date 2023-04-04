#include "IncPieces/King.h"

 bool King::m_registerIt1 =
        Factory<Piece>::registerIt('K',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<King>(false);
                                   });

bool King::m_registerIt2 =
        Factory<Piece>::registerIt('k',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<King>(true);
                                   });

bool King::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move King" << endl;
    return true;
}