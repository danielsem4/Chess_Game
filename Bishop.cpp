#include "pch.h"
#include "Bishop.h"

//constractor
Bishop::Bishop(int iplayer) {
	this->mplayer = iplayer;
	setDirection();
	micon = IBishop;
}

// Bishop moves
void Bishop::setDirection() {
	// using vector to set all the directions that the bishop can move
	mdirection.push_back({ 1,1 });
	mdirection.push_back({ -1,1 });
	mdirection.push_back({ 1,-1 });
	mdirection.push_back({ -1,-1 });
}
