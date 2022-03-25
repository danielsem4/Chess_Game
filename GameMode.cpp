// GameMode.cpp : implementation file
//

#include "pch.h"
#include "chess.h"
#include "GameMode.h"
#include "afxdialogex.h"

CStatic* PHOTO;
// GameMode dialog

IMPLEMENT_DYNAMIC(GameMode, CDialogEx)

GameMode::GameMode(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

GameMode::~GameMode()
{
}

void GameMode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameMode, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &GameMode::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &GameMode::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_Twist, &GameMode::OnBnClickedTwist)
END_MESSAGE_MAP()


// GameMode message handlers


BOOL GameMode::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: Add extra initialization here
	PHOTO = (CStatic*)GetDlgItem(IDC_NEWPIC);
	CString STR;
	STR = CString(_T("GAME_MODE_PIC.bmp"));
	HBITMAP pic2 = (HBITMAP)LoadImage(NULL, STR, IMAGE_BITMAP, 590, 370, LR_LOADFROMFILE);
	PHOTO->SetBitmap(pic2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void GameMode::OnBnClickedButton2()
{
	mgame = 1;
	this->EndDialog(0);
}


void GameMode::OnBnClickedButton1()
{
	mgame = 0;
	this->EndDialog(0);
}


void GameMode::OnBnClickedTwist()
{
	MessageBox(NULL, L"Discover the secret of the mode", MB_ICONINFORMATION);
	mgame = 2;
	this->EndDialog(0);
}
