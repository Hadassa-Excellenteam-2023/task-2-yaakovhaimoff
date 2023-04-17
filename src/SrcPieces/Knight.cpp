#include "IncPieces/Knight.h"

bool Knight::m_registerIt1 =
        Factory<Piece>::registerIt('N',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Knight>(true);
                                   });

bool Knight::m_registerIt2 =
        Factory<Piece>::registerIt('n',
                                   []() -> std::unique_ptr<Piece> {
                                       return std::make_unique<Knight>(false);
                                   });

bool Knight::canMove(const Position& src, const Position& dst, const bool) {
    // Check if the new position is a L-shape from the current position
    int x_diff = abs(src.x - dst.x);
    int y_diff = abs(src.y - dst.y);
    return ((x_diff == 1 && y_diff == 2) || (x_diff == 2 && y_diff == 1));
}