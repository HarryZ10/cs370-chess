#include <cmath>
#include "Pawn.h"
#include "Square.h"

using std::abs;

piece_value_t Pawn::value() const {
    return 1;
}

bool Pawn::can_move_to(const Square& location) const {

    bool result = false;

    if (this->is_on_square()) {

        Square& currentRef = *this->location();

        // rank must go up and file stay the same
        // if piece is white, rank must go up
        if (this->_moved) {
            if (this->color() == Piece::Color::white) {
                if (location.rank() == currentRef.rank() + 1 &&
                    location.file() == currentRef.file()) {
                    result = true;
                }
            }
            // if piece is black, rank must go down
            else {
                if (location.rank() == currentRef.rank() - 1 &&
                    location.file() == currentRef.file()) {
                    result = true;
                }
            }
        } else {
            if (this->color() == Piece::Color::white) {
                if (location.rank() == currentRef.rank() + 1 &&
                    location.file() == currentRef.file()) {
                    result = true;
                }
                else if (location.rank() == currentRef.rank() + 2 &&
                         location.file() == currentRef.file()) {
                    result = true;
                }
            }
            // if piece is black, rank must go down
            else {
                if (location.rank() == currentRef.rank() - 1 &&
                    location.file() == currentRef.file()) {
                    result = true;
                }
                else if (location.rank() == currentRef.rank() - 2 &&
                         location.file() == currentRef.file()) {
                    result = true;
                }
            }
        }
    }

    return result;
}


bool Pawn::move_to(Square& location) {

    bool result = false;

    // if the piece is on a square
    if (this->is_on_square()) {
        // if the piece is not trying to move to the same square
        if (this->location() != &location) {
            // if the piece is trying to move to a square that is not occupied
            if (!location.is_occupied()) {

                // if can be moved to the square
                if (this->can_move_to(location)) {

                    // move the piece to the square
                    this->set_location(&location);

                    // set the moved flag to true
                    this->_moved = true;

                    result = true;
                }
            }
        }
    }

    return result;
}

std::string Pawn::str() const {
    return this->color() == Piece::Color::white ? "♟" : "♙";
}