
// chessDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "chess.h"
#include "chessDlg.h"
#include "afxdialogex.h"
#include "board.h"
#include "Libraries.h"
#include"PieceSelect.h"
#include "GameMode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

// objects for the board and pieces move
Board board;
COORD from;
COORD to;

static int color = 0; // control the color of the board  
static bool indicator = false; // check if its on puzzle mode and indicator for mat in 2 
static int theMode=0;// control on the game mode
CStatic* Picture;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CchessDlg dialog



CchessDlg::CchessDlg(CWnd* pParent):CDialogEx(IDD_CHESS_DIALOG, pParent), level(0)
, mTurn(_T("White play"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CchessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Map, level);
	DDX_Text(pDX, IDC_TURNS, mTurn);
}

BEGIN_MESSAGE_MAP(CchessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Restart, &CchessDlg::OnBnClickedRestart)
	ON_BN_CLICKED(Back, &CchessDlg::OnBnClickedBack)
	ON_BN_CLICKED(Next, &CchessDlg::OnBnClickedNext)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CchessDlg::OnBnClickedButton1)
	
	ON_EN_CHANGE(Map, &CchessDlg::OnEnChangeMap)
	ON_BN_CLICKED(The_Puzzles, &CchessDlg::OnBnClickedPuzzles)
	ON_BN_CLICKED(Default_Game, &CchessDlg::OnBnClickedGame)
	ON_BN_CLICKED(IDC_Exit, &CchessDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_Mode, &CchessDlg::OnBnClickedMode)
	ON_BN_CLICKED(IDC_BoardColor, &CchessDlg::OnBnClickedBoardcolor)
	ON_BN_CLICKED(IDC_SAVE, &CchessDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_Map_Area, &CchessDlg::OnBnClickedMapArea)
END_MESSAGE_MAP()


// CchessDlg message handlers

