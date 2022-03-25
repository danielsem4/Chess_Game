#include "pch.h"
#include "Board.h"

IMPLEMENT_SERIAL(Board, CObject, 0);

#pragma region constructor and distructor

Board::Board()
{
	iturn = 1;
	setIndex();
	cleanBoard();
	setNewBoard(0);
}

Board::Board(int iindex)
{
	iturn = 1;
	setNewBoard(iindex);
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->mmat[i][j] != nullptr)
				delete[]this->mmat[i][j];
		}
	}
}
#pragma endregion

//Function that returns the King location
COORD Board::findKing(int iplayer)
{
	COORD location = { -1,-1 };
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (mmat[i][j] != nullptr && mmat[i][j]->getIcon() == IKing && mmat[i][j]->getPlayer() == iplayer)
				return { (SHORT)i,(SHORT)j };
}

// Function that get the squre from the file and returns if ther is a piece on it or no
void Board::loadFromList(int ilist[BOARD_SIZE][BOARD_SIZE][2])
{
	cleanBoard();
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (ilist[i][j][0])
			{
			case IPawn:mmat[i][j] = new Pawn(ilist[i][j][1]);
				break;
			case IBishop: mmat[i][j] = new Bishop(ilist[i][j][1]);
				break;
			case IKnight: mmat[i][j] = new Knight(ilist[i][j][1]);
				break;
			case IRooks: mmat[i][j] = new Rook(ilist[i][j][1]);
				break;
			case IKing: mmat[i][j] = new King(ilist[i][j][1]);
				break;
			case IQueen: mmat[i][j] = new Queen(ilist[i][j][1]);
				break;
			case IJoker: mmat[i][j] = new Joker(ilist[i][j][1]);
				break;
			default:
				mmat[i][j] = nullptr;
				break;
			}
		}
	}
}

