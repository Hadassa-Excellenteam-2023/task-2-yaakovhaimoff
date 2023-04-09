#pragma once

#include "macros.h"
#include "Factory.h"
#include "IncPieces/Piece.h"
#include "IncPieces/King.h"

using std::vector;

class Board {

	void setBoard(const std::string&);

	bool checkIfNextStepClear(const Position&, const Position&);

	bool checkIfKingInCheck(const bool);

	bool checkWhosInDst(const Position& pos, const bool color) const { return m_piece[pos.x][pos.y]->isWhite() == color; }

	void setKingPos(const Position& pos, const bool color) { color ? m_whiteKingPos = pos : m_BlackKingPos = pos; }

	vector<Position> getOpponetPos(const bool);

	bool m_whiteMove = true;

	Position m_whiteKingPos = { 8, 5 };
	Position m_BlackKingPos{ 1, 5 };

	vector<vector<unique_ptr<Piece>>> m_piece; // 2D vector of unique pointers to Spot objects

public:

	Board(const std::string& board) { setBoard(board); }

	int getResponse(const std::string& input);
};