#include <cmath>
#include "King.h"
#include "Square.h"

using std::abs;

piece_value_t King::value() const {
    return 200;
}

bool King::can_move_to(const Square& location) const {

    bool result = false;

    // if the location is only one square away in either rank or file
    if (this->is_on_square()) {

        Square& currentRef = *this->location();
        
        // if the location is one square away in either rank or file
        if (std::abs(int(location.rank()) - int(currentRef.rank())) <= 1 &&
            std::abs(int(location.file()) - int(currentRef.file())) <= 1) {
            result = true;
        }
    }

    return result;
}

std::string King::str() const {
    return this->color() == Piece::Color::black ? "♚" : "♔";
}