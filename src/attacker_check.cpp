#include <iostream>
#include <cassert>
#include "engine_defs.hpp"
#include "vars.hpp"

int SqAttacked(const int sq, const int side, const Board *position) {
    int a,b,c,d;

    assert(SqOnBoard(sq));
    assert(SideValid(side));
    assert(CheckBoard(position));

    if(side==WHITE) {
        if(position->pieces[sq-11] == white_pawn || position->pieces[sq-9] == white_pawn) {
            return 1;
        }    
    } else {
        if(position->pieces[sq+11] == black_pawn || position->pieces[sq+9] == black_pawn) {
            return 1;
        }
    }

    for(b=0; b<8; ++b) {
        a = position->pieces[sq+KnightDirectory[b]];
        assert(PceValidEmptyOffbrd(a));
        if(a!=100 && IsKn(a) && PieceCol[a]==side) {
            return 1;
        }
    }

    for(b=0; b<4; ++b) {
        d = RookDirectory[b];
        c = sq+d;
        assert(SqIs120(c));
        a = position->pieces[c];
        assert(PceValidEmptyOffbrd(a));
        while(a!=100) {
            if(a!=0) {
                if(IsRQ(a) && PieceCol[a]==side) {
                    return 1;
                }
                break;            
            }
            c+=d;
            assert(SqIs120(c));
            a=position->pieces[c];
        }
    }
	for(b = 0; b < 4; ++b) {		
		d = BishopDirectory[b];
		c = sq + d;
		assert(SqIs120(c));
		a = position->pieces[c];
		assert(PceValidEmptyOffbrd(a));
		while(a != 100) {
			if(a != 0) {
				if(IsBQ(a) && PieceCol[a] == side) {
					return 1;
				}
				break;
			}
			c += d;
			assert(SqIs120(c));
			a = position->pieces[c];
		}
	}
	for(b = 0; b < 8; ++b) {		
		a = position->pieces[sq + KingDirectory[b]];
		assert(PceValidEmptyOffbrd(a));
		if(a != 100 && IsKi(a) && PieceCol[a]==side) {
			return 1;
		}
	}
	
	return 0;
    
}


