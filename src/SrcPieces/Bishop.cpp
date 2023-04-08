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

bool Bishop::canMove(const pair<int, int>& src, const pair<int, int>& dst, const bool moveClear) {
    // Check if the new position is on the same diagonal as the current position
    return abs(src.first - dst.first) == abs(src.second - dst.second) && src != dst && moveClear;
}