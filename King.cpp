#include "pch.h"
#include "King.h"

King::King(int iplayer):Queen(iplayer)
{
	// the king is queen but can move only 1 squre 
	mdistance = 1;
	micon = IKing;
}
