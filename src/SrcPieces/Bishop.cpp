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

bool Bishop::canMove(const Position& src, const Position& dst, const bool moveClear) {
    // Check if the new position is on the same diagonal as the current position
    return abs(src.x - dst.x) == abs(src.y - dst.y) && src != dst && moveClear;
}