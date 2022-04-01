#pragma once

#ifndef ENGINE_DEFS_HPP
#define ENGINE_DEFS_HPP

#include <iostream>
#include <string>

#define INITIAL_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

const std::string about_engine[3] = {"Buzzer", "1.0", "Hamza Inan"};

void welcome_message() {
    if(about_engine[1] == "") {
        std::cout << about_engine[0] << "-dev" << " by " << about_engine[2] << std::endl;
    } else{
        std::cout << about_engine[0] << " " << about_engine[1] << " by " << about_engine[2] << std::endl;    
    }
}

//Components
#define EMPTY 0
#define white_pawn 1
#define white_knight 2
#define white_bishop 3
#define white_rook 4
#define white_queen 5
#define white_king 6
#define black_pawn 7
#define black_knight 8
#define black_bishop 9
#define black_rook 10
#define black_queen 11
#define black_king 12

//Board Rep.
#define A_File 0
#define B_File 1
#define C_File 2
#define D_File 3
#define E_File 4
#define F_File 5
#define G_File 6
#define H_File 7
#define Rank_1 0
#define Rank_2 1
#define Rank_3 2
#define Rank_4 3
#define Rank_5 4
#define Rank_6 5
#define Rank_7 6
#define Rank_8 7

//Sides
#define WHITE 0
#define BLACK 1
#define BOTHSIDE 2

//Communication
#define UCI 0

//Castling Encodes (based on FEN Code)
#define white_kingside 1
#define white_queenside 2
#define black_kingside 4
#define black_queenside 8

//Hashtable
#define Value_None 0
#define Value_Alpha 1
#define Value_Beta 2
#define Value_Exact 3

//Define some macros
#define FROMSQ(m) ((m) & 0x7F)
#define TOSQ(m) (((m)>>7) & 0x7F)
#define CAPTURED(m) (((m)>>14) & 0xF)
#define PROMOTED(m) (((m)>>20) & 0xF)
#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) )
#define SQ64(sq120) (Sq120ToSq64[(sq120)])
#define SQ120(sq64) (Sq64ToSq120[(sq64)])
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)
#define CLRBIT(bb,sq) ((bb) &= ClearMask[(sq)])
#define SETBIT(bb,sq) ((bb) |= SetMask[(sq)])
#define IsBQ(p) (PieceBishopQueen[(p)])
#define IsRQ(p) (PieceRookQueen[(p)])
#define IsKn(p) (PieceKnight[(p)])
#define IsKi(p) (PieceKing[(p)])
#define MIRROR64(sq) (Mirror64[(sq)])
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MFLAGEP 0x40000
#define MFLAGPS 0x80000
#define MFLAGCA 0x1000000
#define MFLAGCAP 0x7C000
#define MFLAGPROM 0xF00000
#define NOMOVE 0

//Classes
class MoveUtils {
public:
    int move,score;
};

class MoveList {
public:
    int count;
    MoveUtils movearray[256];
};

class HashTableEntry {
public:
    unsigned long long positionkey;
    int move,score,depth,flags;
};
    
class HashTable {
public:
    HashTableEntry *ptr;
    int entrysize,newreg,overreg,hit,cut;
};

class Rules {
public:
    int move,docastle,enpassant,fiftymove;
    unsigned long long positionkey;
};

class Board {
public:
    
    Rules history[2048];
    HashTable table[1];
    int searchH[13][120];
    int searchK[2][50];
    int pvidx[50]; // The bigger depths, the same number with it.
    int piece_list[13][10];
    int pieces[120];
    int piecetype[13];
    int big_pieces[2];
    int major_pieces[2];
    int minor_pieces[2];
    int material[2]; //white and black's material
    unsigned long long pawns[3]; //white, black and both pawns
    int king_squares[2]; //at the beginning, E1 and E8
    int side,enpassant,fiftymove,ply,historyply,docastle;
    unsigned long long positionkey;
};

class SearchUtil {
public:
    int start,stop,depth,timeset,movestogo,quit,stopped,nullcut;
    long nodes;
    float fh,fhf;
};

#endif
