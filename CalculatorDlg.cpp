
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "CRoundButton.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <dwmapi.h>
#include <stdexcept>


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CCalculatorDlg 对话框
CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, outEDIT);
	DDX_Control(pDX, IDC_BUTTON1, _brackets1_);
	DDX_Control(pDX, IDC_BUTTON6, _brackets2_);
	DDX_Control(pDX, IDC_BUTTON11, _back_);
	DDX_Control(pDX, IDC_BUTTON16, _division_);
	DDX_Control(pDX, IDC_BUTTON22, _ac_c_);
	DDX_Control(pDX, IDC_BUTTON27, _radical_);
	DDX_Control(pDX, IDC_BUTTON32, _ms_);
	DDX_Control(pDX, IDC_BUTTON2, _num7_);
	DDX_Control(pDX, IDC_BUTTON3, _num4_);
	DDX_Control(pDX, IDC_BUTTON4, _num1_);
	DDX_Control(pDX, IDC_BUTTON9, _num2_);
	DDX_Control(pDX, IDC_BUTTON8, _num5_);
	DDX_Control(pDX, IDC_BUTTON7, _num8_);
	DDX_Control(pDX, IDC_BUTTON12, _num9_);
	DDX_Control(pDX, IDC_BUTTON13, _num6_);
	DDX_Control(pDX, IDC_BUTTON14, _num3_);
	DDX_Control(pDX, IDC_BUTTON5, _num0_);
	DDX_Control(pDX, IDC_BUTTON15, _point_);
	DDX_Control(pDX, IDC_BUTTON17, _multi_);
	DDX_Control(pDX, IDC_BUTTON18, _subtra_);
	DDX_Control(pDX, IDC_BUTTON19, _sum_);
	DDX_Control(pDX, IDC_BUTTON20, _equal_);
	DDX_Control(pDX, IDC_BUTTON26, _pi_);
	DDX_Control(pDX, IDC_BUTTON25, _tan_);
	DDX_Control(pDX, IDC_BUTTON24, _cos_);
	DDX_Control(pDX, IDC_BUTTON23, _sin_);
	DDX_Control(pDX, IDC_BUTTON28, _square_);
	DDX_Control(pDX, IDC_BUTTON29, _ln_);
	DDX_Control(pDX, IDC_BUTTON30, _ex_);
	DDX_Control(pDX, IDC_BUTTON31, _xrank_);
	DDX_Control(pDX, IDC_BUTTON33, _max_);
	DDX_Control(pDX, IDC_BUTTON38, _min_);
	DDX_Control(pDX, IDC_BUTTON34, _med_);
	DDX_Control(pDX, IDC_BUTTON39, _avg_);
	DDX_Control(pDX, IDC_BUTTON35, _sd_);
	DDX_Control(pDX, IDC_BUTTON40, _num_);
	DDX_Control(pDX, IDC_BUTTON36, _sigma_);
	DDX_Control(pDX, IDC_BUTTON41, _pai_);
	DDX_Control(pDX, IDC_BUTTON10, _close_);
	DDX_Control(pDX, IDC_BUTTON21, _winmin_);
	DDX_Control(pDX, IDC_BUTTON37, _mc_);
}


BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalculatorDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalculatorDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CCalculatorDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON27, &CCalculatorDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CCalculatorDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CCalculatorDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CCalculatorDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CCalculatorDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON32, &CCalculatorDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON37, &CCalculatorDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON33, &CCalculatorDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON38, &CCalculatorDlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON34, &CCalculatorDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON39, &CCalculatorDlg::OnBnClickedButton39)
	ON_BN_CLICKED(IDC_BUTTON35, &CCalculatorDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON40, &CCalculatorDlg::OnBnClickedButton40)
	ON_BN_CLICKED(IDC_BUTTON36, &CCalculatorDlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON41, &CCalculatorDlg::OnBnClickedButton41)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序
BOOL CCalculatorDlg::OnInitDialog()
{
	Py_SetPythonHome((wchar_t*)L"C:\\Users\\20826\\.conda\\envs\\cplusplus");
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(r'C:\\Users\\20826\\Documents\\GitHub\\Calculator')");
	pModule = PyImport_ImportModule("src");
	pFunc = PyObject_GetAttrString(pModule, "Calculate");
	CDialogEx::OnInitDialog();
	editFont.CreateFont(
		50,                       // nHeight
		0,                        // nWidth
		0,                        // nEscapement
		0,                        // nOrientation
		FW_BOLD,                // nWeight
		FALSE,                    // bItalic
		FALSE,                    // bUnderline
		0,                        // cStrikeOut
		ANSI_CHARSET,             // nCharSet
		OUT_DEFAULT_PRECIS,       // nOutPrecision
		CLIP_DEFAULT_PRECIS,      // nClipPrecision
		DEFAULT_QUALITY,          // nQuality
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
		_T("微软雅黑"));            // lpszFacename
	outEDIT.SetFont(&editFont);
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// when the application's main window is not a dialog  
	SetIcon(m_hIcon, TRUE);    // Set big icon  
	SetIcon(m_hIcon, FALSE);   // Set small icon  

	m_color = RGB(0,0,0);                    
	m_textcolor = RGB(255, 255, 255);                
	m_brush.CreateSolidBrush(m_color); 
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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


// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CCalculatorDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(rect);
	CRgn myrgn1;
	myrgn1.CreateRoundRectRgn(0, 0, rect.Width(), rect.Height(), 35, 35);
	CBrush frameBrush, bgbrush;
	bgbrush.CreateSolidBrush(RGB(0, 0, 0));
	frameBrush.CreateSolidBrush(RGB(51, 51, 51));
	pDC->FillRgn(&myrgn1, &bgbrush);
	pDC->FrameRgn(&myrgn1, &frameBrush, 1, 1);
	return true;
	return CDialogEx::OnEraseBkgnd(pDC);
}


