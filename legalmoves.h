//specification file
//chess engine
//legalmoves.h

#ifndef LEGALMOVES_H
#define LEGALMOVES_H
//=================================
// forward declared dependencies
class position;

//=================================
// included dependencies
#include <vector>
#include "position.h"

//=================================
// the actual class
class legal_moves
{
	public:
	void find_moves(position&) const;//find all legal moves and add to vector 'moves',
							   //return 'checkmate' if that's the case
	bool checkmate(position&) const;//for find_moves (if checkmate report and exit...)
	bool check(position&) const;//for find_moves (if check, then...)
	bool en_passent(position&) const;
	
	private:
	std::vector<std::string> moves;//list of legal moves	
	int row_check;//row of piece putting you in check (-1 if no
	int col_check;
};

#endif