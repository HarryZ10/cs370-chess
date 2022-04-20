#include "Chess.h"

int main() {
    Board board = Board();

    King *white_king = new King(Piece::Color::white, board.square_at(0, 4));
    Queen *white_queen = new Queen(Piece::Color::white, board.square_at(0, 3));
    Rook *white_rook_1 = new Rook(Piece::Color::white, board.square_at(0, 0));
    Rook *white_rook_3 = new Rook(Piece::Color::white, board.square_at(1, 0));
    Rook *white_rook_2 = new Rook(Piece::Color::white, board.square_at(0, 7));
    Bishop *white_bishop_1 = new Bishop(Piece::Color::white, board.square_at(0, 2));
    Bishop *white_bishop_2 = new Bishop(Piece::Color::white, board.square_at(0, 5));
    Knight *white_knight_1 = new Knight(Piece::Color::white, board.square_at(0, 1));
    Knight *white_knight_2 = new Knight(Piece::Color::white, board.square_at(0, 6));

    // makea list of white pawns
    std::vector<Pawn*> white_pawns;

    // for (int i = 0; i < 8; i++) {
    //     white_pawns.push_back(new Pawn(Piece::Color::white, board.square_at(1, i)));
    // }

    King *black_king = new King(Piece::Color::black, board.square_at(7, 3));
    Queen *black_queen = new Queen(Piece::Color::black, board.square_at(7, 4));
    Rook *black_rook_1 = new Rook(Piece::Color::black, board.square_at(7, 0));
    Rook *black_rook_2 = new Rook(Piece::Color::black, board.square_at(7, 7));
    Bishop *black_bishop_1 = new Bishop(Piece::Color::black, board.square_at(7, 2));
    Bishop *black_bishop_2 = new Bishop(Piece::Color::black, board.square_at(7, 5));
    Knight *black_knight_1 = new Knight(Piece::Color::black, board.square_at(7, 1));
    Knight *black_knight_2 = new Knight(Piece::Color::black, board.square_at(7, 6));

    // make a list of black pawns
    std::vector<Pawn*> black_pawns;

    for (int i = 0; i < 8; i++) {
        black_pawns.push_back(new Pawn(Piece::Color::black, board.square_at(6, i)));
    }

}