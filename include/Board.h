#pragma once

#include "macros.h"
#include "Factory.h"
#include "IncPieces/Piece.h"
#include "IncPieces/King.h"

#include <vector>

class Board {

    // Private helper functions
    /**
     * @brief Sets up the board with pieces based on the input board string
     * @param board The input board string
     */
    void setBoard(const std::string& board);

    /**
     * @brief Checks if the next step from src to dst is clear of obstacles
     * @param src The source position
     * @param dst The destination position
     * @return True if the next step is clear, false otherwise
     */
    bool checkIfNextStepClear(const Position& src, const Position& dst);

    /**
     * @brief Checks if the king of the specified color is in check
     * @param color The color of the king to check
     * @return True if the king is in check, false otherwise
     */
    bool checkIfKingInCheck(const bool color);

    /**
     * @brief Checks if a piece of the specified color is in the destination position
     * @param pos The destination position to check
     * @param color The color of the piece to check
     * @return True if a piece of the specified color is in the destination position, false otherwise
     */
    bool checkWhosInDst(const Position& pos, const bool color) const { return m_piece[pos.x][pos.y]->isWhite() == color; }

    /**
     * @brief Sets the position of the king of the specified color
     * @param pos The position of the king
     * @param color The color of the king
     */
    void setKingPos(const Position& pos, const bool color) { color ? m_whiteKingPos = pos : m_BlackKingPos = pos; }

    /**
     * @brief Gets the positions of all opponent pieces
     * @param color The color of the opponent pieces to get
     * @return A vector of positions of opponent pieces
     */
    std::vector<Position> getOpponetPos(const bool color);

    // Member variables
    bool m_whiteMove = true;
    Position m_whiteKingPos = { 8, 5 };
    Position m_BlackKingPos{ 1, 5 };
    std::vector<std::vector<std::unique_ptr<Piece>>> m_piece; // 2D vector of unique pointers to Piece objects

public:
    /**
     * @brief Constructor for the Board class
     * @param board The input board string
     */
    Board(const std::string& board) { setBoard(board); }

    /**
     * @brief Processes a player move and returns a response code
     * @param input The player move input string
     * @return An integer response code
     */
    int getResponse(const std::string& input);
};