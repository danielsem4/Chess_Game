#include "pch.h"
#include "Knight.h"

// constractor
Knight::Knight(int iplayer)
{
	this->mplayer = iplayer;
	setDirection();
	mdistance = 1;
	micon = IKnight;
}

void Knight::setDirection()
{
	// using vector to set all the directions that the Knight can move
	mdirection.push_back({ 2,1 });
	mdirection.push_back({ 2,-1 });
	mdirection.push_back({ -2,1 });
	mdirection.push_back({ -2,-1 });
	mdirection.push_back({ 1,2 });
	mdirection.push_back({ -1,2 });
	mdirection.push_back({ 1,-2 });
	mdirection.push_back({ -1,-2 });
}
