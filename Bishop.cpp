#include "Bishop.h"
#include "Piece.h"

piece_value_t Bishop::value() const {
    return 3;
}

bool Bishop::can_move_to(const Square& location) const {
    // TODO: implement this function
    return false;
}

std::string Bishop::str() const {
    return "Bishop";
}