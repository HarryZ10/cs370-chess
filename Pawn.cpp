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
        if (location.rank() == currentRef.rank() + 1 &&
            location.file() == currentRef.file()) {
            result = true;
        }
    }

    return result;
}

std::string Pawn::str() const {
    return this->color() == Piece::Color::white ? "♟" : "♙";
}