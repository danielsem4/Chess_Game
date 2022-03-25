#include "pch.h"
#include "Joker.h"

Joker::Joker(int iplayer) :Queen(iplayer)
{
	this->mplayer = iplayer;
	setDirection();
	micon = IJoker;
}

void Joker::setDirection()
{
	// using vector to set all the directions that the Knight can move
	Queen::setDirection();
	mdirection.push_back({ 2,1 });
	mdirection.push_back({ 2,-1 });
	mdirection.push_back({ -2,1 });
	mdirection.push_back({ -2,-1 });
	mdirection.push_back({ 1,2 });
	mdirection.push_back({ -1,2 });
	mdirection.push_back({ 1,-2 });
	mdirection.push_back({ -1,-2 });
}