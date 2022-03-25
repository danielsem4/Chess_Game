// PieceSelect.cpp : implementation file
//

#include "pch.h"
#include "chess.h"
#include "PieceSelect.h"
#include "afxdialogex.h"

CStatic* Pic;
// PieceSelect dialog

IMPLEMENT_DYNAMIC(PieceSelect, CDialogEx)

PieceSelect::PieceSelect(CWnd* pParent /*=nullptr*/,int iindicator)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	mindicator = iindicator;
}

PieceSelect::~PieceSelect()
{
}

void PieceSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PieceSelect, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PieceSelect::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &PieceSelect::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &PieceSelect::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &PieceSelect::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_The_Joker, &PieceSelect::OnBnClickedTheJoker)
END_MESSAGE_MAP()


// PieceSelect message handlers

BOOL PieceSelect::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: Add extra initialization here
	Pic = (CStatic*)GetDlgItem(IDC_PIC);
	CString STR;
	STR = CString(_T("kingBackGround.bmp"));
	HBITMAP pic2 = (HBITMAP)LoadImage(NULL, STR, IMAGE_BITMAP, 520, 370, LR_LOADFROMFILE);
	Pic->SetBitmap(pic2);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//Queen option
void PieceSelect::OnBnClickedButton1()
{
	mselect = 3;
	this->EndDialog(0);
}
//Rook option
void PieceSelect::OnBnClickedButton2()
{
	mselect = 0;
	this->EndDialog(0);
}
//Bishop option
void PieceSelect::OnBnClickedButton3()
{
	mselect = 1;
	this->EndDialog(0);
}
//Knight option
void PieceSelect::OnBnClickedButton4()
{
	mselect = 2;
	this->EndDialog(0);
}

void PieceSelect::OnBnClickedTheJoker()
{
	if (mindicator == 2)
	{
		mselect = 4;
		this->EndDialog(0);
	}
	else
		MessageBox(NULL, L"Access denied. Change mode", MB_ICONEXCLAMATION);
}