// The function get the map number by i and searching for the map in the files and loading from the file
void Board::setNewBoard(int i)
{
	CFile file;
	if (i == 0)
	{
		iturn = 1;
		file.Open(L"Default_map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 1)
	{
		file.Open(L"Firs_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 2)
	{
		file.Open(L"Second_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 3)
	{
		file.Open(L"Third_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 4)
	{
		file.Open(L"Fourth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 5)
	{
		file.Open(L"Fifth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 6)
	{
		file.Open(L"Sixth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 7)
	{
		file.Open(L"Seventh_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 8)
	{
		file.Open(L"Eighth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 9)
	{
		file.Open(L"Ninth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 10)
	{
		file.Open(L"Tenth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 11)
	{
		file.Open(L"Eleventh_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	else if (i == 12)
	{
		file.Open(L"Twelfth_Map", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		serializa(ar);
		ar.Close();
	}
	file.Close();
}

//the Function cleans the board from pieces
void Board::cleanBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			mmat[i][j] = nullptr;
}

//the function delete the pawn who got to the end of the map and change him by:Rook/Bishop/Knight/Queen (the player choose)
void Board::changePiece(COORD iloc, int inewPoint)
{
	int player = (*this)[iloc]->getPlayer();
	delete[](*this)[iloc];
	switch (inewPoint)
	{
	case 0: (*this)[iloc] = new Rook(player); break;
	case 1: (*this)[iloc] = new Bishop(player); break;
	case 2: (*this)[iloc] = new Knight(player); break;
	case 3: (*this)[iloc] = new Queen(player); break;
	case 4: (*this)[iloc] = new Joker(player); break;
	default:
		break;
	}
}

//the function check if the king is under attack by serch through the board and find all the pieces legal moves if the king is on one of the lines
bool Board::checkChess(int iplayer)
{
	COORD location = findKing(iplayer);
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (mmat[i][j] != nullptr && mmat[i][j]->getPlayer() != iplayer)
			{
				COORD temp = { (SHORT)i,(SHORT)j };
				if ((*this)[temp]->isLeagle(this->mmat, temp, location))
					return true;
			}
	return false;
}

//the function checks if the new location of the piece is legal if yes the loc will be updated else wont
bool Board::movePiece(COORD ifrom, COORD ito)
{
	Piece* toPtr = (*this)[ito];
	Piece* fromPtr = (*this)[ifrom];
	if ((*this)[ifrom]->isLeagle(this->mmat, ifrom, ito))
	{
		(*this)[ito] = (*this)[ifrom];
		(*this)[ifrom] = nullptr;
		if (checkChess((*this)[ito]->getPlayer())) {
			(*this)[ito] = toPtr;
			(*this)[ifrom] = fromPtr;
			MessageBox(NULL, L"your king is under attack", L"invalid move", MB_ICONWARNING);
			return false;
		}
		if (fromPtr != nullptr)
			delete[]toPtr;
		return true;
	}
	MessageBox(NULL, L"invalid move", L"pls try again", MB_ICONWARNING);
	return false;
}

//the function is storing in files and loading from files
void Board::serializa(CArchive& iar)
{
	if (iar.IsStoring()) {
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (mmat[i][j] != nullptr)
				{
					iar << (int)mmat[i][j]->getIcon();
					iar << mmat[i][j]->getPlayer();
				}
				else
				{
					iar << 0;
					iar << 0;
				}
			}
		}
	}
	else {
		int listToLoad[BOARD_SIZE][BOARD_SIZE][2];
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				iar >> listToLoad[i][j][0];
				iar >> listToLoad[i][j][1];
			}
		}
		loadFromList(listToLoad);
	}
}

// movving to the next\prev map 
void Board::levelUp(int ijump)
{
	if (this->mindex == 1 && ijump == -1)
		this->mindex = 1;

	else if (this->mindex == 11 && ijump == 1)
				this->mindex = 12;
	else
		this->mindex = (this->mindex + ijump) % this->mmaxLevel;

	this->setNewBoard(this->mindex);
}

// checks if the move that was courrent and solves the puzzle or no 
int Board::rightMove(int iindex)
{
	switch (iindex)
	{
	case 1:
		if (mmat[3][4] != nullptr && mmat[3][4]->getIcon() == IBishop) {
			return 1;
		}
		else
			return -1;
		break;
	case 2:
		if (mmat[0][7] != nullptr && mmat[0][7]->getIcon() == IRooks) {
			return 1;
		}
		else
			return -1;
		break;
	case 3:
		if (mmat[5][1] != nullptr && mmat[5][1]->getIcon() == IKnight) {
			return 1;
		}
		else
			return -1;
		break;
	case 4:
		if (mmat[2][1] != nullptr && mmat[2][1]->getIcon() == IPawn) {
			return 1;
		}
		else
			return -1;
		break;
	case 5:
		if (mmat[3][3] != nullptr && mmat[3][3]->getIcon() == IKnight) {
			return 1;
		}
		else
			return -1;
		break;
	case 6:
		if (mmat[7][0] != nullptr && mmat[7][0]->getIcon() == IQueen) {
			return 1;
		}
		else
			return -1;
		break;
	case 7:
		if (mmat[0][0] != nullptr && mmat[0][0]->getIcon() == IQueen) {
			return 1;
		}
		else
			return -1;
		break;
	case 8:
		if (mmat[2][4] != nullptr && mmat[2][4]->getIcon() == IPawn) {
			return 1;
		}
		else
			return -1;
		break;
	case 9:
		if (mmat[3][0] != nullptr && mmat[3][0]->getIcon() == IQueen&& getNumOfMove()==1) {
			mmat[5][1] = new King(0);
			mmat[4][0] = nullptr;
			setNumOfMove(2);
			return 0;
		}
		if (getNumOfMove() == 2) {
			if (mmat[4][3] != nullptr && mmat[4][3]->getIcon() == IKnight) {
				setNumOfMove(1);
				return 1;
			}
		}
			setNumOfMove(1);
			return -1;
			break;
	case 10:
		if (mmat[5][6] != nullptr && mmat[5][6]->getIcon() == IKnight && getNumOfMove() == 1) {
			mmat[6][7] = new King(1);
			mmat[7][7] = nullptr;
			setNumOfMove(2);
			return 0;
		}
		if (getNumOfMove() == 2) {
			if (mmat[7][5] != nullptr && mmat[7][5]->getIcon() == IKnight) {
				setNumOfMove(1);
				return 1;
			}
		}
		setNumOfMove(1);
		return -1;
		break;
	case 11:
		if (mmat[3][0] != nullptr && mmat[3][0]->getIcon() == IQueen && getNumOfMove() == 1) {
			mmat[3][0] = nullptr;
			mmat[3][0] = new King(0);
			mmat[4][0] = nullptr;
			setNumOfMove(getNumOfMove() + 1);
			return 0;
		}
		if (getNumOfMove() == 2)
		{
			if (mmat[5][0] != nullptr && mmat[5][0]->getIcon() == IRooks) {
				setNumOfMove(1);
				return 1;
			}
		}
		setNumOfMove(1);
		return -1;
		break;

	case 12:
		if (mmat[7][1] != nullptr && mmat[7][1]->getIcon() == IPawn && getNumOfMove() == 1) {
			mmat[5][0] = new King(0);
			mmat[6][0] = nullptr;
			setNumOfMove(2);
			return 0;
		}
		if (getNumOfMove()==2) {
			if (mmat[7][0] != nullptr && mmat[7][0]->getIcon() == IQueen) {
					setNumOfMove(1);
					return 1;
			}
		}
		setNumOfMove(1);
		return -1;
		break;

	default:
		break;
	}
}
