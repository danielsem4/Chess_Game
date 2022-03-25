#pragma once

// PieceSelect dialog

class PieceSelect : public CDialogEx {
	DECLARE_DYNAMIC(PieceSelect)

public:
	PieceSelect(CWnd* pParent = nullptr, int iindicator = 0); // standard constructor
	virtual ~PieceSelect();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int mselect;
	int mindicator;
	BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	afx_msg void OnBnClickedTheJoker();
};
