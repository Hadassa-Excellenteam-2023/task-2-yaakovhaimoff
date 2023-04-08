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

bool Queen::canMove(const pair<int, int>& src, const pair<int, int>& dst, const bool moveClear) {
    // Check if the new position is on the same row, column or diagonal as the current position
    return (src.first == dst.first || src.second == dst.second ||
        abs(src.first - dst.first) == abs(src.second - dst.second)) && src != dst && moveClear;
}