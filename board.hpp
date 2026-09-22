#include <cstdint>
#include <string>
#include <vector>

#include "move.hpp"

// todo: make a cpp and hpp file like a normal person

typedef uint64_t u64;

class Board {
// NOTES:
// bitboard bits are in column-major order
// bit 0 (LSB) = A1, bit 1 = A2, bit 2 = A3, ...
private:
    u64 rook_bb;
    u64 bishop_bb;
    u64 knight_bb;
    u64 king_bb;
    u64 queen_bb;
    u64 pawn_bb;
    
    u64 white_mask;
    u64 black_mask;

    bool is_white_turn;
public:
    Board();

    Board(std::string fen);

    bool validate_pseudolegal_move(Move m);

    void make_move(Move m);

    bool is_game_over(void);

    std::vector<Move> generate_pseudolegal_moves();

    // for each of the following methods:
    // not private because engine peeps might want finer-grained control over generation
    // TODO: "factorize" clz out because that's lowkey weird to have here
    // do NOT pass 0 in because that's UB

    std::vector<Move> _generate_pawn_moves(u64 pawn);

    std::vector<Move> _generate_rook_moves(u64 rook);

    std::vector<Move> _generate_knight_moves(u64 knight);

    std::vector<Move> _generate_bishop_moves(u64 bishop);

    std::vector<Move> _generate_king_moves(u64 king);

    std::vector<Move> _generate_queen_moves(u64 queen);
};
