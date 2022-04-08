#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "Piece.h"

class Rook : public Piece {
    public:

        /**
         * @brief Construct a new specified type of the chess piece
         *
         * @param color the color of the specified type of chess piece
         * @param location the location of the specified type of chess piece
         */
        Rook(Piece::Color color, Square& location) : Piece(color, location) { }


        /**
         * @brief Returns the piece's value
         * @return the piece's value
         */
        piece_value_t value() const override;


        /**
         * @brief Checks if the piece can move to the specified location
         *
         * @param location the location of the square (reference)
         * @return true if it is, otherwise false
         */
        bool can_move_to(const Square& location) const override;


        /**
         * @brief Returns the string representation for the piece
         * @return the string representaiton of the object piece 
         */
        std::string str() const override;
};

#endif
