//main file
//chess engine
//main.cpp
#include <iostream>
#include "position.h"
#include "legalmoves.h"

using namespace std;

int main()
{
	enum command{see_all,see_white,see_black,see_rooks,
			see_knights,see_bishops,see_queens,see_kings,find_moves,make_a_move,end};
	
	position board_position;//putting the pieces on the board
	
	//std::cout << "board_position.wp1[1]=" << board_position.wp1[1] << "\n";//debug
	
	legal_moves move_finder;//legal move finding function clustered in this class
	
	//user inputs for making a move:
	char side;
	char piece;
	int col;
	int row;
	int col_new;
	int row_new;
	
	int input;
	cout << "Enter move or command (enter 9 to exit program):\n";
	while(input != end){
		cin >> input;
		switch(input){
			case see_all: //0
				board_position.see_all();
				break;
			case see_white: //1
				board_position.see_white();
				break;
			case see_black: //2
				board_position.see_black();
				break;
			case see_rooks: //3
				board_position.see_rooks();
				break;
			case see_knights: //4
				board_position.see_knights();
				break;
			case see_bishops: //5
				board_position.see_bishops();
				break;
			case see_queens: //6
				board_position.see_queens();
				break;
			case see_kings: //7
				board_position.see_kings();
				break;
			case find_moves: //8
				move_finder.find_moves(board_position);
				break;
			case make_a_move: //9
				cout << "Enter side piece col row col_new row_new:\n";
				cin >> side >> piece >> col >> row >> col_new >> row_new;
				board_position.move(side,piece,col,row,col_new,row_new);
		}
	}
		
	return 0;
}