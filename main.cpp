#include "board.hpp"
#include "board.cpp"
#include "move.hpp"
#include "move.cpp"
#include "piece.hpp"
// ^^^^ make cmake file instead of whatever this is

int main(void) {
    Board b = Board();
    b.display();
}