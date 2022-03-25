#include "pch.h"
#include "Pawn.h"

//constractor
Pawn::Pawn(int iplayer)
{
	this->mplayer = iplayer;
	mdistance = 2;
	setDirection();
	micon = IPawn;
}

#pragma region pawn moves
//
bool Pawn::isLeagle(Piece* iboard[8][8], COORD ifrom, COORD ito)
{
	COORD temp;
	for (int i = 1; i <= this->mdistance; i++) {
		temp = getNewLocation(ifrom, 0, i);
		if (temp.X < 0 || temp.X >= BOARD_SIZE || temp.Y < 0 || temp.Y >= BOARD_SIZE)
			break;
		if (iboard[temp.X][temp.Y] != nullptr)
			break;
		if (temp == ito) {
			this->mdistance = 1;
			return true;
		}
	}
	//
	for (int j = 1; j < numDirection(); j++) {
		temp = getNewLocation(ifrom, j, 1);
		if (temp.X < 0 || temp.X >= BOARD_SIZE || temp.Y < 0 || temp.Y >= BOARD_SIZE);
		else if (iboard[temp.X][temp.Y] != nullptr && iboard[temp.X][temp.Y]->getPlayer() != this->mplayer && temp == ito) {
			mdistance = 1;
			return true;
		}
	}
	return false;
}
void Pawn::setDirection()
{
	// using vector to set all the directions that the Pawn can move

	int PD = getPlayer() * (-2) + 1;//check if he can move double step
	mdirection.push_back({ 0,(SHORT)(1 * PD) });
	mdirection.push_back({ 1,(SHORT)(1 * PD) });
	mdirection.push_back({ -1,(SHORT)(1 * PD) });
}
#pragma endregion


