#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Board.h"
#include "Piece.h"
#include "King.h"

class Player {
  public:
    /**
     * @brief Construct a new Player object
     * @param color the color of the player
     * @param board the board for the game
     */
    Player(Piece::Color color, const Board& board);

    
    /**
     * @brief Return the color of the player
     *
     * @return the color of the player
     */
    Piece::Color color() const;


    /**
     * @brief Make the move from the starting square to the ending square
     *
     * @param from the starting square
     * @param to the ending square
     * @return true if the move was made, false otherwise
     */
    bool make_move(const std::string& from, const std::string& to);


    /**
     * @brief Return value of the piece value
     */
    piece_value_t piece_value() const;


    /**
     * @brief Destroy the Player object
     */
    ~Player();

  private:
    const Piece::Color _color;
    const Board& _board;
    std::vector<Piece*> _pieces;
    King* _king;
};

#endif
