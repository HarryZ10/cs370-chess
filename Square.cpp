#include "Square.h"
#include "Piece.h"

size_t Square::rank() const {
    return this->_rank;
}


size_t Square::file() const {
    return this->_file;
}


bool Square::is_occupied() const {
    return this->_occupant != nullptr;
}


Piece* Square::occupant() const {
    return this->_occupant;
}

void Square::set_occupant(Piece* occupant) {
    this->_occupant = occupant;
}
