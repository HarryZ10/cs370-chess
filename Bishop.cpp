#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

#include "Piece.h"
#include "Bishop.h"
#include "Square.h"

using std::abs;

piece_value_t Bishop::value() const {
    return 3;
}

bool Bishop::can_move_to(const Square& location) const {

    bool result = false;

    if (this->is_on_square()) {
        
        Square* current = this->location();
        Square& currentRef = *current;
        
        if (std::abs(int(currentRef.rank()) - int(location.rank())) == std::abs(int(currentRef.file()) - int(location.file()))) {
            result = true;
        }
    }

    return result;
}


std::string Bishop::str() const {
    return this->color() == Piece::Color::black ? "♝" : "♗";
}
