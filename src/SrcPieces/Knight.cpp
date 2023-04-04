#include "IncPieces/Knight.h"

bool Knight::m_registerIt1 =
        Factory<Piece>::registerIt('N',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Knight>(false);
                                   });

bool Knight::m_registerIt2 =
        Factory<Piece>::registerIt('n',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Knight>(true);
                                   });

bool Knight::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move Knight" << endl;
    return true;
}