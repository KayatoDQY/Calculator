#pragma once
#include <afxwin.h>
class CDrawEdit : public CEdit
{
	//DECLARE_DYNAMIC(CDrawEdit)

public:
	CDrawEdit();
	virtual ~CDrawEdit();
	void CDrawEdit::OnNcPaint();
protected:
	//DECLARE_MESSAGE_MAP()
};

