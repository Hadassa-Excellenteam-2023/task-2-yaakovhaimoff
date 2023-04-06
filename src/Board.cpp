#include "Board.h"

void Board::setBoard(const std::string &board) {
    m_piece.resize(8); // resize the 2D vector
    for (auto &row: m_piece) row.resize(8); // resize each row

    // loop through the board string and create the corresponding piece objects
    for (int i = 0; i < board.size(); ++i) {
        int x = i % 8; // calculate x and y indices for the spot
        int y = i / 8;
        m_piece[y][x] = Factory<Piece>::create(board[i]);
    }
}

int Board::getResponse(const std::string &input) {
    // parse the input string
    pair src = {input[0] - 'a', input[1] - '1'};
    pair dst = {input[2] - 'a', input[3] - '1'};

    // board checks

    // check if the src is empty
    if (!m_piece[src.first][src.second]) return 11;
    
    // check if the src is occupied by the opponent
    if (m_piece[src.first][src.second]->isWhite() != m_whiteMove) return 12;
    
    // check if the dst is occupied by the same color of the current player
    if (m_piece[dst.first][dst.second] && m_piece[src.first][src.second]->isWhite() == m_piece[dst.first][dst.second]->isWhite())
        return 13;
    
    // check if player caused himself a mate

    // check if the player move is legal
    if (!m_piece[src.first][src.second]->canMove(src, dst) || !checkIfNextStepClear(src, dst)) return 21;

    // if player move was legal
    m_piece[dst.first][dst.second] = move(m_piece[src.first][src.second]);
    //m_piece[src.first][src.second] = nullptr;
    m_whiteMove = !m_whiteMove; // change the player
    return 42;
}

bool Board::isOutOfBounds(const int x, const int y) {
    return x < 0 || y < 0 || x >= BoardSize || y >= BoardSize;
}


bool Board::checkIfNextStepClear(const pair<int, int>& src, const pair<int, int>& dst) {
    int srcRow = src.first, srcCol = src.second;
    int dstRow = dst.first, dstCol = dst.second;
    int rowStep = (dstRow == srcRow) ? 0 : (dstRow > srcRow ? 1 : -1);
    int colStep = (dstCol == srcCol) ? 0 : (dstCol > srcCol ? 1 : -1);

    if (srcRow != dstRow && srcCol != dstCol && abs(srcRow - dstRow) != abs(srcCol - dstCol)) {
        // Not a valid rook, bishop or queen move
        return false;
    }

    for (int row = srcRow + rowStep, col = srcCol + colStep; row != dstRow || col != dstCol; row += rowStep, col += colStep) {
        if (m_piece[row][col]) {
            return false;
        }
    }

    return true;
}