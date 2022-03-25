
#include "pch.h"
#include "piece.h"

// checks if the move was on the board and if it match the piece move allowed
bool Piece::isLeagle(Piece* iboard[8][8], COORD ifrom, COORD ito)
{
	COORD temp;
	for (int i = 0; i < numDirection(); i++)
	{
		for (int j = 1; j <= this->mdistance; j++)
		{
			temp = getNewLocation(ifrom, i, j);
			if (temp.X < 0 || temp.X >= BOARD_SIZE || temp.Y < 0 || temp.Y >= BOARD_SIZE)//if the piece is out of the board
				break;
			if (iboard[temp.X][temp.Y] != nullptr && this->mplayer == iboard[temp.X][temp.Y]->mplayer)//if there is a player in the way
				break;
			if (temp == ito)//if the move is valid
				return true;
			if (iboard[temp.X][temp.Y] != nullptr)
				break;
		}
	}
	return false;
}
