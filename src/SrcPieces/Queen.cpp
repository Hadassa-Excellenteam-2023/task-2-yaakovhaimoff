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

bool Queen::canMove(const Position& src, const Position& dst, const bool) {
    // Check if the new position is on the same row, column or diagonal as the current position
    return (src.x == dst.x || src.y == dst.y ||
        abs(src.x - dst.x) == abs(src.y - dst.y)) && src != dst;
}