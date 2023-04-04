#include "IncPieces/Bishop.h"

bool Bishop::m_registerIt1 =
        Factory<Piece>::registerIt('B',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Bishop>(false);
                                   });

bool Bishop::m_registerIt2 =
        Factory<Piece>::registerIt('b',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Bishop>(true);
                                   });

bool Bishop::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move Bishop" << endl;
    return true;
}