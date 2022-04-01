#include <iostream>
#include "engine_defs.hpp"
#include "vars.hpp"

int PopBit(unsigned long long *bitboard) {
    unsigned long long a = *bitboard ^ (*bitboard-1);
    unsigned int b = (unsigned)((a & 0xffffffff) ^ (a >> 32));
    *bitboard &= (*bitboard-1);
    return BitTable[(b*0x783a9b23)>>26];
}

int CountBits(unsigned long long board) {
    int a;
    for(a=0;board;a++,board&=board-1);
    return a;
}

int PceListOk(const Board *position) {
    int a = white_pawn;
	int b,c;
	for(a = white_pawn; a <= black_king; ++a) {
		if(position->piecetype[a]<0 || position->piecetype[a]>=10) return 0;
	}

	if(position->piecetype[white_king]!=1 || position->piecetype[black_king]!=1) return 0;

	for(a = white_pawn; a <= black_king; ++a) {
		for(c = 0; c < position->piecetype[a]; ++c) {
			b = position->piece_list[a][c];
			if(!SqOnBoard(b)) return 0;
		}
	}
    return 1;
}

int CheckBoard(const Board *position) {
    int a,b,c,d,e,f;
    unsigned long long pawnsarr[3] = {0ULL, 0ULL, 0ULL};
    pawnsarr[WHITE] = position->pawns[WHITE];
    pawnsarr[BLACK] = position->pawns[BLACK];
    pawnsarr[BOTHSIDE] = position->pawns[BOTHSIDE];
    for(b=white_pawn; b<=black_king; ++b) {
        for(c=0; c<position->piecetype[b]; ++c) {
            d=position->piece_list[b][c];
            assert(position->pieces[d]==b);
        }
    }

    for(a=0; a<64; ++a) {
        d=SQ120(a);
        b=position->pieces[d];
        piecetypearr[b]++;
        e=PieceCol[b];
        if(PieceBig[b]==1) {
            bigpiecesarr[e]++;
        }
        if(PieceMin[b]==1) {
            minorpiecesarr[e]++;
        }
        if(PieceMaj[b]==1) {
            majorpiecesarr[e]++;
        }
        matarr[e] += PieceVal[b];
    }
}


