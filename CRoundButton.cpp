#include "pch.h"
#include "CRoundButton.h"

void CRoundButton::PreSubclassWindow()
{
	// TODO:  在此添加专用代码和/或调用基类
	ModifyStyle(0, BS_OWNERDRAW);
	CButton::PreSubclassWindow();
}
void CRoundButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  添加您的代码以绘制指定项
	CRect rct = lpDrawItemStruct->rcItem;

	CRgn coverrgn;
	coverrgn.CreateRectRgn(0, 0, rct.Width(), rct.Height());
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	int nSaveDC = pDC->SaveDC();
	CBrush backBrush;
	backBrush.CreateSolidBrush(RGB(0, 0, 0));
	pDC->FillRgn(&coverrgn, &backBrush);

	CRgn keyrgn;
	if (kind==39||kind==40) {
		keyrgn.CreateEllipticRgn(rct.CenterPoint().x - 11, rct.CenterPoint().y - 11, rct.CenterPoint().x + 11, rct.CenterPoint().y + 11);
	}
	else {
		keyrgn.CreateRoundRectRgn(rct.TopLeft().x, rct.TopLeft().y, rct.BottomRight().x, rct.BottomRight().y, min(rct.Width(), rct.Height()) / 2 + 15, min(rct.Width(), rct.Height()) / 2 + 15);
	}
	CBrush keyBrush;
	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		if (kind >=14&&kind<=18) {
			keyBrush.CreateSolidBrush(RGB(254, 254, 254));
			pDC->SetTextColor(RGB(239, 164, 62));
		}
		else if (kind >= 0 && kind <= 10 ) {
			keyBrush.CreateSolidBrush(RGB(254, 254, 254));
			pDC->SetTextColor(RGB(51, 51, 51));
		}
		else if (kind == 39) {
			keyBrush.CreateSolidBrush(RGB(150, 150, 150));
		}
		else if (kind == 40) {
			keyBrush.CreateSolidBrush(RGB(150, 150, 150));
			//pDC->SetTextColor(RGB(254, 254, 254));
		}
		else if (kind <= 38 && kind >= 19) {
			keyBrush.CreateSolidBrush(RGB(254, 254, 254));
			pDC->SetTextColor(RGB(33, 33, 33));
		}
		else if (kind <= 13 && kind >= 11) {
			keyBrush.CreateSolidBrush(RGB(33, 33, 33));
			pDC->SetTextColor(RGB(165, 165, 165));
		}
		else {
			keyBrush.CreateSolidBrush(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(0, 0, 0));
		}
	}
	else {
		if (kind >= 14 && kind <= 18) {
			keyBrush.CreateSolidBrush(RGB(239, 164, 62));
			pDC->SetTextColor(RGB(254, 254, 254));
		}
		else if (kind >= 0 && kind <= 10) {
			keyBrush.CreateSolidBrush(RGB(51, 51, 51));
			pDC->SetTextColor(RGB(254, 254, 254));
		}
		else if (kind == 39) {
			keyBrush.CreateSolidBrush(RGB(224, 75, 68));
			pDC->SetTextColor(RGB(254, 254, 254));
		}
		else if (kind == 40) {
			keyBrush.CreateSolidBrush(RGB(35, 199, 60));
			pDC->SetTextColor(RGB(254, 254, 254));
		}
		else if (kind <= 38 && kind >= 19) {
			keyBrush.CreateSolidBrush(RGB(33, 33, 33));
			pDC->SetTextColor(RGB(254, 254, 254));
		}
		else if (kind <= 13 && kind >= 11) {
			keyBrush.CreateSolidBrush(RGB(165, 165, 165));
			pDC->SetTextColor(RGB(33, 33, 33));
		}
		else {
			keyBrush.CreateSolidBrush(RGB(0, 0, 0));
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		
	}
	pDC->FillRgn(&keyrgn, &keyBrush);
	
	pDC->SetBkMode(TRANSPARENT);
	
	CString strText{};
	CFont font;
	//font.CreatePointFont(180, L"幼圆");//设置控件文字大小与字体
	font.CreateFont(
		30,                       // nHeight
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
	pDC->SelectObject(&font);
	GetWindowText(strText);
	pDC->DrawText(strText, rct, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDC->RestoreDC(nSaveDC);
}
CRoundButton::CRoundButton(const char a)
{
	kind = a;
}
CRoundButton::~CRoundButton()
{

}
