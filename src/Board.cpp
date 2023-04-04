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
    if (m_spots[src.first][src.second]->canPieceMove(src, dst)) return 21;

    m_whiteMove = !m_whiteMove; // change the player
    return 42;

}

bool Board::isOutOfBounds(const int x, const int y) {
    return x < 0 || y < 0 || x >= BoardSize || y >= BoardSize;
}


bool Board::checkIfNextStepClear(const pair<int, int> &src, const pair<int, int> &dst) {

    return true;
}