#include <iostream>
#include <cmath>
#include "Pawn.h"
#include "Square.h"

using std::abs;

piece_value_t Pawn::value() const {
    return 1;
}

bool Pawn::can_move_to(const Square& location) const {

    // store the result
    bool result = false;

    // pawn must be on a square (a valid piece)
    if (this->is_on_square()) {

        // currentRef is the Square that the current pawn is on
        Square& currentRef = *this->location();

        if (location.file() == currentRef.file()) {

            if (this->color() == Piece::Color::white) {

                // if one rank up
                if (location.rank() == currentRef.rank() - 2 && !this->_moved) { 
                    result = true;
                }
                else if (location.rank() == currentRef.rank() - 1) {

                    result = true;
                }

            } else {
                // else if the piece is black

                if (location.rank() == currentRef.rank() + 2 && !this->_moved) { 
                    result = true;
                }
                else if (location.rank() == currentRef.rank() + 1) {
                    result = true;
                }
            }
        }
        else if (std::abs(int(location.rank()) - int(currentRef.rank())) == 1
              && std::abs(int(location.file()) - int(currentRef.file())) == 1) { 
            result = true;
        }
    }

    return result;
}


bool Pawn::move_to(Square& location) {

    bool result = false;

    // if the piece is on a square
    if (this->is_on_square()) {

        // if can be moved to the square
        if (this->can_move_to(location)) {

            // move the piece to the square
            this->set_location(&location);

            // set the moved flag to true
            if (!this->_moved) {
                this->_moved = true;
            }

            result = true;
        }
    }

    return result;
}

std::string Pawn::str() const {
    return this->color() == Piece::Color::white ? "♟" : "♙";
}
