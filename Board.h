#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Square.h"

static const size_t SIZE = 8;

class Board {

  public:
    /**
     * @brief Construct a new Board object
     */
    Board();

    
    /**
     * @brief Return square ref at the rank and file
     *
     * @param rank the row of the board
     * @param file the col of the board
     * @return the reference of the Square at rank and file
     */
    Square& square_at(size_t rank, size_t file) const;


    /**
     * @brief Translate pair to the rank/file indexing of the board
     *
     * @param pair the coordinates using Chess style notation (i.e "a1")
     * @return the square reference at the rank and file
     */
    Square& square_at(std::string pair) const;


    /**
     * @brief Return true if the rank is valid
     *
     * @param from the starting square
     * @param to the ending square
     * @return true if the rank is valid
     */
    bool is_valid_rank(const Square& from, const Square& to) const;


    /**
     * @brief Return true if the file is valid
     *
     * @param from the starting square
     * @param to the ending square
     * @return true if the file is valid
     */
    bool is_valid_file(const Square& from, const Square& to) const;


    /**
     * @brief Return true if the rank and file is valid
     *
     * @param from the starting square
     * @param to the ending square
     * @return true if the rank and file is valid
     */
    bool is_valid_diag(const Square& from, const Square& to) const;


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