BOOL CchessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	Picture = (CStatic*)GetDlgItem(IDC_PICTURE);
	CString str;
	/*str = CString(_T("KingBackGround.bmp"));*/
	str = CString(_T("background.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 520, 670, LR_LOADFROMFILE);
	Picture->SetBitmap(pic1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CchessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

double bloks;
void CchessDlg::OnPaint()
{
	int temp = board.rightMove(board.getIndex());
	double bloks_size = 0;
	double piece_size = 0;
	double piece_sener = 0;
	GetDesktopResolution(bloks, bloks_size, piece_size, piece_sener);
	// Function that take from the screan the Resolution and adapt the map to the screen size
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CFont font;
	font.CreatePointFont(bloks * bloks_size, _T("MS Gothic"));
	CFont* oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	CString string;

	string = _T("■");// the squre's of the chess board (String)

	// Drawing the chess board
		
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				switch (color)
				{
				case 0:
					dc.SetTextColor((i + j) % 2 ? RGB(224, 224, 224) : RGB(128, 128, 129));
					break;
				case 1:
					dc.SetTextColor((i + j) % 2 ? RGB(224, 224, 224) : RGB(153, 76, 0));
					break;
				case 2:
					dc.SetTextColor((i + j) % 2 ? RGB(224, 224, 224) : RGB(0, 205, 0));
					break;
				case 3:
					dc.SetTextColor((i + j) % 2 ? RGB(224, 224, 224) : RGB(51, 51, 255));
					break;
				case 4:
					dc.SetTextColor((i + j) % 2 ? RGB(224, 224, 224) : RGB(255, 102, 102));
					break;
				case 5:
					dc.SetTextColor((i + j) % 2 ? RGB(128, 128, 128) : RGB(51, 255, 255));
					break;
				case 6:
					dc.SetTextColor((i + j) % 2 ? RGB(224, 224, 224) : RGB(255, 51, 153));
					break;
				case 7:
					dc.SetTextColor((i + j) % 2 ? RGB(0, 100, 255) : RGB(102, 255, 173));
					break;
				case 8:
					dc.SetTextColor((i + j) % 2 ? RGB(255, 75, 0) : RGB(204, 153, 255));
					break;
				default:
					break;
				}
				dc.DrawText(string, &rect, DT_VCENTER);
				rect.OffsetRect(bloks, 0);

			}
			rect.OffsetRect(-8 * bloks, bloks);
		}
		GetClientRect(&rect);
		rect.OffsetRect(bloks / piece_sener, bloks / piece_sener);
		font.DeleteObject();
		font.CreatePointFont(bloks * piece_size, _T("MS Gothic"));
		dc.SelectObject(&font);

		// find the pieces on the board and draw them
		for (int j = 0; j < 8; j++)
			{
				for (int i = 0; i < 8; i++)
				{
					COORD loc = { (SHORT)i,(SHORT)j };
					wchar_t s = board[loc] != nullptr ? board[loc]->getIcon() + 6 : L' ';
					string = s;
					int p = board[loc] != nullptr ? board[loc]->getPlayer() : 0;
					dc.SetTextColor(p ? RGB(255, 255, 255) : RGB(0, 0, 0));
					dc.DrawText(string, &rect, DT_VCENTER);
					string = board[loc] != nullptr ? board[loc]->getIcon() : L' ';
					dc.SetTextColor(p ? RGB(0, 0, 0) : RGB(0, 0, 0));
					dc.DrawText(string, &rect, DT_VCENTER);
					rect.OffsetRect(bloks, 0);
				}
				rect.OffsetRect(-8 * bloks, bloks);
			}
		if (indicator != false) {
			switch (temp)
			{
			case 1:
				MessageBox(NULL, L"Great job Moving to the next map (:", MB_ICONMASK);
				OnBnClickedNext();
				break;
			case -1:
				MessageBox(NULL, L"Wrong Move Pls try again from the beginning ):", MB_ICONEXCLAMATION);
				UpdateData(true);
				board.cleanBoard();
				board.setNewBoard(level);
				Invalidate();
				UpdateData(false);
				break;
			default:
				MessageBox(NULL, L"Great job what is the next move ? (:", MB_ICONQUESTION);
				level == 10 ? mTurn = "Black play" : mTurn = "White play";
				break;
			}
		}
		indicator = false;
	dc.SelectObject(oldFont);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CchessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//The Last Save Button
void CchessDlg::OnBnClickedRestart()
{
	UpdateData(true);
	CFile file;
	file.Open(L"Last_Save", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	board.serializa(ar);
	ar.Close();
	file.Close();
	MessageBox(NULL, L"The last map you played (:");
	Invalidate();
	UpdateData(false);
}

// Back 1 map Button
void CchessDlg::OnBnClickedBack()
{
	if (level > 0) {
		UpdateData(true);
		if (level > 1)
			level -= 1;
		(level == 2 || level == 11) ? mTurn = "Black move" : mTurn = "White move";
		board.cleanBoard();
		board.levelUp(-1);
		Invalidate();
		UpdateData(false);
	}
}

// Next 1 map Button
void CchessDlg::OnBnClickedNext()
{
	if (level > 0) {
		UpdateData(true);
		if (level == 12)
			level = 1;
		else
			level += 1;
		(level == 2 || level == 10) ? mTurn = "Black move" : mTurn = "White move";
		board.cleanBoard();
		board.levelUp(1);
		Invalidate();
		UpdateData(false);
	}
}

// Indicate Click Down on the mouse
void CchessDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	startP = point;
	isPressed = true;
	CDialog::OnLButtonDown(nFlags, point);
	from = ConvLoc({ (SHORT)startP.x,(SHORT)startP.y }, bloks);
}

// Indicate Click Up on the mouse
void CchessDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(board[from] != nullptr){
	if (isPressed)
	{
		endP = point;
		isPressed = false;
		level > 0 ? indicator = true : indicator = false;
	}
	if (level == 0)
	{
		if (board.getTurn() != board[from]->getPlayer())
		{
			MessageBox(NULL, L"its not your turn wait till the second player will play", MB_ICONEXCLAMATION);
			return;
		}
	}
		CDialog::OnLButtonUp(nFlags, point);
		to = ConvLoc({ (SHORT)endP.x,(SHORT)endP.y }, bloks);
		if ((board[from] != nullptr /*&& board[from]->getPlayer() == board.getTurn()*/))
		{
			if (validLoc(to) && validLoc(from)) {
				if (board.movePiece(from, to)) {
					if ((to.Y == 0 || to.Y == 7) && (board[to]->getIcon() == IPawn))
					{
						PieceSelect dlg(NULL,theMode);// the "theMode" control on the mode of the game
						dlg.DoModal();
						board.changePiece(to, dlg.mselect);
					}
					board.getTurn() = (board.getTurn() + 1) % 2;
					Invalidate();
					mTurn = board.getTurn() ? L"White move" : L"Black move";
					/*step_counter = board.getTurn();*/
					UpdateData(false);
				}
				from = { -1,-1 };
				to = { -1,-1 };
			}
		}
	}
	if (theMode == 2)
		OnBnClickedBoardcolor();
}

// Restart Button 
void CchessDlg::OnBnClickedButton1()
{
	UpdateData(true);
	level = 0;
	theMode = 0;
	board.setIndex();
	board.setNewBoard(level);
	Invalidate();
	UpdateData(false);
}

// The Map Number you play 
void CchessDlg::OnEnChangeMap()
{
	
}

// The puzzle Area
void CchessDlg::OnBnClickedPuzzles()
{
	OnBnClickedButton1();
}

// the Default Area
void CchessDlg::OnBnClickedGame()
{
	UpdateData(true);
	level = 0;
	board.setIndex();
	board.setNewBoard(level);
	Invalidate();
	UpdateData(false);
}
// the Maps Area
void CchessDlg::OnBnClickedMapArea()
{
	UpdateData(true);
	level = 1;
	board.setIndex();
	board.setNewBoard(level);
	Invalidate();
	UpdateData(false);
}

// choose the mode you want to play
void CchessDlg::OnBnClickedMode()
{
	GameMode mode;
	mode.DoModal();
	theMode = mode.mgame;
	mode.mgame == 1 ? OnBnClickedMapArea() : OnBnClickedGame();
}

//play with the board color
void CchessDlg::OnBnClickedBoardcolor()
{
	color = (color + 1) % 9;
	Invalidate();
	UpdateData(false);
}

//save 
void CchessDlg::OnBnClickedSave()
{
	CFile file;
	file.Open(L"Last_Save", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	board.serializa(ar);
	ar.Close();
}

// exit and ask if save before you exit in the Default game
void CchessDlg::OnBnClickedExit()
{
	if (theMode == 0)
	{
		switch (MessageBox(L"Do you want to save before Exit the game ?", L"Exit", MB_YESNOCANCEL | MB_ICONQUESTION))
		{
		case IDYES:
			OnBnClickedSave();
		case IDNO:
			this->EndDialog(0);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (MessageBox(L"Do you want to Exit the game ?", L"Exit", MB_YESNOCANCEL))
		{
		case IDYES:
			this->EndDialog(0);
		default:
			break;
		}
	}

}