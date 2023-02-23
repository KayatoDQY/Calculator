#pragma once
#include <afxdialogex.h>
// TestDlg.h : header file
//
#pragma once
// CTestDlg dialog
class CTestDlg : public CDialogEx
{
	// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor
	// Dialog Data
	enum { IDD = IDD_TEST_DIALOG };
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
		CBrush m_brMine;
	COLORREF m_BlackColor;
	COLORREF m_TextColor;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};