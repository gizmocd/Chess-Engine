//implementation file
//chess engine
//position.cpp
#include "position.h"
#include <iostream>

enum {a,b,c,d,e,f,g,h};
enum {one,two,three,four,five,six,seven,eight};

position::position()
{
	int length = 8;
	int width = 8;
	int row = 0;
	int col = 0;
	for(int i=0; i<length;i++){
		for(int j=0;j<width;j++){
			col = i;//this is used in logic for direct correspondence
			row = j+1;//between standard row & column lookup
			all_pieces[i][j]=(row==7 || row==8 || row==1 || row==2);
			white_pieces[i][j]=(row==1 || row==2);
			black_pieces[i][j]=(row==7 || row==8);//{col,row->ex:e4}
			white_pawns[i][j]=(row==2);	
			black_pawns[i][j]=(row==7);
			white_knights[i][j]=(row==1 && (col==b || col==g));
			black_knights[i][j]=(row==8 && (col==b || col==g));
			white_bishops[i][j]=(row==1 && (col==c || col==f));
			black_bishops[i][j]=(row==8 && (col==c || col==f));
			white_rooks[i][j]=(row==1 && (col==a || col==h));
			black_rooks[i][j]=(row==8 && (col==a || col==h));
			white_queen[i][j]=(row==1 && col==d);
			black_queen[i][j]=(row==8 && col==d);
			white_king[i][j]=(row==1 && col==e);
			black_king[i][j]=(row==8 && col==e);
		}
	}
	wp1[0]=a;wp1[1]=two;//white pawn one coordinates..
	wp2[0]=b;wp1[1]=two;
	wp3[0]=c;wp1[1]=two;
	wp4[0]=d;wp1[1]=two;
	wp5[0]=e;wp1[1]=two;
	wp6[0]=f;wp1[1]=two;
	wp7[0]=g;wp1[1]=two;
	wp8[0]=h;wp1[1]=two;
	
	wR1[0]=a;wR1[1]=one;
	wR2[0]=h;wR2[1]=one;
	wN1[0]=b;wN1[1]=one;
	wN2[0]=g;wN2[1]=one;
	wB1[0]=c;wB1[1]=one;
	wB2[0]=f;wB2[1]=one;
	wQ[0]=d;wQ[1]=one;
	wK[0]=e;wK[1]=one;
	
	bp1[0]=a;bp1[1]=seven;
	bp2[0]=b;bp1[1]=seven;
	bp3[0]=c;bp1[1]=seven;
	bp4[0]=d;bp1[1]=seven;
	bp5[0]=e;bp1[1]=seven;
	bp6[0]=f;bp1[1]=seven;
	bp7[0]=g;bp1[1]=seven;
	bp8[0]=h;bp1[1]=seven;
	
	bR1[0]=a;bR1[1]=eight;
	bR2[0]=h;bR2[1]=eight;
	bN1[0]=b;bN1[1]=eight;//SET THESE COORDINATES TO -1 IF PIECE
	bN2[0]=g;bN2[1]=eight;//IS CAPTURED!!
	bB1[0]=c;bB1[1]=eight;
	bB2[0]=f;bB2[1]=eight;
	bQ[0]=d;bQ[1]=eight;
	bK[0]=e;bK[1]=eight;
}

