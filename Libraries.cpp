#include "pch.h"
#include "Libraries.h"

#pragma region Board and Pieces

COORD ConvLoc(COORD iloc, double ibloks) {
	iloc.X -= 15;
	iloc.Y -= 15;
	iloc.X /= ibloks;
	iloc.Y /= ibloks;
	return iloc;
}

COORD ReConvLoc(COORD iloc, double ibloks) {
	iloc.X *= ibloks;
	iloc.Y *= ibloks;
	iloc.X += 15;
	iloc.Y += 15;
	return iloc;
}
//checks if the location is on the board
bool validLoc(COORD it) {
	if (it.X < 0 || it.X > 7 || it.Y < 0 || it.Y > 7)
		return false;
	return true;
}
// Function that takes from the screen the size of the screen and the resulution and adapt the board to the scree
void GetDesktopResolution(double& ibloks, double& ibloksSize, double& ipieceSize, double& ipieceSenser)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	int horizontal = desktop.right;
	int vertical = desktop.bottom;
	int temp = horizontal + vertical;
	ibloks = temp / 40;
	ibloksSize = ibloks / 7;
	ipieceSize = ibloksSize - 4;
	ipieceSenser = temp / 700;
}

#pragma endregion

#pragma region operators

_COORD operator+(_COORD ia, _COORD ib) { return { ia.X + ib.X , ia.Y + ib.Y }; }

bool operator==(_COORD ia, _COORD ib) { return (ia.X == ib.X && ia.Y == ib.Y); }

_COORD operator*(_COORD ia, int ib) { return { ia.X * (SHORT)ib , ia.Y * (SHORT)ib }; }

#pragma endregion