#pragma once


// GameMode dialog

class GameMode : public CDialogEx
{
	DECLARE_DYNAMIC(GameMode)

public:
	GameMode(CWnd* pParent = nullptr);   // standard constructor
	virtual ~GameMode();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int mgame;
	BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedTwist();
};
