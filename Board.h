#pragma once
#include <afx.h>
#include "Libraries.h"
#include "piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Joker.h"

#define NUM_OF_MAPS 12

class Board :public CObject
{
private:
	int iturn;
	int mindex;
	int const mmaxLevel = NUM_OF_MAPS;
	int mnumOfMove;
	Piece* mmat[BOARD_SIZE][BOARD_SIZE];
	COORD findKing(int);
	void loadFromList(int ilist[BOARD_SIZE][BOARD_SIZE][2]);
public:

	//constractor and distractor
	Board();
	Board(int);
	~Board();

	// setters
	void setNewBoard(int);
	void setIndex(int iindex=1) { this->mindex = iindex; }
	void setNumOfMove(int imove = 1) { this->mnumOfMove = imove; }

	// getters
	int& getTurn() { return iturn; }// returns whos turn it is 
	int getIndex() { return mindex; }//return the map number
	int getNumOfMove() { return mnumOfMove; }// return the number of moves you need to solve the puzzle

	//Functions
	void cleanBoard();
	void changePiece(COORD, int);
	bool checkChess(int);
	bool movePiece(COORD, COORD);
	void serializa(CArchive& iar);
	DECLARE_SERIAL(Board);
	void levelUp(int);
	int rightMove(int);

	//operators
	Piece*& operator[](COORD it) { return this->mmat[it.X][it.Y]; }
};

