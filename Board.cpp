#include <vector>
#include <iostream>
#include <ostream>

#include "Board.h"
#include "Piece.h"
#include "Square.h"

using std::vector;
using std::ostream;
using std::basic_ostream;

Board::Board() {
    for (size_t rank = 0; rank < SIZE; rank++) {
        for (size_t file = 0; file < SIZE; file++) {
            this->_squares[rank][file] = new Square(rank, file);
        }
    }
};


Board::~Board() {
    for (size_t rank = 0; rank < SIZE; rank++) {
        for (size_t file = 0; file < SIZE; file++) {
            delete this->_squares[rank][file];
        }
    }
};


Square& Board::square_at(size_t rank, size_t file) const {
    return *this->_squares[rank][file];
};


bool Board::is_clear_rank(const Square& from, const Square& to) const {
    bool result = false;

    // The corresponding rank is actually a valid rank
    // Each of the squares from the specified square to the other specified
    // square are unoccupied by a piece
    
    // Rank is valid if it is between 0 and 7
    if (from.rank() >= 0 && from.rank() <= 7 && to.rank() >= 0 && to.rank() <= 7) {
        if (!from.is_occupied() && !to.is_occupied()) {
            
            // The rank is clear if the rank of the from square is the same as the to square
            if (from.rank() == to.rank()) {
                result = true;
            }
        }
    }

    return result;
};


bool Board::is_clear_file(const Square& from, const Square& to) const {

    bool result = true;

    // The corresponding file is actually a valid file
    // Each of the squares from the specified square to the other specified

    // File is valid if it is between 0 and 7
    if (from.file() >= 0 && from.file() <= 7 && to.file() >= 0 && to.file() <= 7) {
        if (!from.is_occupied() && !to.is_occupied()) {
            
            // Check if the rank is the same
            if (from.rank() == to.rank()) {
                result = false;
            }
            else {
                result = true;
            }
        }
    }

    return result;
}


bool Board::is_clear_diag(const Square& from, const Square& to) const {
    bool result = true;

    // The corresponding diagonal is actually a valid diagonal
    // Each of the squares from the specified square to the other specified

    // Diagonal is valid if it is between 0 and 7
    // check if valid diagonal (must have slope)
    if (from.rank() >= 0 && from.rank() <= 7 && from.file() >= 0 && from.file() <= 7 &&
        to.rank() >= 0 && to.rank() <= 7 && to.file() >= 0 && to.file() <= 7) {
        if (!from.is_occupied() && !to.is_occupied()) {
            // check if valid diagonal (must have slope)
            if (abs(int(from.rank()) - int(to.rank())) == abs(int(from.file()) - int(to.file()))) {
                result = true;
            }
        }
    }

    return result;
}


std::ostream& operator<<(std::ostream& os, const Board& board) {

    // print a b c d e f g h
    os << "\x1b[33m  ┃ a   b   c   d   e   f   g   h ┃" << std::endl;
    os << "\x1b[33m ━╋━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━╋━" << std::endl;
    // print 8
    for (size_t rank = 8; rank > 0; rank--) {
        os << "\x1b[33m" << rank << "\x1b[33m ┃ ";
        for (size_t file = 0; file < 8; file++) {
            os << "\x1b[0m" << board.square_at(rank - 1, file);
            os << "\x1b[33m ┃ ";
        }
        os << rank << std::endl;
        os << "\x1b[33m ━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━" << std::endl;
    }

    os << "\x1b[33m  ┃ a   b   c   d   e   f   g   h ┃" << std::endl;

    return os;
}
