#include "pch.h"
#include "CDrawEdit.h"
void CDrawEdit::OnNcPaint()
{
	CRect rc;
	GetWindowRect(&rc);
	CRect rcWindow(0, 0, rc.Width(), rc.Height());

	CBrush brushFrame;
	brushFrame.CreateSolidBrush(RGB(255, 0, 0));

	CWindowDC dc(this);
	dc.FrameRect(&rcWindow, &brushFrame);
}
CDrawEdit::CDrawEdit() {
};
CDrawEdit::~CDrawEdit() {
};