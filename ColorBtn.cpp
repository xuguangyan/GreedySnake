// ColorBtn.cpp : implementation file
//

#include "stdafx.h"
#include "ColorBtn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorBtn

CColorBtn::CColorBtn()
{
	m_bMouseOn=false;
	m_bBkColor=true;
	m_nCursor=32649;


	m_backColor=m_backColorFocus=m_backColorSelected=m_backColorDisabled=GetSysColor(COLOR_3DFACE);
	m_foreColor=m_foreColorFocus=m_foreColorSelected=GetSysColor(COLOR_BTNTEXT);
	m_foreColorDisabled=GetSysColor(COLOR_3DHIGHLIGHT);
}

CColorBtn::~CColorBtn()
{
}


BEGIN_MESSAGE_MAP(CColorBtn, CButton)
	//{{AFX_MSG_MAP(CColorBtn)
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorBtn message handlers
BOOL CColorBtn::Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	m_nID=nID;
	m_pWnd=pParentWnd;
	return CButton::Create(lpszCaption,dwStyle,rect,pParentWnd,nID);
}

BOOL CColorBtn::AutoLoad(UINT nID, CWnd* pParent)
{
	m_nID=nID;
	m_pWnd=pParent;
	CButton* pBtn=(CButton *)pParent->GetDlgItem(nID);
	
	CRect rect;
	pBtn->GetClientRect(&rect);
	pBtn->ClientToScreen(&rect);
	pParent->ScreenToClient(&rect);

	CString str;
	pBtn->GetWindowText(str);
	pBtn->ShowWindow(SW_HIDE);

	return CButton::Create(str, WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, rect, pParent, nID);
}

void CColorBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);//获取一个CDC指针
	CRect rect(lpDrawItemStruct->rcItem);//定义按钮区域并初始化
	UINT state = lpDrawItemStruct->itemState;//初始化按钮状态

	//设置背景模式
	pDC->SetBkMode(TRANSPARENT);
	CString strText;
	GetWindowText(strText);

	CBrush brush;
	CBitmap bitmap;
	CDC dc;
	dc.CreateCompatibleDC(pDC);

	if (state & ODS_DISABLED)//按钮置灰
	{
		if(m_bBkColor)
		{
			brush.CreateSolidBrush(m_backColorDisabled);
			pDC->FillRect(rect,&brush);
		}
		else
		{
			if(bitmap.LoadBitmap(m_backgroundDisabled))
			{
				dc.SelectObject(&bitmap);
				pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);
			}
			else
			{
				brush.CreateSolidBrush(GetSysColor(COLOR_3DFACE));
				pDC->FillRect(rect,&brush);
			}
		}
		pDC->Draw3dRect(rect,GetSysColor(COLOR_3DHILIGHT),GetSysColor(COLOR_3DSHADOW));

		CSize sz = pDC->GetTextExtent(strText);
		int x = rect.left + (rect.Width() - sz.cx)/2;
		int y = rect.top + (rect.Height() - sz.cy)/2;

		rect.top += 2;
		rect.left += 2;
		pDC->SetTextColor(m_foreColorDisabled);
		pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		rect.top -= 2;
		rect.left -= 2;
		pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT));
		pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else
	{
		if (m_bMouseOn)//光标在按钮上
		{
			if (state & ODS_SELECTED)//按下
			{
				if(m_bBkColor)
				{
					brush.CreateSolidBrush(m_backColorSelected);
					pDC->FillRect(rect,&brush);
				}
				else
				{
					if(bitmap.LoadBitmap(m_backgroundSelected))
					{
						dc.SelectObject(&bitmap);
						pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);
					}
					else
					{
						brush.CreateSolidBrush(GetSysColor(COLOR_3DFACE));
						pDC->FillRect(rect,&brush);
					}
				}
				pDC->Draw3dRect(rect,GetSysColor(COLOR_3DSHADOW), GetSysColor(COLOR_3DHILIGHT));
				pDC->SetTextColor(m_foreColorSelected);
			}
			else//未按下
			{
				if(m_bBkColor)
				{
					brush.CreateSolidBrush(m_backColorFocus);
					pDC->FillRect(rect,&brush);
				}
				else
				{
					if(bitmap.LoadBitmap(m_backgroundFocus))
					{
						dc.SelectObject(&bitmap);
						pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);
					}
					else
					{
						brush.CreateSolidBrush(GetSysColor(COLOR_3DFACE));
						pDC->FillRect(rect,&brush);
					}
				}
				pDC->Draw3dRect(rect,GetSysColor(COLOR_3DHILIGHT),GetSysColor(COLOR_3DSHADOW));
				pDC->SetTextColor(m_foreColorFocus);
			}
		}
		else//光标不在按钮上
		{
			if(m_bBkColor)
			{
				brush.CreateSolidBrush(m_backColor);
				pDC->FillRect(rect,&brush);
			}
			else
			{
				
				if(bitmap.LoadBitmap(m_background))
				{
					dc.SelectObject(&bitmap);
					pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);
				}
				else
				{
					brush.CreateSolidBrush(GetSysColor(COLOR_3DFACE));
					pDC->FillRect(rect,&brush);
				}
			}
			pDC->Draw3dRect(rect,GetSysColor(COLOR_3DHILIGHT),GetSysColor(COLOR_3DSHADOW));
			pDC->SetTextColor(m_foreColor);
		}
		pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}

