#include <vector>
#include <iostream>
#include <ostream>
#include <unordered_map>

#include "Board.h"
#include "Piece.h"
#include "Square.h"

using std::vector;
using std::ostream;
using std::basic_ostream;
using std::unordered_map;

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


Square& Board::square_at(std::string pair) const {
    // a7 -> rank = 1, file = 0
    static std::unordered_map<char, int> rank_map = {
        {'8', 0}, {'7', 1}, {'6', 2}, {'5', 3},
        {'4', 4}, {'3', 5}, {'2', 6}, {'1', 7}
    };

    static std::unordered_map<char, int> file_map = {
        {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4},
        {'f', 5}, {'g', 6}, {'h', 7}
    };

    size_t file = file_map[pair.at(0)];
    size_t rank = rank_map[pair.at(1)];

    std::cout << pair.at(0) << " " << pair.at(1) << std::endl;

    return *this->_squares[rank][file];
}


bool Board::is_clear_rank(const Square& from, const Square& to) const {
    bool result = false;

    // The corresponding rank is actually a valid rank
    // Each of the squares from the specified square to the other specified
    // square are unoccupied by a piece

    for (size_t file = from.file() + 1; file <= to.file(); file++) {
        if (this->_squares[from.rank()][file]->is_occupied()) {
            result = false;
            break;
        } else {
            result = true;
        }
    }

    return result;
};


bool Board::is_clear_file(const Square& from, const Square& to) const {

    bool result = true;

    // The corresponding file is actually a valid file
    // Each of the squares from the specified square to the other specified
    for (size_t rank = from.rank() + 1; rank <= to.rank(); rank++) {
        if (this->_squares[rank][from.file()]->is_occupied()) {
            result = false;
            break;
        }
    }

    return result;
}


bool Board::is_clear_diag(const Square& from, const Square& to) const {
    bool result = true;

    // The corresponding diagonal is actually a valid diagonal
    // Each of the squares from the specified square to the other specified
    for (size_t rank = from.rank() + 1, file = from.file() + 1; rank <= to.rank()
        && file <= to.file(); rank++, file++) {
        if (this->_squares[rank][file]->is_occupied()) {
            result = false;
            break;
        }
    }

    return result;
}


std::ostream& operator<<(std::ostream& os, const Board& board) {

    os << "\x1b[33m  ┃ a   b   c   d   e   f   g   h ┃" << std::endl;
    os << "\x1b[33m ━╋━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━╋━" << std::endl;
    // print 8
    for (size_t rank = 0; rank < SIZE; rank++) {

        os << "\x1b[33m" << 8 - rank << "\x1b[33m ┃ ";

        for (size_t file = 0; file < SIZE; file++) {
            os << "\x1b[0m" << board.square_at(rank, file);
            os << "\x1b[33m ┃ ";
        }

        os << SIZE - rank << std::endl;
        os << "\x1b[33m ━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━" << std::endl;
    }

    os << "\x1b[33m  ┃ a   b   c   d   e   f   g   h ┃" << std::endl;

    return os;
}
