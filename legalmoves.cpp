//implementation file
//chess engine
//legalmoves.cpp

#include <iostream>
//#include <vector>
#include "position.h"
#include "legalmoves.h"

//using namespace std;

const int ROW = 1;
const int COL = 0;
int temp=0;int temp2=0;int temp3=0;int temp4=0;//temporary variables used in functions..

enum {a,b,c,d,e,f,g,h};
enum {one,two,three,four,five,six,seven,eight};

void legal_moves::find_moves(position& pos) const
{
	//find pawn moves
	//--pawn one (wp1)
	if(pos.wp1[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp1[COL] - 1;//don't ignore this side (pawn could move to b file)
		temp2 = pos.wp1[COL] + 1;
		temp3 = pos.wp1[ROW] + 1;
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p--" << temp+1 << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p--" << temp2+1 << temp3+1 << "\n";
		if(pos.wp1[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[a][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-a3\n";//debug
				if(pos.all_pieces[a][four] == 0) //check two squares ahead
					std::cout << "p-a4\n";
			}
		}
		else if(pos.wp1[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-a8 (promotion!)\n";
		}
		else
		{//else pawn has already moved,no promotion
			temp = pos.wp1[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[a][temp] == 0)
				std::cout << "p-a" << temp + 1 << "\n";
		}
	}
	//-PAWN TWO-PAWN TWO-PAWN TWO-PAWN TWO-PAWN TWO 
	if(pos.wp2[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp2[COL] - 1;
		temp2 = pos.wp2[COL] + 1;
		temp3 = pos.wp2[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-a" << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p-c" << temp3+1 << "\n";
		if(pos.wp2[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[b][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-b3\n";//debug
				if(pos.all_pieces[b][four] == 0) //check two squares ahead
					std::cout << "p-b4\n";
			}
		}
		else if(pos.wp2[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-b8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp2[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[b][temp] == 0)
				std::cout << "p-b" << temp + 1 << "\n";
		}
	}
	//-PAWN THREE-PAWN THREE-PAWN THREE
	if(pos.wp3[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp3[COL] - 1;
		temp2 = pos.wp3[COL] + 1;
		temp3 = pos.wp3[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-b" << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p-d" << temp3+1 << "\n";
		if(pos.wp3[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[c][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-c3\n";//debug
				if(pos.all_pieces[c][four] == 0) //check two squares ahead
					std::cout << "p-c4\n";
			}
		}
		else if(pos.wp3[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-c8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp3[ROW];
			if(pos.all_pieces[c][temp] == 0)
				std::cout << "p-c" << temp + 1 << "\n";
		}
	}
	//-PAWN FOUR-PAWN FOUR-PAWN FOUR
	if(pos.wp4[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp4[COL] - 1;
		temp2 = pos.wp4[COL] + 1;
		temp3 = pos.wp4[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-c" << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p-e" << temp3+1 << "\n";
		if(pos.wp4[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[d][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-d3\n";//debug
				if(pos.all_pieces[d][four] == 0) //check two squares ahead
					std::cout << "p-d4\n";
			}
		}
		else if(pos.wp4[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-d8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp4[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[d][temp] == 0)
				std::cout << "p-d" << temp + 1 << "\n";
		}
	}
	//-pawn five 
	if(pos.wp4[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp5[COL] - 1;
		temp2 = pos.wp5[COL] + 1;
		temp3 = pos.wp5[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-d" << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p-f" << temp3+1 << "\n";
		if(pos.wp5[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[e][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-e3\n";//debug
				if(pos.all_pieces[e][four] == 0) //check two squares ahead
					std::cout << "p-e4\n";
			}
		}
		else if(pos.wp5[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-e8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp5[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[e][temp] == 0)
				std::cout << "p-e" << temp + 1 << "\n";
		}
	}
	//-pawn six
	if(pos.wp6[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp6[COL] - 1;
		temp2 = pos.wp6[COL] + 1;
		temp3 = pos.wp6[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-e" << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p-g" << temp3+1 << "\n";
		if(pos.wp6[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[f][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-f3\n";//debug
				if(pos.all_pieces[f][four] == 0) //check two squares ahead
					std::cout << "p-f4\n";
			}
		}
		else if(pos.wp6[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-f8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp6[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[f][temp] == 0)
				std::cout << "p-f" << temp + 1 << "\n";
		}
	}
	//-pawn seven
	if(pos.wp7[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp7[COL] - 1;
		temp2 = pos.wp7[COL] + 1;
		temp3 = pos.wp7[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-f" << temp3+1 << "\n";
		if(pos.black_pieces[temp2][temp3] == 1)
			std::cout << "p-h" << temp3+1 << "\n";
		if(pos.wp7[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[g][three] == 0) //check one square ahead
			{
				//moves.push_back('p-a3');??Why doesn't this work?
				std::cout << "p-g3\n";//debug
				if(pos.all_pieces[g][four] == 0) //check two squares ahead
					std::cout << "p-g4\n";
			}
		}
		else if(pos.wp7[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-g8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp7[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[g][temp] == 0)
				std::cout << "p-g" << temp + 1 << "\n";
		}
	}
	//-pawn eight//-pawn eight//-pawn eight//-pawn eight//-pawn eight//-pawn eight
	if(pos.wp8[ROW] == -1)//if pawn has been taken (row col set to -1)
	{
		//do nothing
	}
	else 
	{
		//first check diagonals for piece capture:
		temp = pos.wp8[COL] - 1;
		temp2 = pos.wp8[COL] + 1;
		temp3 = pos.wp8[ROW];
		if(pos.black_pieces[temp][temp3] == 1)
			std::cout << "p-g" << temp3+1 << "\n";
		if(pos.wp8[ROW] == two)//if pawn hasn't moved yet:
		{
			if(pos.all_pieces[h][three] == 0) //check one square ahead
			{
				std::cout << "p-h3\n";//debug
				if(pos.all_pieces[h][four] == 0) //check two squares ahead
					std::cout << "p-h4\n";
			}
		}
		else if(pos.wp8[ROW] == seven)//if on row 7 then promotion!!
		{
			std::cout << "p-h8 (promotion!)\n";
		}
		else
		{//else (pawn has already moved
			temp = pos.wp8[ROW]; //note: bitboards indexed 0 to 7, piece coord. not so... 
			if(pos.all_pieces[h][temp] == 0)
				std::cout << "p-h" << temp + 1 << "\n";
		}
	}
//--------END OF !white! PAWN MOVE CALCULATIONS---------//
}


