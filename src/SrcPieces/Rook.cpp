#include "IncPieces/Rook.h"

bool Rook::m_registerIt1 =
        Factory<Piece>::registerIt('R',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Rook>(false);
                                   });

bool Rook::m_registerIt2 =
        Factory<Piece>::registerIt('r',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Rook>(true);
                                   });

bool Rook::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move Rook" << endl;
    return true;
}