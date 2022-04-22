
#include <iostream>
#include "Piece.h"
#include "Square.h"

using std::cout;
using std::to_string;
using std::ostream;


Piece::Color Piece::color() const {
    return this->_color;
}


Square* Piece::location() const {
    return this->_location;
}


void Piece::set_location(Square* location) {

    // define variable for the old location
    Square* old_location = this->_location;

    location->set_occupant(this);
    this->_location = location;
    this->location()->set_occupant(location->occupant());

    // if the old location is not null, remove the piece from it
    if (old_location != nullptr) {
        old_location->set_occupant(nullptr);
    }
}


bool Piece::is_on_square() const {
    return this->_location != nullptr;
}


void Piece::capture() {
    
    // if the piece is on a square, remove it from the square
    if (this->is_on_square()) {
        this->location()->set_occupant(nullptr);
    }

    // set the piece's location to null
    this->_location = nullptr;
}


bool Piece::move_to(Square& location) {
    bool result = false;

    // if the piece is on a square
    if (this->is_on_square()) {
        // if the piece is not trying to move to the same square
        if (this->_location != &location) {
            // if the piece is trying to move to a square that is not occupied
            if (!location.is_occupied()) {

                // if can be moved to the square
                if (this->can_move_to(location)) {
                    // move the piece to the square
                    this->set_location(&location);
                    result = true;
                }
            }
        }
    }

    return result;
}


std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << piece.str();
    return os;
}