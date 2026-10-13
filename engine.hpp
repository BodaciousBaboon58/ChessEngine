#pragma once

#include <board.hpp>
#include <move.hpp>
#include <evaluation.hpp>
#include <search.hpp>

class Engine
{
    private:
        

        
        std::vector<Move> generate_pseudolegal_moves();

        bool validate_pseudolegal_move(Move m){}
        // for each of the following methods:
        // TODO: "factorize" clz out because that's lowkey weird to have here
        // do NOT pass 0 in because that's UB

        std::vector<Move> _generate_pawn_moves(u64 pawn);

        std::vector<Move> _generate_rook_moves(u64 rook);

        std::vector<Move> _generate_knight_moves(u64 knight);

        std::vector<Move> _generate_bishop_moves(u64 bishop);

        std::vector<Move> _generate_king_moves(u64 king);

        std::vector<Move> _generate_queen_moves(u64 queen);



    public:





}
