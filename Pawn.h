#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"

class Pawn : public Piece {
  public:

    /**
     * @brief Construct a new specified type of the chess piece
     *
     * @param color the color of the specified type of chess piece
     * @param location the location of the specified type of chess piece
     */
    Pawn(Piece::Color color, Square& location) : Piece(color, location) { }


    /**
     * @brief Return the value of the piece
     * @return the value of the piece
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