void position::move(char black_or_white, int piece, int col, int row, int col_new, int row_new)
{
	//Note: for 'piece' we must move the individual piece so piece must indicate which
	//piece it is. Therefore we utilize enum (again). MUST GIVE USER A THOROUGH GUIDE
	
	//Note: must add logic for capture-- need to update captured pieces coordinates
	//to -1 -1 (i.e. off the board)
	/*enum {white_pawn1,white_pawn2,white_pawn3,white_pawn4,white_pawn5,white_pawn6
			,white_pawn7,white_pawn8,black_pawn1,black_pawn2,black_pawn3,black_pawn4
			,black_pawn5,black_pawn6,black_pawn7,black_pawn8,white_rook1,white_rook2
			,white_knight1,white_knight2,white_bishop1,white_bishop2,white_queen1
			,white_king1,black_rook1,black_rook2,black_knight1,black_knight2
			,black_bishop1,black_bishop2,black_queen1,black_king1};
	*/ // the above enum doesn't work in switch statement.. using corresponding numbers..
	if(black_or_white == 'w'){
		all_pieces[col][row] = 0;
		black_pieces[col][row] = 0;
		all_pieces[col_new][row_new] = 1;	
		white_pieces[col][row] = 0;
		white_pieces[col_new][row_new] = 1;
		switch(piece){
			case 1: 
				white_rooks[col][row] = 0;
				white_rooks[col_new][row_new] = 1;
				wR1[0]=col_new;wR1[1]=row_new;
				break;
			case 2:
				white_rooks[col][row] = 0;
				white_rooks[col_new][row_new] = 1;
				wR2[0]=col_new;wR2[1]=row_new;
				break;
			case 3:
				white_knights[col][row] = 0;
				white_knights[col_new][row_new] = 1;
				wN1[0]=col_new;wN1[1]=row_new;
				break;
			case 4:
				white_knights[col][row] = 0;
				white_knights[col_new][row_new] = 1;
				wN2[0]=col_new;wN2[1]=row_new;
				break;
			case 5:
				white_bishops[col][row] = 0;
				white_bishops[col_new][row_new] = 1;
				wB1[0]=col_new;wB1[1]=row_new;
				break;
			case 6:
				white_bishops[col][row] = 0;
				white_bishops[col_new][row_new] = 1;
				wB2[0]=col_new;wB2[1]=row_new;
				break;
			case 7:
				white_queen[col][row] = 0;
				white_queen[col_new][row_new] = 1;
				wQ[0]=col_new;wQ[1]=row_new;
				break;
			case 8:
				white_king[col][row] = 0;
				white_king[col_new][row_new] = 1;
				wK[0]=col_new;wK[1]=row_new;
				break;
			case 9:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp1[0]=col_new;wp1[1]=row_new;
				break;
			case 10:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp2[0]=col_new;wp2[1]=row_new;
				break;
			case 11:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp3[0]=col_new;wp3[1]=row_new;
				break;
			case 12:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp4[0]=col_new;wp4[1]=row_new;
				break;
			case 13:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp5[0]=col_new;wp5[1]=row_new;
				break;
			case 14:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp6[0]=col_new;wp6[1]=row_new;
				break;
			case 15:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp7[0]=col_new;wp7[1]=row_new;
				break;
			case 16:
				white_pawns[col][row] = 0;
				white_pawns[col_new][row_new] = 1;
				wp8[0]=col_new;wp8[1]=row_new;
				break;
			default:
				std::cout << "Error, unknown piece\n";
		}
	}else{
		all_pieces[col][row] = 0;
		white_pieces[col][row] = 0;
		all_pieces[col_new][row_new] = 1;	
		black_pieces[col][row] = 0;
		black_pieces[col_new][row_new] = 1;
		switch(piece){
			case 1:
				black_rooks[col][row] = 0;
				black_rooks[col_new][row_new] = 1;
				bR1[0]=col_new;bR1[1]=row_new;
				break;
			case 2:
				black_rooks[col][row] = 0;
				black_rooks[col_new][row_new] = 1;
				bR2[0]=col_new;bR2[1]=row_new;
				break;
			case 3:
				black_knights[col][row] = 0;
				black_knights[col_new][row_new] = 1;
				bN1[0]=col_new;bN1[1]=row_new;
				break;
			case 4:
				black_knights[col][row] = 0;
				black_knights[col_new][row_new] = 1;
				bN2[0]=col_new;bN2[1]=row_new;
				break;
			case 5:
				black_bishops[col][row] = 0;
				black_bishops[col_new][row_new] = 1;
				bB1[0]=col_new;bB1[1]=row_new;
				break;
			case 6:
				black_bishops[col][row] = 0;
				black_bishops[col_new][row_new] = 1;
				bB2[0]=col_new;bB2[1]=row_new;
				break;
			case 7:
				black_queen[col][row] = 0;
				black_queen[col_new][row_new] = 1;
				bQ[0]=col_new;bQ[1]=row_new;
				break;
			case 8:
				black_king[col][row] = 0;
				black_king[col_new][row_new] = 1;
				bK[0]=col_new;bK[1]=row_new;
				break;
			case 9:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp1[0]=col_new;bp1[1]=row_new;
				break;
			case 10:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp2[0]=col_new;bp2[1]=row_new;
				break;
			case 11:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp3[0]=col_new;bp3[1]=row_new;
				break;
			case 12:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp4[0]=col_new;bp4[1]=row_new;
				break;
			case 13:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp5[0]=col_new;bp5[1]=row_new;
				break;
			case 14:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp6[0]=col_new;bp6[1]=row_new;
				break;
			case 15:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp7[0]=col_new;bp7[1]=row_new;
				break;
			case 16:
				black_pawns[col][row] = 0;
				black_pawns[col_new][row_new] = 1;
				bp8[0]=col_new;bp8[1]=row_new;
				break;
			default:
				std::cout << "Error, unknown piece\n";
		}
	}	
}

void position::see_all() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){	
			if(all_pieces[row][col]==1)
				std::cout << "P";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_white() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){	
			if(white_pieces[row][col]==1)
				std::cout << "W";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_black() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){	
			if(black_pieces[row][col]==1)
				std::cout << "B";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_rooks() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){
			if(white_rooks[row][col]==1)
				std::cout << "W";	
			else if(black_rooks[row][col]==1)
				std::cout << "B";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_knights() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){
			if(white_knights[row][col]==1)
				std::cout << "W";	
			else if(black_knights[row][col]==1)
				std::cout << "B";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_bishops() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){
			if(white_bishops[row][col]==1)
				std::cout << "W";	
			else if(black_bishops[row][col]==1)
				std::cout << "B";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_queens() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){
			if(white_queen[row][col]==1)
				std::cout << "W";	
			else if(black_queen[row][col]==1)
				std::cout << "B";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}

void position::see_kings() const
{
	for(int col=0; col<8;col++){
		for(int row=0; row<8;row++){
			if(white_king[row][col]==1)
				std::cout << "W";	
			else if(black_king[row][col]==1)
				std::cout << "B";
			else
				std::cout << "-";
		}	
		std::cout << "\n";
	}	
}






