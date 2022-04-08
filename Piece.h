#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Square;

typedef unsigned int piece_value_t;

class Piece {

  public:

    /**
     * @brief Color properties for the piece (black or white)
     */
    enum struct Color {
        black, white
    };


    /**
     * @brief Construct a new specified type of the chess piece
     *
     * @param color the color of the specified type of chess piece
     * @param location the location of the specified type of chess piece
     */
    Piece(const Piece::Color color, Square& location) : _color(color) {
        this->set_location(&location);
    }


    /**
     * @brief Returns the piece's value
     * @return the piece's value
     */
    virtual piece_value_t value() const = 0;


    /**
     * @brief Returns the color of the piece
     * @return the color of the piece 
     */
    Piece::Color color() const;


    /**
     * @brief Returns the locations of the piece
     * @return the location of the piece
     */
    Square* location() const;


    /**
     * @brief Set the location object
     * @param location 
     */
    void set_location(Square* location);


    /**
     * @brief Checks if the piece is on a square
     * @return true if it is, otherwise false
     */
    bool is_on_square() const;


    /**
     * @brief Checks if the piece can move to the specified location
     *
     * @param location the location of the square (reference)
     * @return true if it is, otherwise false
     */
    virtual bool can_move_to(const Square& location) const = 0;


    /**
     * @brief Move the piece to location
     *
     * @param location the location of the square reference
     * @return true if the location is valid, false otherwise
     */
    bool move_to(Square& location);


    /**
     * @brief Returns the string representation for the piece
     * @return the string representaiton of the object piece 
     */
    virtual std::string str() const = 0;

  private:

    const Piece::Color _color;
    Square* _location = nullptr;
};


/**
 * @brief Return the string representation of the piece
 *
 * @param os the output stream
 * @param piece the specified object piece
 * @return the string representation of the piece
 */
std::ostream& operator<<(std::ostream& os, const Piece& piece);

#endif
