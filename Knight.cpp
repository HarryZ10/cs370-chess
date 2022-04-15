#include <cmath>
#include "Knight.h"
#include "Square.h"

using std::abs;

piece_value_t Knight::value() const {
    return 3;
}

bool Knight::can_move_to(const Square& location) const {

    bool result = false;

    if (this->is_on_square()) {

        Square& currentRef = *this->location();
        
        // if the location is out 3 squares and turns into a L shape
        if (std::abs(int(location.rank()) - int(currentRef.rank())) == 2 &&
            std::abs(int(location.file()) - int(currentRef.file())) == 1) {
            result = true;
        }
        else if (std::abs(int(location.rank()) - int(currentRef.rank())) == 1 &&
                 std::abs(int(location.file()) - int(currentRef.file())) == 2) {
            result = true;
        }
        
    }

    return result;
}

std::string Knight::str() const {
    return this->color() == Piece::Color::white ? "♞" : "♘";
}