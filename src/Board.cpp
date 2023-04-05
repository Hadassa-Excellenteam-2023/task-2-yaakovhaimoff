#include "Board.h"

void Board::setBoard(const std::string &board) {
    m_spots.resize(8); // resize the 2D vector
    for (auto &row: m_spots) row.resize(8); // resize each row

    // loop through the board string and create the corresponding piece objects
    for (int i = 0; i < board.size(); ++i) {
        int x = i % 8; // calculate x and y indices for the spot
        int y = i / 8;
        m_spots[y][x] = make_unique<Spot>(x, y, board[i]);
    }
}

int Board::getResponse(const std::string &input) {
    // parse the input string
    pair src = {input[0] - 'a', input[1] - '1'};
    pair dst = {input[2] - 'a', input[3] - '1'};

    // board checks

    // check out of bounds
    if (isOutOfBounds(src.first, src.second) || isOutOfBounds(dst.first, dst.second)) return 21;
    // check if the src is empty
    if (m_spots[src.first][src.second]->isPieceEmpty()) return 11;
        // check if the src is occupied by the opponent
    else if (m_spots[src.first][src.second]->isPieceWhite() != m_whiteMove) return 12;
        // check if the dst is occupied by the same color of the current player
    else if (m_spots[src.first][src.second]->isPieceWhite() == m_spots[dst.first][dst.second]->isPieceWhite())
        return 13;
    // check if player caused himself a mate

    // check if the next step is clear
//    checkIfNextStepClear(src, dst);

    // check if the player move is legal
    if (!m_spots[src.first][src.second]->canPieceMove(src, dst) || !checkIfNextStepClear(src, dst)) return 21;

    m_whiteMove = !m_whiteMove; // change the player
    return 42;
}

bool Board::isOutOfBounds(const int x, const int y) {
    return x < 0 || y < 0 || x >= BoardSize || y >= BoardSize;
}


bool Board::checkIfNextStepClear(const pair<int, int>& src, const pair<int, int>& dst) {
    int srcRow = src.first;
    int srcCol = src.second;
    int dstRow = dst.first;
    int dstCol = dst.second;

    if (srcRow == dstRow) { // Moving horizontally
        int colStep = (srcCol < dstCol) ? 1 : -1;
        for (int col = srcCol + colStep; col != dstCol; col += colStep) {
            if (!m_spots[srcRow][col]->isPieceEmpty()) {
                return false;
            }
        }
    }
    else if (srcCol == dstCol) { // Moving vertically
        int rowStep = (srcRow < dstRow) ? 1 : -1;
        for (int row = srcRow + rowStep; row != dstRow; row += rowStep) {
            if (!m_spots[row][srcCol]->isPieceEmpty()) {
                return false;
            }
        }
    }
    else {
        int rowStep = (dstRow > srcRow) ? 1 : -1;
        int colStep = (dstCol > srcCol) ? 1 : -1;

        if (srcRow == dstRow) { // Moving horizontally
            colStep = 0;
        }
        else if (srcCol == dstCol) { // Moving vertically
            rowStep = 0;
        }
        else if (abs(srcRow - dstRow) != abs(srcCol - dstCol)) {
            // Not a valid rook, bishop or queen move, you might want to handle this case as well.
            return false;
        }

        int row, col;
        for (row = srcRow + rowStep, col = srcCol + colStep; row != dstRow || col != dstCol; row += rowStep, col += colStep) {
            if (!m_spots[row][col]->isPieceEmpty()) {
                return false;
            }
        }
    }


    return true;
}