void CColorBtn::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bMouseOn=true;
	Invalidate();

	TRACKMOUSEEVENT tme;   
	tme.cbSize=sizeof(tme);   
	tme.hwndTrack=m_hWnd;   
	tme.dwFlags=TME_LEAVE;   
	_TrackMouseEvent(&tme);

	CButton::OnMouseMove(nFlags, point);
}

LRESULT CColorBtn::OnMouseLeave(WPARAM wParam,LPARAM lParam)   
{
	m_bMouseOn=false;
	Invalidate();
	return TRUE;
}

BOOL CColorBtn::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_bMouseOn)
	{
		::SetCursor(LoadCursor(NULL,MAKEINTRESOURCE(m_nCursor)));
		return true;
	}
	return CButton::OnSetCursor(pWnd, nHitTest, message);
}

void CColorBtn::SetBackColor(COLORREF backColor)
{
	m_backColor=backColor;
	m_backColorFocus=backColor;
	m_backColorSelected=backColor;
	Invalidate();
}

void CColorBtn::SetBackColor(COLORREF backColor,COLORREF backColorFocus,
				COLORREF backColorSelected,COLORREF backColorDisabled)
{
	if(backColor!=-1) m_backColor=backColor;
	if(backColorFocus!=-1) m_backColorFocus=backColorFocus;
	if(backColorSelected!=-1) m_backColorSelected=backColorSelected;
	if(backColorDisabled!=-1) m_backColorDisabled=backColorDisabled;
	Invalidate();
}

void CColorBtn::SetForeColor(COLORREF foreColor)
{
	m_foreColor=foreColor;
	m_foreColorFocus=foreColor;
	m_foreColorSelected=foreColor;
	Invalidate();
}

void CColorBtn::SetForeColor(COLORREF foreColor,COLORREF foreColorFocus,
				COLORREF foreColorSelected,COLORREF foreColorDisabled)
{
	if(foreColor!=-1) m_foreColor=foreColor;
	if(foreColorFocus!=-1) m_foreColorFocus=foreColorFocus;
	if(foreColorSelected!=-1) m_foreColorSelected=foreColorSelected;
	if(foreColorDisabled!=-1) m_foreColorDisabled=foreColorDisabled;
	Invalidate();
}

void CColorBtn::SetBitmap(UINT background)
{
	m_background=background;
	m_backgroundFocus=background;
	m_backgroundSelected=background;
	m_backgroundDisabled=background;
	Invalidate();
}

void CColorBtn::SetBitmap(UINT background,UINT backgroundFocus,
				UINT backgroundSelected,UINT backgroundDisabled)
{
	if(background) m_background=background;
	if(backgroundFocus) m_backgroundFocus=backgroundFocus;
	if(backgroundSelected) m_backgroundSelected=backgroundSelected;
	if(backgroundDisabled) m_backgroundDisabled=backgroundDisabled;
	Invalidate();
}

void CColorBtn::SetCursor(int nCursor)
{
	m_nCursor=nCursor;
	Invalidate();
}

void CColorBtn::SetIsBkColor(bool bBkColor)
{
	m_bBkColor=bBkColor;
	Invalidate();
}

void CColorBtn::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CButton::OnLButtonUp(nFlags, point);
}
