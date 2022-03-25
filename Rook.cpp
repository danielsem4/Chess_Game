#include "pch.h"
#include "Rook.h"

//constractor
Rook::Rook(int iplayer)
{
	this->mplayer = iplayer;
	setDirection();
	micon = IRooks;
}

void Rook::setDirection()
{
	// using vector to set all the directions that the Rook can move
	mdirection.push_back({ 1,0 });
	mdirection.push_back({ -1,0 });
	mdirection.push_back({ 0,1 });
	mdirection.push_back({ 0,-1 });
}
