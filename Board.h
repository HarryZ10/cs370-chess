#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Square.h"

class Board {

  public:

    static const size_t SIZE = 8;

    /**
     * @brief Construct a new Board object
     */
    Board();

    
    /**
     * @brief REturn square ref at the rank and file
     *
     * @param rank the row of the board
     * @param file the col of the board
     * @return the  reference of the Square at rank and file
     */
    Square& square_at(size_t rank, size_t file) const;

    
    /**
     * @brief Checks if the row/rank is clear
     *
     * @param from the location of the square where it's coming from
     * @param to the location of the square where it's going to
     * @return true if it is clear, otherwise it is false
     */
    bool is_clear_rank(const Square& from, const Square& to) const;


    /**
     * @brief Checks if the col/file is clear
     *
     * @param from the location of the square where it's coming from
     * @param to the location of the square where it's going to
     * @return true if it is clear, otherwise it is false
     */
    bool is_clear_file(const Square& from, const Square& to) const;


    /**
     * @brief Checks if the diagonal line is clear
     *
     * @param from the location of the square where it's coming from
     * @param to the location of the square where it's going to
     * @return true if it is clear, otherwise it is false
     */
    bool is_clear_diag(const Square& from, const Square& to) const;


    /**
     * @brief Destroy the Board object
     */
    ~Board();

  private:

    Square* _squares[SIZE][SIZE] = {};
};


/**
 * @brief Return the string representation of a board
 * 
 * @param os the output stream
 * @param board the matrix structure stored in the class
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Board& board);

#endif