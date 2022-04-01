#pragma once

#ifndef VARS_HPP
#define VARS_HPP

//Global Variables

int Mirror64[64] = 
{56,57,	58,	59,	60,	61,	62,	63,
48,	49,	50,	51,	52,	53,	54,	55,
40,	41,	42,	43,	44,	45,	46,	47,
32,	33,	34,	35,	36,	37,	38,	39,
24,	25,	26,	27,	28,	29,	30,	31,
16,	17,	18,	19,	20,	21,	22,	23,
8,	9,	10,	11,	12,	13,	14,	15,
0,	1,	2,	3,	4,	5,	6,	7};

int BitTable[64] = {
  63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
};

extern int Sq120ToSq64[120];
extern int Sq64ToSq120[64];
extern unsigned long long SetMask[64];
extern unsigned long long ClearMask[64];
extern unsigned long long PieceKeys[13][120];
extern unsigned long long SideKey;
extern unsigned long long CastleKeys[16];
char PceChar[] = ".PNBRQKpnbrqk";
char SideChar[] = "wb-";
char RankChar[] = "12345678";
char FileChar[] = "abcdefgh";
int PieceBig[13] = {0,0,1,1,1,1,0,0,1,1,1,1,0};
int PieceMaj[13] = {0,0,0,0,1,1,1,0,0,0,1,1,1};
int PieceMin[13] = {0,0,1,1,0,0,0,0,1,1,0,0,0};
int PieceVal[13] = {0,100,32,325,550,1000,0,100,325,325,550,1000,0};
int PieceCol[13] = {2,0,0,0,0,0,0,1,1,1,1,1,1};
int PiecePawn[13] = {0,1,0,0,0,0,0,1,0,0,0,0,0};
int PieceKnight[13] = {0,0,1,0,0,0,0,0,1,0,0,0,0};
int PieceKing[13] = {0,0,0,0,0,0,1,0,0,0,0,0,1};
int PieceRookQueen[13] = {0,0,0,0,1,1,0,0,0,0,1,1,0};
int PieceBishopQueen[13] = {0,0,0,1,0,1,0,0,0,1,0,1,0};
int PieceSlides[13] = {0,0,0,1,1,1,0,0,0,1,1,1,0};
int KnightDirectory[8] = {-8,-19,-21,-12,8,19,21,12};
int RookDirectory[4] = {-1,-10,1,10};
int BishopDirectory[4] = {-9,-11,11,9};
int KingDirectory[8] = {-1,-10,1,10,-9,-11,11,9};
int piecetypearr[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int bigpiecesarr[2] = { 0, 0};
int majorpiecesarr[2] = { 0, 0};
int minorpiecesarr[2] = { 0, 0};
int matarr[2] = { 0, 0};
extern int FilesBrd[120];
extern int RanksBrd[120];
extern unsigned long long FileBBMask[8];
extern unsigned long long RankBBMask[8];
extern unsigned long long BlackPassedMask[64];
extern unsigned long long WhitePassedMask[64];
extern unsigned long long IsolatedMask[64];

//Global Functions
extern int ProbeHashEntry(Board *position, int *move, int *score, int alpha, int beta, int depth);
extern int ProbePvMove(const Board *position);
extern int GetPvLine(const int depth, Board *position);
extern int PopBit(unsigned long long *bitboard);
extern int CountBits(unsigned long long board);
extern int ParseFen(char *fen, Board *position);
extern int CheckBoard(const Board *position);
extern int SqAttacked(const int sq, const int side, const Board *position);
extern int ParseMove(char *ptrChar, Board *position);
extern int SqOnBoard(const int sq);
extern int SideValid(const int side);
extern int FileRankValid(const int fr);
extern int PieceValidEmpty(const int pce);
extern int PieceValid(const int pce);
extern int SqIs120(const int sq);
extern int PceValidEmptyOffbrd(const int pce);
extern int MoveListOk(const MoveList *list,  const Board *position);
extern int MoveExists(Board *position, const int move);
extern int MakeMove(Board *position, int move);
extern int GetTimeMs();
extern int EvalPosition(Board *position);
extern void ResetBoard(Board *position);
extern void UpdateListsMaterial(Board *position);
extern void MirrorBoard(Board *position);
extern void AllInit();
extern void PrintMoveList(const MoveList *list);
extern void MirrorEvalTest(Board *position);
extern void GenerateAllMoves(const Board *position, MoveList *list);
extern void GenerateAllCaps(const Board *position, MoveList *list);
extern void InitMvvLva();
extern void TakeMove(Board *position);
extern void MakeNullMove(Board *position);
extern void TakeNullMove(Board *position);
extern void SearchPosition(Board *position, SearchUtil *info);
extern void InitSearch();
extern void ReadInput(SearchUtil *info);
extern void InitHashTable(HashTable *pot, const int MB);
extern void StoreHashEntry(Board *position, const int move, int score, const int flags, const int depth);
extern void ClearHashTable(HashTable *pot);
extern void MirrorEvalTest(Board *position) ;
extern void Uci_Loop(Board *position, SearchUtil *info);
extern char *PrMove(const int move);
extern char *PrSq(const int sq);
extern unsigned long long GeneratePosKey(const Board *position);


#endif
