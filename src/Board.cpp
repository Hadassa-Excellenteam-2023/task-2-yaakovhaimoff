#include "Board.h"

void Board::setBoard(const std::string &board) {
    m_spots.resize(8); // resize the 2D vector
    for (auto &row : m_spots) row.resize(8); // resize each row

    cout << "board: " << board << endl;
    // loop through the board string and create the corresponding piece objects
    for (int i = 0; i < board.size(); ++i) {
        int x = i % 8; // calculate x and y indices for the spot
        int y = i / 8;
        m_spots[y][x] = make_unique<Spot>(x, y, board[i]);
    }
}

int Board::getResponse(const std::string &input) {
    // parse the input string
    int x1 = input[0] - 'a';
    int y1 = input[1] - '1';
    int x2 = input[2] - 'a';
    int y2 = input[3] - '1';
    m_spots[x1][y1]->canPieceMove({x1, y1}, {x2, y2});
//    for (auto &row : m_spots) {
//        for (auto &spot : row) {
//            spot->canPieceMove(pair(0, 0), pair(0, 0));
//        }
//    }
}
