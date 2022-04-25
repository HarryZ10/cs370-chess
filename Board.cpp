#include <vector>
#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

#include "Board.h"
#include "Piece.h"
#include "Square.h"

using std::vector;
using std::ostream;
using std::basic_ostream;
using std::abs;

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
    if (from.rank() == to.rank()) {
        //if to is greater than from, increment from
        if (to.file() > from.file()) {
            for (size_t file = from.file() + 1; file <= to.file(); file++) {
                if (this->_squares[from.rank()][file]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        } else {
            for (size_t file = from.file() - 1; file >= to.file(); file--) {
                if (this->_squares[from.rank()][file]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        }
    }

    return result;
};


bool Board::is_clear_file(const Square& from, const Square& to) const {

    bool result = false;
    int modifer = 0;

    // if black player, then modifer is +1
    // if white player, then modifer is -1
    modifer = (from.occupant()->color() == Piece::Color::black) ? 1 : -1;

    if (from.rank() == to.rank()) {
        if (from.occupant()->color() == Piece::Color::white) {
            for (size_t rank = from.rank() - 1; rank >= to.rank(); rank--) {
                if (this->_squares[rank][from.file()]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        } else {
            for (size_t rank = from.rank() + 1; rank <= to.rank(); rank++) {
                if (this->_squares[rank][from.file()]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        }
    }

    return result;
}


bool Board::is_clear_diag(const Square& from, const Square& to) const {
    bool result = false;
    // The corresponding diagonal is actually a valid diagonal
    // Each of the squares from the specified square to the other specified
    // square are unoccupied by a piece
    if (std::abs(int(from.rank()) - int(to.rank())) == std::abs(int(from.file()) - int(to.file()))) {
        
        // if to.file() is greater than from.file() and to.rank() is greater than from.rank()
        // then increment from.file() and from.rank()
        if (to.file() > from.file() && to.rank() > from.rank()) {
            for (size_t file = from.file() + 1, rank = from.rank() + 1; file <= to.file(); file++, rank++) {
                if (this->_squares[rank][file]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        } else if (to.file() < from.file() && to.rank() < from.rank()) {
            for (size_t file = from.file() - 1, rank = from.rank() - 1; file >= to.file(); file--, rank--) {
                if (this->_squares[rank][file]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        } else if (to.file() > from.file() && to.rank() < from.rank()) {
            for (size_t file = from.file() + 1, rank = from.rank() - 1; file <= to.file(); file++, rank--) {
                if (this->_squares[rank][file]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        } else if (to.file() < from.file() && to.rank() > from.rank()) {
            for (size_t file = from.file() - 1, rank = from.rank() + 1; file >= to.file(); file--, rank++) {
                if (this->_squares[rank][file]->is_occupied()) {
                    result = false;
                    break;
                } else {
                    result = true;
                }
            }
        }
    }

    return result;
}


std::ostream& operator<<(std::ostream& os, const Board& board) {

    os << "\x1b[33m  ┃ a   b   c   d   e   f   g   h ┃" << std::endl;
    os << "\x1b[33m ━╋━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━╋━" << std::endl;
    // print 8
    for (size_t rank = 0; rank < SIZE; rank++) {

        os << "\x1b[33m" << SIZE - rank << "\x1b[33m ┃ ";

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
