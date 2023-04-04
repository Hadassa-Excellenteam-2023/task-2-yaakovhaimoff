#include "IncPieces/Pawn.h"

bool Pawn::m_registerIt1 =
        Factory<Piece>::registerIt('P',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Pawn>(false);
                                   });

bool Pawn::m_registerIt2 =
        Factory<Piece>::registerIt('p',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Pawn>(true);
                                   });

bool Pawn::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move Pawn" << endl;
    return true;
}