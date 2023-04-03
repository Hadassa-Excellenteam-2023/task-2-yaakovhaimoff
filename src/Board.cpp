#include "Board.h"

void Board::setBoard(const std::string &name) {
    spots.resize(8, std::vector<unique_ptr<Spot>>(8)); // initialize the 2D vector

    // loop through the board string and create the corresponding piece objects
    for (int i = 0; i < 64; ++i) {
        int x = i % 8; // calculate x and y indices for the spot
        int y = i / 8;
        Piece *piece = nullptr;

        // create the piece object based on the character in the board string
        switch (board[i]) {
            case 'R':
                piece = Factory::create("Rook", x, y, nullptr).release();
                break;
            case 'N':
                piece = Factory::create("Knight", x, y, nullptr).release();
                break;
            case 'B':
                piece = Factory::create("Bishop", x, y, nullptr).release();
                break;
            case 'Q':
                piece = Factory::create("Queen", x, y, nullptr).release();
                break;
            case 'K':
                piece = Factory::create("King", x, y, nullptr).release();
                break;
            case 'P':
                piece = Factory::create("Pawn", x, y, nullptr).release();
                break;
        }

        // create the spot object and set the piece
        spots[x][y] = std::make_unique<Spot>(x, y, piece);
    }
}
