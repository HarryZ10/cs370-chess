#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "Piece.h"

class Bishop : public Piece {

  public:

    /**
     * @brief Construct a new Bishop object
     *
     * @param color the color of the piece
     * @param location the location of the piece
     */
    Bishop(Piece::Color color, Square& location) : Piece(color, location) { }


    /**
     * @brief the value of the piece which is unsigned integer
     *
     * @return piece_value_t the value of the piece
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
     * @brief Returns a string representation of Bishop and its values
     * @return std::string the string representation
     */
    std::string str() const override;
};

#endif