LRESULT CCalculatorDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT nHitTest = CDialog::OnNcHitTest(point);
	return (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
	return CDialogEx::OnNcHitTest(point);
}


HBRUSH CCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	switch (nCtlColor)
	{
	case CTLCOLOR_EDIT:
	case CTLCOLOR_STATIC:
		switch (pWnd->GetDlgCtrlID())
		{
		case IDC_EDIT1:
			pDC->SetBkColor(m_color);
			pDC->SetTextColor(m_textcolor);
			pDC->SetTextAlign(TA_RIGHT & TA_BOTTOM & TA_UPDATECP);
			hbr = (HBRUSH)m_brush;
			break;
		default:
			hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
			break;
		}
		break;
	}
	return hbr;
}


void CCalculatorDlg::OnBnClickedButton10()
{
	CDialogEx::OnOK();
}


void CCalculatorDlg::OnBnClickedButton21()
{
	CWnd::ShowWindow(SW_MINIMIZE);
}


void CCalculatorDlg::OnBnClickedButton1()
{
	nowstr += "(";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	nowstr += ")";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	nowstr += "7";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	nowstr += "4";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	nowstr += "1";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	nowstr += "0";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	nowstr += "2";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	nowstr += "5";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	nowstr += "8";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton12()
{
	nowstr += "9";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton13()
{
	nowstr += "6";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton14()
{
	nowstr += "3";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton15()
{
	nowstr += ".";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton16()
{
	nowstr += "/";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton17()
{
	nowstr += "*";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton18()
{
	nowstr += "-";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton19()
{
	nowstr += "+";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton20()
{
	char* p = (char*)nowstr.data();
	pParams = Py_BuildValue("(s)",p);
	pResult = PyObject_CallObject(pFunc, pParams);
	char *res= NULL;
	PyArg_Parse(pResult, "s", &res);
	nowstr =res;
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton23()
{
	nowstr += "sin(";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton24()
{
	nowstr += "cos(";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton25()
{
	nowstr += "tan(";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton26()
{
	nowstr += "pi";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton11()
{
	nowstr=processString(nowstr);
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


std::string CCalculatorDlg::processString(const std::string& str) {
	std::string result = str;
	std::string specials[] = { "sin(", "cos(", "tan(", "pi", "#2", "^2", "ln(", "e^(","Expression Error" };
	for (const std::string& s : specials) {
		if (result.size() >= s.size() && result.substr(result.size() - s.size()) == s) {
			result.erase(result.size() - s.size(), s.size());
			return result;
		}
	}
	result.pop_back();
	return result;
}

void CCalculatorDlg::OnBnClickedButton22()
{
	nowstr = "";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton27()
{
	nowstr += "#2";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton28()
{
	nowstr += "^2";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton29()
{
	nowstr += "ln(";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton30()
{
	nowstr += "e^(";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton31()
{
	nowstr += "!";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton32()
{
	try {
		double dd=stringToDouble(nowstr);
		num.add(dd);
	}
	catch(std::invalid_argument&) {
		nowstr = "Please confirm this is only a number";
	}
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


double CCalculatorDlg::stringToDouble(const std::string& str) {
	bool hasDecimal = false;
	for (char c : str) {
		if (!isdigit(c) && c != '.') {
			throw std::invalid_argument("Please confirm this is only a number");
		}
		if (c == '.' && hasDecimal) { 
			throw std::invalid_argument("Please confirm this is only a number");
		}
		if (c == '.') {
			hasDecimal = true;
		}
	}
	return std::stod(str);
}


void CCalculatorDlg::OnBnClickedButton37()
{
	num.clear();
	nowstr = "";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton33()
{
	double num_= num.get_max();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton38()
{
	double num_ = num.get_min();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton34()
{
	double num_ = num.get_median();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton39()
{
	double num_ = num.get_average();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton35()
{
	double num_ = num.get_stddev();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton40()
{
	double num_ = num.get_size();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton36()
{
	double num_ = num.get_sum();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton41()
{
	double num_ = num.get_product();
	if (num_ != NAN)
		nowstr = std::to_string(num_);
	else
		nowstr = "Error no num in vector";
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}
