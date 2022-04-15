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
    bool result = true;

    // if entire rank is empty
    for (size_t file = 0; file < SIZE; file++) {
        if (this->_squares[from.rank()][file]->is_occupied()) {
            result = false;
            break;
        }
    }

    return result;
};


bool Board::is_clear_file(const Square& from, const Square& to) const {

    bool result = true;

    // if entire col/file is empty
    for (size_t rank = 0; rank < SIZE; rank++) {
        if (this->_squares[rank][from.file()]->is_occupied()) {
            result = false;
            break;
        }
    }

    return result;
}


bool Board::is_clear_diag(const Square& from, const Square& to) const {
    bool result = true;

    // if diagonal from and to is clear
    for (size_t rank = 0; rank < SIZE; rank++) {
        for (size_t file = 0; file < SIZE; file++) {
            if (this->_squares[rank][file]->is_occupied()) {
                result = false;
                break;
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
