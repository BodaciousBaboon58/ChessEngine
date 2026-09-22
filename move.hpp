#pragma once

#include <cstdint>

// todo: incorporate move data (en passant, castling, etc.)

class Move {
public:
    Move(int start_square, int end_square);

    int start_square();

    int end_square();
private:
    uint16_t move;
};