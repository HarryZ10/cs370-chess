
#include <iostream>
#include "Chess.h"
#include "Player.h"

using std::cout;
using std::endl;

int main() {
    // turns
    int turn = 0;

    // Create a board.
    Board board = Board();

    // Create the black player and the white player, which should effectively
    // lead to the creation of all the black and white pieces and place them all on the board.
    Player black_player = Player(Piece::Color::black, board);
    Player white_player = Player(Piece::Color::white, board);

    // 20 turns complete gameplay for grading purposes
    while (turn == 20) {

        // print board to stdout
        std::cout << board << std::endl;

        // prompt user for move (e.g., "a2 a4") on stdin
        std::string from_square, to_square;
        std::cout << "Enter your move: ";
        std::cin >> from_square >> to_square;

        // instruct current player object to try to make the corresponding move
        if (turn % 2 == 0) {

            if (white_player.make_move(from_square, to_square)) {
                turn++;
            } else {
                std::cout << "Invalid move." << std::endl;
            }

        } else {
            if (black_player.make_move(from_square, to_square)) {
                turn++;
            } else {
                std::cout << "Invalid move." << std::endl;
            }
        }
    }

    std::cout << "Game over." << std::endl;

    // print board to stdout
    std::cout << board << std::endl;

    // print winner to stdout
    if (black_player.piece_value() > white_player.piece_value()) {
        std::cout << "Black wins!" << std::endl;
    } else if (black_player.piece_value() < white_player.piece_value()) {
        std::cout << "White wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}