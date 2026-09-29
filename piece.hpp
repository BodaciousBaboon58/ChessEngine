#pragma once

#include <unordered_map>

enum Piece {
    WHITE_PAWN = 0,
    WHITE_ROOK = 1,
    WHITE_KNIGHT = 2,
    WHITE_BISHOP = 3,
    WHITE_KING = 4,
    WHITE_QUEEN = 5,
    BLACK_PAWN = 6,
    BLACK_ROOK = 7,
    BLACK_KNIGHT = 8,
    BLACK_BISHOP = 9,
    BLACK_KING = 10,
    BLACK_QUEEN = 11,
    NONE = 12
};

std::unordered_map<Piece, char> piece_to_character = {
    {Piece::WHITE_PAWN, 'P'},
    {Piece::WHITE_ROOK, 'R'},
    {Piece::WHITE_KNIGHT, 'N'},
    {Piece::WHITE_BISHOP, 'B'},
    {Piece::WHITE_KING, 'K'},
    {Piece::WHITE_QUEEN, 'Q'},
    {Piece::BLACK_PAWN, 'p'},
    {Piece::BLACK_ROOK, 'r'},
    {Piece::BLACK_KNIGHT, 'n'},
    {Piece::BLACK_BISHOP, 'b'},
    {Piece::BLACK_KING, 'k'},
    {Piece::BLACK_QUEEN, 'q'},
    {Piece::NONE, ' '}
};

std::unordered_map<char, Piece> character_to_piece = {
    {'P', Piece::WHITE_PAWN},
    {'R', Piece::WHITE_ROOK},
    {'N', Piece::WHITE_KNIGHT},
    {'B', Piece::WHITE_BISHOP},
    {'K', Piece::WHITE_KING},
    {'Q', Piece::WHITE_QUEEN},
    {'p', Piece::BLACK_PAWN},
    {'r', Piece::BLACK_ROOK},
    {'n', Piece::BLACK_KNIGHT},
    {'b', Piece::BLACK_BISHOP},
    {'k', Piece::BLACK_KING},
    {'q', Piece::BLACK_QUEEN},
    {' ', Piece::NONE}
};