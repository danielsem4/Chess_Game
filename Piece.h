#pragma once
#include <iostream>
#include <vector>
#include "Libraries.h"
#define BOARD_SIZE 8

using namespace std;

enum Icon {
	IPawn = L'♙',
	IBishop = L'♗',
	IKnight = L'♘',
	IRooks = L'♖',
	IKing = L'♔',
	IQueen = L'♕',
	IJoker = L'☃'
};

//♤
class Piece : public CWnd {
protected:
	vector<COORD> mdirection;
	int mplayer;
	int mdistance = BOARD_SIZE;
	wchar_t micon;

public:
	virtual ~Piece() {};
	
	//Getters for the player icon and the new location 
	int getPlayer() { return this->mplayer; }
	wchar_t getIcon() { return this->micon; }
	COORD getNewLocation(COORD istart, int inum, int idistance) { return istart + mdirection[inum] * idistance; }
	int numDirection() { return mdirection.size(); }

	//Setter for the direction 
	virtual void setDirection() = 0;

	virtual bool isLeagle(Piece* [8][8], COORD, COORD);
};


