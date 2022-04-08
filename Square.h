#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Piece.h"

class Square {
    public:

        /**
         * @brief Construct a new square (for the Board)
         *
         * @param rank the row
         * @param file the column
         */
        Square(size_t rank, size_t file) : _rank(rank), _file(file) { }


        /**
         * @brief Get rank of the square
         * @return rank of the square
         */
        size_t rank() const;


        /**
         * @brief Get file of the square
         * @return file of the square
         */
        size_t file() const;


        /**
         * @brief Checks if the square is occupied
         * @return true if it is, false otherwise
         */
        bool is_occupied() const;


        /**
         * @brief Get the address of the occupant
         * @return the pointer to the occupant
         */
        Piece* occupant() const;

    private:

        /**
         * @brief Set the occupant object
         * @param occupant 
         */
        void set_occupant(Piece* occupant);

        const size_t _rank;
        const size_t _file;
        Piece* _occupant = nullptr;
        friend void Piece::set_location(Square* location);
};


/**
 * @brief Return the string representation of the object
 *
 * @param os the output stream
 * @param square the reference of the Square to display
 * @return output stream of the square (reference)
 */
std::ostream& operator<<(std::ostream& os, const Square& square);

#endif
