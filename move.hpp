#pragma once

#include <cstdint>

// todo: incorporate move data (en passant, castling, etc.)

class Move {
public:
    Move(int start_square, int end_square) : move(
        start_square + (end_square << 6)
    ) {}
    int start_square() {
        return move & (0b111111);
    }
    int end_square() {
        return move >> 6;
    }
private:
    uint16_t move;
};