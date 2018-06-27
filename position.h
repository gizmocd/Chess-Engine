//specification file
//chess engine (old)
//position.h
#ifndef POSITION_H
#define POSITION_H
 
class position{
	public:
	position();
	void move(char black_or_white, int piece, int col, int row, int col_new, int row_new);
	void see_all() const;
	void see_white() const;
	void see_black() const;
	void see_rooks() const;
	void see_knights() const;
	void see_bishops() const;
	void see_queens() const;
	void see_kings() const;
	
	int all_pieces[8][8];//bitboards (*make bools later instead of ints!)
	int white_pawns[8][8];	
	int black_pawns[8][8];
	int white_pieces[8][8];
	int black_pieces[8][8];
	int white_knights[8][8];
	int black_knights[8][8];
	int white_bishops[8][8];
	int black_bishops[8][8];
	int white_rooks[8][8];
	int black_rooks[8][8];
	int white_queen[8][8];
	int black_queen[8][8];
	int white_king[8][8];
	int black_king[8][8];
	
	int wp1[2];//white pawn one coordinates..
	int wp2[2];
	int wp3[2];
	int wp4[2];
	int wp5[2];
	int wp6[2];
	int wp7[2];
	int wp8[2];
	
	int wR1[2];
	int wR2[2];
	int wN1[2];
	int wN2[2];
	int wB1[2];
	int wB2[2];
	int wQ[2];
	int wK[2];
	
	int bp1[2];//black pawn one coordinates..
	int bp2[2];
	int bp3[2];
	int bp4[2];
	int bp5[2];
	int bp6[2];
	int bp7[2];
	int bp8[2];
	
	int bR1[2];
	int bR2[2];
	int bN1[2];
	int bN2[2];
	int bB1[2];
	int bB2[2];
	int bQ[2];
	int bK[2];
};

#endif








