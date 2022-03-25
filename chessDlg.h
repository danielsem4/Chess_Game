
// chessDlg.h : header file
//

#pragma once


// CchessDlg dialog
class CchessDlg : public CDialogEx
{
// Construction
public:
	CchessDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHESS_DIALOG };
#endif

	bool isPressed;
	CPoint startP;
	CPoint endP;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRestart();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedNext();
	int level;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnEnChangeMap();
	afx_msg void OnBnClickedPuzzles();
	afx_msg void OnBnClickedGame();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedMode();
	afx_msg void OnBnClickedBoardcolor();
	afx_msg void OnBnClickedSave();
	CString mTurn;
	afx_msg void OnBnClickedMapArea();
};
