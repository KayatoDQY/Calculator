
// CalculatorDlg.h: 头文件
//

#pragma once
#include "CRoundButton.h"
#include "CDrawEdit.h"

#include <Python.h>
#include <string>
// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
	// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;
	CBrush m_brush;
	COLORREF m_color, m_textcolor;
	CFont editFont;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	std::string  nowstr = "";
	PyObject* pModule = NULL;
	PyObject* pFunc = NULL; 
	PyObject* pParams = NULL; 
	PyObject* pResult = NULL;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CEdit outEDIT;

	CRoundButton _num7_ = { 7 };
	CRoundButton _num4_ = { 4 };
	CRoundButton _num1_ = { 1 };
	CRoundButton _num2_ = { 2 };
	CRoundButton _num5_ = { 5 };
	CRoundButton _num8_ = { 8 };
	CRoundButton _num9_ = { 9 };
	CRoundButton _num6_ = { 6 };
	CRoundButton _num3_ = { 3 };
	CRoundButton _num0_ = { 0 };
	CRoundButton _point_ = { 10 };

	CRoundButton _brackets1_ = {11};
	CRoundButton _brackets2_ = {12};
	CRoundButton _back_ = { 13 };

	CRoundButton _division_ = { 14 };
	CRoundButton _multi_ = { 15 };
	CRoundButton _sum_ = { 16 };
	CRoundButton _equal_ = { 17 };
	CRoundButton _subtra_ = { 18 };

	CRoundButton _ac_c_ = { 19 };
	CRoundButton _radical_ = { 20 };
	CRoundButton _ms_ = { 21 };
	CRoundButton _pi_ = { 22 };
	CRoundButton _tan_ = { 23 };
	CRoundButton _cos_ = { 24 };
	CRoundButton _sin_ = { 25 };
	CRoundButton _ln_ = { 26 };
	CRoundButton _ex_ = { 27 };
	CRoundButton _square_ = { 28 };
	CRoundButton _xrank_ = { 29 };
	CRoundButton _max_ = { 30 };
	CRoundButton _min_ = { 31 };
	CRoundButton _med_ = { 32 };
	CRoundButton _avg_ = { 33 };
	CRoundButton _sd_ = { 34 };
	CRoundButton _num_ = { 35 };
	CRoundButton _sigma_ = { 36 };
	CRoundButton _pai_ = { 37 };
	CRoundButton _mc_ = { 38 };

	CRoundButton _close_ = { 39 };
	CRoundButton _winmin_ = { 40 };
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton22();
};

