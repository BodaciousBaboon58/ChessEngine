#include "board.hpp"

Board::Board() {
    Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

Board::Board(std::string fen) {
    
}

bool Board::validate_pseudolegal_move(Move m) {

}

void Board::make_move(Move m) {

}

bool Board::is_game_over() {

}

std::vector<Move> Board::generate_pseudolegal_moves() {

}

std::vector<Move> Board::_generate_pawn_moves(u64 pawn) {

}

std::vector<Move> Board::_generate_rook_moves(u64 rook) {

}

std::vector<Move> Board::_generate_knight_moves(u64 knight) {
}

std::vector<Move> Board::_generate_bishop_moves(u64 bishop) {

}

std::vector<Move> Board::_generate_king_moves(u64 king) {
    
}

std::vector<Move> Board::_generate_queen_moves(u64 queen) {

}