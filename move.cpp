#include "move.hpp"

int Move::start_square() {
    return move & (0b111111);
}

int Move::end_square() {
    return move >> 6;
}

Move::Move(int start_square, int end_square) : move(
    start_square + (end_square << 6)
) {}