#include "IncPieces/Queen.h"

bool Queen::m_registerIt1 =
        Factory<Piece>::registerIt('Q',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Queen>(false);
                                   });

bool Queen::m_registerIt2 =
        Factory<Piece>::registerIt('q',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Queen>(true);
                                   });

bool Queen::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move Queen" << endl;
    return true;
}