
#include <iostream>
#include "Piece.h"
#include "Square.h"

using std::cout;
using std::to_string;

piece_value_t Piece::value() const {
    return 0;
}


Piece::Color Piece::color() const {
    return this->_color;
}

Square* Piece::location() const {
    return this->_location;
}


void Piece::set_location(Square* location) {
    this->_location = location;
}


bool Piece::is_on_square() const {
    return this->_location != nullptr;
}


bool can_move_to(const Square& location) {
    return false;
}


bool Piece::move_to(Square& location) {

    bool result = false;

    if (this->can_move_to(location)) {
        this->_location = &location;
        result = true;
    }

    return result;
}


std::string Piece::str() const {
    return "Piece";
}