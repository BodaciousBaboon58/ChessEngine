#include "board.hpp"
#include "board.cpp"
#include "move.hpp"
#include "move.cpp"
#include "piece.hpp"

#include <iostream>
using std::cout,std::endl;
// ^^^^ make cmake file instead of whatever this is

int main(void) {
    Board b = Board("4r1k1/ppb4p/6pP/P2p1pP1/3R1Pn1/2P3Q1/1q1B4/3B2K1 w - f6 0 32");
    b.display();
    cout<<"is white turn"<<endl;
    cout<<b.is_white_turn<<endl;
    cout<<"half move clock"<<endl;
    cout<<b.half_move_clock<<endl;
    cout<<"full move clock"<<endl;
    cout<<b.full_move_clock<<endl;
    cout<<"ep square"<<endl;
    cout<<(int)b.ep_square<<endl;
    cout<<"white king castle"<<endl;
    cout<<b.can_castle_wk<<endl;
    cout<<"white queen castle"<<endl;
    cout<<b.can_castle_wq<<endl;
    cout<<"black king castle"<<endl;
    cout<<b.can_castle_bk<<endl;
    cout<<"black queen castle"<<endl;
    cout<<b.can_castle_bq<<endl;
    
}