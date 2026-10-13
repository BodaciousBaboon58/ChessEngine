#include <cctype> // std::isdigit
#include <iostream>

#include "board.hpp"
#include "piece.hpp"

Board::Board() : Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {}

Board::Board(std::string FEN) {
    int s_index = -1;
    int current_square = 0;
    std::string castling_info;

    std::string ranks[8];
    std::string fen_metadata;
    for(int i=0; i<8; i++){
        if(i<7){
            ranks[7-i]=FEN.substr(0,FEN.find('/'));
            FEN = std::string(FEN.begin() + FEN.find('/')+1, FEN.end());
        }
        else{
            ranks[7-i]=FEN.substr(0,FEN.find(' '));
            FEN = std::string(FEN.begin() + FEN.find_first_of(' '), FEN.end());
        }
    }
    fen_metadata=FEN;
    FEN="";
    for(int i=0; i<8; i++){
        FEN.append(ranks[i]);
    }
    while (current_square < 64) {
        s_index++;
        char item = FEN[s_index];
        if (item == '/') {
            continue;
        } else if (item == ' ') {
            break;
        } else if (std::isdigit(item)) { // skip that many squares
            for(int i=0; i<item-'0'; i++){
                set_piece_at(current_square,character_to_piece[' ']);
                current_square++;
            }
        } else {
            set_piece_at(current_square, character_to_piece[item]);
            current_square++;
        }
    }
    is_white_turn=(fen_metadata[fen_metadata.find_first_not_of(' ')] == 'w');
    fen_metadata=fen_metadata.substr(3);
    can_castle_wk=(fen_metadata.find('K')!=std::string::npos);
    can_castle_wq=(fen_metadata.find('Q')!=std::string::npos);
    can_castle_bk=(fen_metadata.find('k')!=std::string::npos);
    can_castle_bq=(fen_metadata.find('q')!=std::string::npos);
    fen_metadata=fen_metadata.substr(fen_metadata.find_first_of(' '));
    full_move_clock=stoi(fen_metadata.substr(fen_metadata.find_last_of(' ')));
    fen_metadata=fen_metadata.substr(0,fen_metadata.find_last_of(' '));
    half_move_clock=stoi(fen_metadata.substr(fen_metadata.find_last_of(' ')));
    fen_metadata=fen_metadata.substr(0,fen_metadata.find_last_of(' '));
    fen_metadata=fen_metadata.substr(1,fen_metadata.size()-1);
    if(fen_metadata.find('-')==fen_metadata.find('*')){
        ep_square = (fen_metadata[1]-'0')*8+(fen_metadata[0]-'a');
    }
}

void Board::display() {
    for (int i = 63; i >= 0; i--) {
        std::cout << character_to_symbol[piece_to_character[get_piece_at(7 ^ i)]]<<' ';
        if (i % 8 == 0) {
            std::cout << "\n";
        }
    }
}

bool Board::validate_pseudolegal_move(Move m) {
    return true;
}

Piece Board::get_piece_at(int square) {
    // compiler will optimize this hopefully
    // TODO: also keep separate representation as array[Piece]
    u64 bit = 1ULL << square;

    if (bit & white_mask) {
        if (bit & pawn_bb)      return Piece::WHITE_PAWN;
        if (bit & rook_bb)      return Piece::WHITE_ROOK;
        if (bit & knight_bb)    return Piece::WHITE_KNIGHT;
        if (bit & bishop_bb)    return Piece::WHITE_BISHOP;
        if (bit & king_bb)      return Piece::WHITE_KING;
        else                    return Piece::WHITE_QUEEN;
    } else if (bit & black_mask) {
        if (bit & pawn_bb)      return Piece::BLACK_PAWN;
        if (bit & rook_bb)      return Piece::BLACK_ROOK;
        if (bit & knight_bb)    return Piece::BLACK_KNIGHT;
        if (bit & bishop_bb)    return Piece::BLACK_BISHOP;
        if (bit & king_bb)      return Piece::BLACK_KING;
        else                    return Piece::BLACK_QUEEN;
    }
    return Piece::NONE;
}

void Board::set_piece_at(int square, Piece piece) {
    // does not perform literally any validation (things like spawning a king, placing a pawn on back rank, etc.)
    clear_square(square);

    if (piece == Piece::NONE) {
        return;
    }

    u64 bit = 1ULL << square;

    // update global white/black masks
    if (piece < Piece::BLACK_PAWN /* piece is white */) {
        white_mask |= bit;
    } else {
        black_mask |= bit;
    }

    // update individual piece mask
    switch (piece % 6) {
        case (Piece::WHITE_PAWN):   pawn_bb |= bit;     break;
        case (Piece::WHITE_ROOK):   rook_bb |= bit;     break;
        case (Piece::WHITE_KNIGHT): knight_bb |= bit;   break;
        case (Piece::WHITE_BISHOP): bishop_bb |= bit;   break;
        case (Piece::WHITE_KING):   king_bb |= bit;     break;
        case (Piece::WHITE_QUEEN):  queen_bb |= bit;    break;
    }
}

void Board::clear_square(int square) {
    u64 bit = 1ULL << square;

    rook_bb &= ~bit;
    bishop_bb &= ~bit;
    knight_bb &= ~bit;
    king_bb &= ~bit;
    queen_bb &= ~bit;
    pawn_bb &= ~bit;

    white_mask &= ~bit;
    black_mask &= ~bit;
}

void Board::make_move(Move m) {

}

bool Board::is_game_over() {
    return false;
}

std::vector<Move> Board::generate_pseudolegal_moves() {
    return std::vector<Move>();
}

std::vector<Move> Board::_generate_pawn_moves(u64 pawn) {
    return std::vector<Move>();
}

std::vector<Move> Board::_generate_rook_moves(u64 rook) {
    return std::vector<Move>();
}

std::vector<Move> Board::_generate_knight_moves(u64 knight) {
    return std::vector<Move>();
}

std::vector<Move> Board::_generate_bishop_moves(u64 bishop) {
    return std::vector<Move>();
}

std::vector<Move> Board::_generate_king_moves(u64 king) {
    return std::vector<Move>();
}

std::vector<Move> Board::_generate_queen_moves(u64 queen) {
    return std::vector<Move>();
}