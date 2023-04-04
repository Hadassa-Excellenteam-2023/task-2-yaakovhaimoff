#include "IncPieces/Empty.h"

bool Empty::m_registerIt =
        Factory<Piece>::registerIt('#',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Empty>(false);
                                   });

bool Empty::canMove(const pair<int, int> &, const pair<int, int> &)
{
    cout << "move Empty" << endl;
    return true;
}