#include "Board.h"

void Board::setBoard(const std::string& board) {
	m_piece.resize(8); // resize the 2D vector
	for (auto& row : m_piece) row.resize(8); // resize each row

	// loop through the board string and create the corresponding piece objects
	for (int i = 0; i < board.size(); ++i) {
		int x = i % 8; // calculate x and y indices for the spot
		int y = i / 8;
		m_piece[y][x] = Factory<Piece>::create(board[i]);
	}
	setKingsPositions();
}

void Board::setKingsPositions() {
	for (int i = 0; i < BoardSize; i++)
		for (int j = 0; j < BoardSize; j++) 
			if (m_piece[i][j] && typeid(*m_piece[i][j]) == typeid(King)) {
				m_piece[i][j]->isWhite() ? setKingPos({ i + 1, j + 1 }, true) :
					setKingPos({ i + 1, j + 1 }, false);
			}
}

int Board::getResponse(const std::string& input) {
	// parse the input string
	Position src = { input[0] - 'a', input[1] - '1' };
	Position dst = { input[2] - 'a', input[3] - '1' };

	// board checks

	// check if the src is empty
	if (!m_piece[src.x][src.y]) return 11;

	// check if the src is occupied by the opponent
	if (m_piece[src.x][src.y]->isWhite() != m_whiteMove) return 12;

	// check if the dst is occupied by the same color of the current player
	if (m_piece[dst.x][dst.y] && m_piece[src.x][src.y]->isWhite() == m_piece[dst.x][dst.y]->isWhite())
		return 13;

	// check if the player move is legal
	bool opponent = m_piece[dst.x][dst.y] && m_piece[src.x][src.y]->isWhite() == !m_piece[dst.x][dst.y]->isWhite();
	if (!m_piece[src.x][src.y]->canMove(src, dst, opponent) || !checkIfNextStepClear(src, dst)) return 21;

	// if player move was legal
	m_piece[dst.x][dst.y] = move(m_piece[src.x][src.y]);

	// set king position
	if (typeid(*m_piece[dst.x][dst.y]) == typeid(King))
		setKingPos({ dst.x, dst.y }, m_piece[dst.x][dst.y]->isWhite());

	// check if player caused himself check
	if (checkIfKingInCheck(m_whiteMove)) {
		if (typeid(*m_piece[dst.x][dst.y]) == typeid(King)) {
			setKingPos({ src.x, src.y }, m_piece[dst.x][dst.y]->isWhite());
		}
		m_piece[src.x][src.y] = move(m_piece[dst.x][dst.y]);
		return 31;
	}

	// if move was legal
	bool opponet = !m_whiteMove;
	m_whiteMove = !m_whiteMove; // change the player
	// check if player caused opponet check
	if (checkIfKingInCheck(opponet)) return 41;
	return 42;
}


bool Board::checkIfNextStepClear(const Position& src, const Position& dst) {
	int srcRow = src.x, srcCol = src.y;
	int dstRow = dst.x, dstCol = dst.y;
	int rowStep = (dstRow == srcRow) ? 0 : (dstRow > srcRow ? 1 : -1);
	int colStep = (dstCol == srcCol) ? 0 : (dstCol > srcCol ? 1 : -1);

	// check for knight move
	if ((abs(dstRow - srcRow) == 2 && abs(dstCol - srcCol) == 1) ||
		(abs(dstRow - srcRow) == 1 && abs(dstCol - srcCol) == 2)) {
		return true;
	}

	// check for invalid moves
	if (srcRow != dstRow && srcCol != dstCol && abs(srcRow - dstRow) != abs(srcCol - dstCol)) {
		// Not a valid rook, bishop or queen move
		return false;
	}

	// check for obstacles in path
	for (int row = srcRow + rowStep, col = srcCol + colStep; row != dstRow || col != dstCol; row += rowStep, col += colStep) {
		if (m_piece[row][col]) {
			return false;
		}
	}
	return true;
}

bool Board::checkIfKingInCheck(const bool color) {
	vector<Position> opponetPos = getOpponetPos(color);
	Position kingPos = color ? m_WhiteKingPos : m_BlackKingPos;

	for (auto& pos : opponetPos) {
		if (m_piece[pos.x][pos.y]->canMove(pos, kingPos, checkIfNextStepClear(pos, kingPos)))
			return true;
	}
	return false;
}

vector<Position> Board::getOpponetPos(const bool color) {
	vector<Position> opponetPos;
	for (int i = 0; i < BoardSize; i++)
		for (int j = 0; j < BoardSize; j++)
			if (m_piece[i][j] && m_piece[i][j]->isWhite() != color)
				opponetPos.push_back({ i,j });
	return opponetPos;
}