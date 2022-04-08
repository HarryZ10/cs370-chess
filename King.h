#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

class King : public Piece {
    public:

        /**
         * @brief Construct a new specified type of the chess piece
         *
         * @param color the color of the specified type of chess piece
         * @param location the location of the specified type of chess piece
         */
        explicit King(Piece::Color color, Square& location) : Piece(color, location) { }


        /**
         * @brief Return the value of the piece
         * @return the value of the piece
         */
        piece_value_t value() const override;


        /**
         * @brief Checks if the object can move to location of the Square ref
         *
         * @param location the location specified
         * @return true if it can, otherwise false
         */
        bool can_move_to(const Square& location) const override;


        /**
         * @brief Returns the string representation for the piece
         * @return the string representaiton of the object piece 
         */
        std::string str() const override;
};

#endif
