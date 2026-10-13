#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "move.hpp"
#include "piece.hpp"

// todo: make a cpp and hpp file like a normal person

typedef uint64_t u64;

class Board {
private:
    u64 rook_bb;
    u64 bishop_bb;
    u64 knight_bb;
    u64 king_bb;
    u64 queen_bb;
    u64 pawn_bb;
    
    u64 white_mask;
    u64 black_mask;



    
public:

    bool is_white_turn = true;

    //fifty move rule counter
    int half_move_clock = 0;
    //moves in game
    int full_move_clock = 0;

    //wk=white kingside, wq=white queenside, etc etc
    bool can_castle_wk = true;
    bool can_castle_wq = true;
    bool can_castle_bk = true;
    bool can_castle_bq = true;
    int8_t ep_square=-1;

    Board();

    Board(std::string fen);

    void display();

    Piece get_piece_at(int square);

    void set_piece_at(int square, Piece piece);

    void clear_square(int square);

    bool validate_move(Move m);

    void make_move(Move m);

    bool is_game_over(void);


};
