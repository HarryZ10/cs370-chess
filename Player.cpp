#include "Player.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

Player::Player(Piece::Color color, const Board& board): _color(color), _board(board) {
    // if color is white, setup the pieces on the board
    if (color == Piece::Color::black) {
        // setup the pawns
        for (size_t i = 0; i < 8; i++) {
            this->_pieces.push_back(new Pawn(Piece::Color::black, board.square_at(1, i)));
        }

        // setup the rooks
        this->_pieces.push_back(new Rook(Piece::Color::black, board.square_at(0, 0)));
        this->_pieces.push_back(new Rook(Piece::Color::black, board.square_at(0, 7)));

        // setup the knights
        this->_pieces.push_back(new Knight(Piece::Color::black, board.square_at(0, 1)));
        this->_pieces.push_back(new Knight(Piece::Color::black, board.square_at(0, 6)));

        // setup the bishops
        this->_pieces.push_back(new Bishop(Piece::Color::black, board.square_at(0, 2)));
        this->_pieces.push_back(new Bishop(Piece::Color::black, board.square_at(0, 5)));

        // setup the queen and king
        this->_pieces.push_back(new Queen(Piece::Color::black, board.square_at(0, 3)));
        this->_king = new King(Piece::Color::black, board.square_at(0, 4));

        this->_pieces.push_back(this->_king);
    } else {
        // setup the pawns
        for (size_t i = 0; i < 8; i++) {
            this->_pieces.push_back(new Pawn(Piece::Color::white, board.square_at(6, i)));
        }

        // setup the rooks
        this->_pieces.push_back(new Rook(Piece::Color::white, board.square_at(7, 0)));
        this->_pieces.push_back(new Rook(Piece::Color::white, board.square_at(7, 7)));

        // setup the knights
        this->_pieces.push_back(new Knight(Piece::Color::white, board.square_at(7, 1)));
        this->_pieces.push_back(new Knight(Piece::Color::white, board.square_at(7, 6)));

        // setup the bishops
        this->_pieces.push_back(new Bishop(Piece::Color::white, board.square_at(7, 2)));
        this->_pieces.push_back(new Bishop(Piece::Color::white, board.square_at(7, 5)));

        // setup the queen and king
        this->_pieces.push_back(new Queen(Piece::Color::white, board.square_at(7, 3)));
        this->_king = new King(Piece::Color::white, board.square_at(7, 4));

        this->_pieces.push_back(this->_king);
    }
}


Piece::Color Player::color() const {
    return this->_color;
}


bool Player::make_move(const std::string& from, const std::string& to) {
    bool result = false;

    // The "from" square should be occupied by a piece of the same color as the player (the "piece").
    if (this->_board.square_at(from).is_occupied() && this->_board.square_at(from).occupant()->color() == this->_color) {

        // get occupant of from square
        // If the piece reports that it can move to the "to" square,
        if (this->_board.square_at(from).occupant()->can_move_to(this->_board.square_at(to))) {

            // The "to" square should be unoccupied, or occupied by a piece not of the same color (the "opponent piece").
            if (!this->_board.square_at(to).is_occupied()) {

                // move piece to "to" square
                this->_board.square_at(from).occupant()->move_to(this->_board.square_at(to));
                result = true;
            }
            else if(this->_board.square_at(to).occupant()->color() != this->_color){

                // capture
                this->_board.square_at(to).occupant()->capture();
                this->_board.square_at(from).occupant()->move_to(this->_board.square_at(to));
                result = true;
            }
       

        }
    }

    return result;
}


piece_value_t Player::piece_value() const {
    piece_value_t result = 0;

    for (Piece* piece : this->_pieces) {
        result += piece->value();
    }

    return result;
}


Player::~Player() {
    for (Piece* piece : this->_pieces) {
        delete piece;
    }
}