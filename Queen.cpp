#include <cmath>
#include "Queen.h"
#include "Square.h"

using std::abs;

piece_value_t Queen::value() const {
    return 9;
}

bool Queen::can_move_to(const Square& location) const {

    bool result = false;

    if (this->is_on_square()) {

        Square& currentRef = *this->location();

        if (std::abs(int(currentRef.rank()) - int(location.rank())) == std::abs(int(currentRef.file()) - int(location.file()))
            || std::abs(int(currentRef.rank()) - int(location.rank())) == 0
            || std::abs(int(currentRef.file()) - int(location.file())) == 0) {
            result = true;
        }
    }

    return result;
}

std::string Queen::str() const {
    return this->color() == Piece::Color::black ? "♛" : "♕";
}