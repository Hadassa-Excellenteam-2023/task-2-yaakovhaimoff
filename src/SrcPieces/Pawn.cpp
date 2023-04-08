#include "IncPieces/Pawn.h"

bool Pawn::m_registerIt1 =
Factory<Piece>::registerIt('P',
	[]() -> std::unique_ptr<Piece> {
		return std::make_unique<Pawn>(false);
	});

bool Pawn::m_registerIt2 =
Factory<Piece>::registerIt('p',
	[]() -> std::unique_ptr<Piece> {
		return std::make_unique<Pawn>(true);
	});

bool Pawn::canMove(const pair<int, int>& src, const pair<int, int>& dst, const bool moveClear) {
	int dir = isWhite() ? -1 : 1;
	int x_diff = abs(src.second - dst.second);
	int y_diff = dst.first - src.first;
	// Check if the new position is a valid move for a pawn
	if (x_diff == 0 && moveClear) {
		if (m_hasMoved) {
			return y_diff * dir == 1;
		}
		else {
			m_hasMoved = true;
			return (y_diff * dir == 1 || y_diff * dir == 2);
		}
	}
	else if (x_diff == 1 && y_diff * dir == 1 && !moveClear) {
		return true;
	}
	return false;
}