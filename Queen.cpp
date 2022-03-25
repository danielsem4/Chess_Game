#include "pch.h"
#include "Queen.h"

//constractor 
Queen::Queen(int iplayer)
{
	this->mplayer = iplayer;
	setDirection();
	micon = IQueen;
}

void Queen::setDirection()
{
	// using vector to set all the directions that the Queen can move
	mdirection.push_back({ 1,0 });
	mdirection.push_back({ -1,0 });
	mdirection.push_back({ 1,1 });
	mdirection.push_back({ 1,-1 });
	mdirection.push_back({ -1,1 });
	mdirection.push_back({ -1,-1 });
	mdirection.push_back({ 0,1 });
	mdirection.push_back({ 0,-1 });
}
