#include "IncPieces/Rook.h"

bool Rook::m_registerIt1 =
        Factory<Piece>::registerIt('R',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Rook>(false);
                                   });

bool Rook::m_registerIt2 =
        Factory<Piece>::registerIt('r',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Rook>(true);
                                   });

bool Rook::canMove(const pair<int, int> &src, const pair<int, int> &dst, const bool moveClear) {
    // Check if the new position is on the same row or column as the current position
    return (src.first == dst.first || src.second == dst.second) && (src != dst) && moveClear;
}