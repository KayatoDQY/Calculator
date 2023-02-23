#pragma once
#include "afxwin.h"
class CRoundButton :
	public CButton
{
public:
	CRoundButton(const char a);
	~CRoundButton();
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
	char kind;
};