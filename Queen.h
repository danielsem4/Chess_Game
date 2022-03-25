#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"


class Queen :public Piece
{
public:
	//constractor
	Queen(int);
	//setter
	void setDirection();
};

