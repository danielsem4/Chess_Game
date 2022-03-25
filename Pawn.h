#pragma once
#include "piece.h"

class Pawn : public Piece
{
public:
	//constractor
	Pawn(int);

	//setter
	void setDirection();

	// Function that 
	bool isLeagle(Piece* [8][8], COORD, COORD);
};