#include "IncPieces/King.h"

 bool King::m_registerIt1 =
        Factory<Piece>::registerIt('K',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<King>(false);
                                   });

bool King::m_registerIt2 =
        Factory<Piece>::registerIt('k',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<King>(true);
                                   });

bool King::canMove(const Position& src, const Position& dst, const bool moveClear) {
    // Check if the new position is adjacent to the current position
    return abs(src.x - dst.x) <= 1 && abs(src.y - dst.y) <= 1 && src != dst && moveClear;
}