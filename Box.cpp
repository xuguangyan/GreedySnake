// Box.cpp : implementation file
//

#include "stdafx.h"
#include "GreedySnake.h"
#include "Box.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBox

CBox::CBox()
{
	m_bMask=FALSE;
	m_bPaint=FALSE;
	m_bEnable=FALSE;
	m_bSelect=FALSE;
	m_bBorder=TRUE;
	m_nType=-1;
}

CBox::~CBox()
{
}


BEGIN_MESSAGE_MAP(CBox, CButton)
	//{{AFX_MSG_MAP(CBox)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBox message handlers
BOOL CBox::Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	m_nID=nID;
	m_pParentWnd=pParentWnd;
	return CButton::Create(lpszCaption,dwStyle,rect,pParentWnd,nID);
}

void CBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);//获取一个CDC指针
	CRect rect(lpDrawItemStruct->rcItem);//定义按钮区域并初始化
	if(m_bPaint)
	{	
		
		if(m_bMask)
			DrawTransparentBitmap(pDC,rect);
		else
			DrawBitmap(pDC,rect);
	}
	else
	{
		CBrush brush;
		brush.CreateSolidBrush(GetSysColor(COLOR_3DFACE));
		pDC->FillRect(rect,&brush);
	}
	if(m_bBorder)
	{
		if(m_bSelect)
			pDC->Draw3dRect(rect,RGB(255,0,0),RGB(255,0,0));
		else
			pDC->Draw3dRect(rect,GetSysColor(COLOR_3DHILIGHT),GetSysColor(COLOR_3DSHADOW));
	}
}

void CBox::SetBitmap(LPCTSTR lpszFileName,LPCTSTR lpszBgFileName)
{
	m_bPaint=FALSE;
	m_bMask=FALSE;
	if(lpszFileName!="")
	{
		HBITMAP hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),lpszFileName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		if(hBitmap)
		{
			m_image.DeleteObject();
			m_image.Attach(hBitmap);
			m_bPaint=TRUE;
		}
		else
			return ;
	}
	else
		return;
	if(lpszBgFileName!="")
	{
		HBITMAP hBgBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),lpszBgFileName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		if(hBgBitmap)
		{
			m_background.DeleteObject();
			m_background.Attach(hBgBitmap);
			m_bMask=TRUE;
		}
	}
	Invalidate();
}

void CBox::SetBitmap(UINT nResID,UINT nBgResID)
{
	m_bPaint=FALSE;
	m_bMask=FALSE;
	if(nResID)
	{
		m_image.DeleteObject();
		if(m_image.LoadBitmap(nResID))
			m_bPaint=TRUE;
		else
			return ;
	}
	else
		return;
	if(nBgResID)
	{
		m_background.DeleteObject();
		if(m_background.LoadBitmap(nBgResID))
			m_bMask=TRUE;
		else
			return ;
	}
	Invalidate();
}

void CBox::SetBitmap(CBitmap * pBitmap,CBitmap * pBgBitmap)
{
	m_bPaint=FALSE;
	m_bMask=FALSE;
	if(pBitmap)
	{
		m_image.DeleteObject();
		if(m_image.Attach((HBITMAP)pBitmap->m_hObject))
			m_bPaint=TRUE;
		else
			return ;
	}
	else
		return;
	if(pBgBitmap)
	{
		m_background.DeleteObject();
		if(m_background.Attach((HBITMAP)pBgBitmap->m_hObject))
			m_bMask=TRUE;
		else
			return ;
	}
	Invalidate();
}

void CBox::SetBitmap(HBITMAP hBitmap,HBITMAP hBgBitmap)
{
	m_bPaint=FALSE;
	m_bMask=FALSE;
	if(hBitmap)
	{
		m_image.DeleteObject();
		if(m_image.Attach(hBitmap))
			m_bPaint=TRUE;
		else
			return ;
	}
	else
		return;
	if(hBgBitmap)
	{
		m_background.DeleteObject();
		if(m_background.Attach(hBgBitmap))
			m_bMask=TRUE;
		else
			return ;
	}
	Invalidate();
}

void CBox::DrawBitmap(CDC *pDC,CRect rect)
{
	CDC ImageDC;
	CBitmap *pOldImage;
	ImageDC.CreateCompatibleDC(pDC);
	pOldImage=ImageDC.SelectObject(&m_image);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&ImageDC,0,0,SRCCOPY);
	ImageDC.SelectObject(pOldImage);
}

void CBox::DrawTransparentBitmap(CDC *pDC,CRect rect)
{ 
	CDC backgroundDC,ImageDC,MaskDC; 
	
	CBitmap *pOldBackground,*pOldImage; 
	CBitmap maskBitmap,*pOldMaskDCBitmap ; 
	
	backgroundDC.CreateCompatibleDC(pDC);
	pOldBackground=backgroundDC.SelectObject(&m_background);

	ImageDC.CreateCompatibleDC(pDC); 
	pOldImage=ImageDC.SelectObject(&m_image); 
	
	MaskDC.CreateCompatibleDC(pDC); 
	maskBitmap.CreateBitmap(rect.Width(),rect.Height(),1,1,NULL); 
	pOldMaskDCBitmap=MaskDC.SelectObject(&maskBitmap ); 
	
	ImageDC.SetBkColor(RGB(255,255,255)); 
	MaskDC.BitBlt(0,0,rect.Width(),rect.Height(),&ImageDC,0,0,SRCCOPY); 
	
	ImageDC.SetBkColor(RGB(0,0,0)); 
	ImageDC.SetTextColor(RGB(255,255,255)); 
	ImageDC.BitBlt(0,0,rect.Width(),rect.Height(),&MaskDC,0,0,SRCAND); 
	
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&backgroundDC,0,0,SRCCOPY);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&MaskDC,0,0,SRCAND); 
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&ImageDC,0,0,SRCPAINT); 
	
	backgroundDC.SelectObject(pOldBackground); 
	MaskDC.SelectObject(pOldMaskDCBitmap); 
	ImageDC.SelectObject(pOldImage); 
}

void CBox::SetEnable(BOOL bEnable)
{
	m_bEnable=bEnable;
}

BOOL CBox::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
	{
		::SetCursor(AfxGetApp()->LoadStandardCursor(MAKEINTRESOURCE(32649)));
		return TRUE;
	}
	return CButton::OnSetCursor(pWnd, nHitTest, message);
}

void CBox::SetSelect(BOOL bSelect)
{
	m_bSelect=bSelect;
	Invalidate();
}

void CBox::SetType(int nType)
{
	m_nType=nType;
	switch(nType)
	{
	case TYPE_WALL:
		m_bBorder=TRUE;
		break;
	case TYPE_GROUND:
		m_bBorder=FALSE;
		break;
	case TYPE_FOOD:
		m_bBorder=FALSE;
		break;
	case TYPE_SNAKE:
		m_bBorder=TRUE;
		break;
	}
	Invalidate();
}

int CBox::GetType()
{
	return m_nType;
}

void CBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
		::SendMessage(m_pParentWnd->GetSafeHwnd(),UM_LBUTTONDOWN,m_nID,0);
	
	CButton::OnLButtonDown(nFlags, point);
}

void CBox::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
		::SendMessage(m_pParentWnd->GetSafeHwnd(),UM_LBUTTONUP,m_nID,0);

	CButton::OnLButtonUp(nFlags, point);
}

void CBox::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
		::SendMessage(m_pParentWnd->GetSafeHwnd(),UM_LBUTTONDBLCLK,m_nID,0);
	
	CButton::OnLButtonDblClk(nFlags, point);
}

void CBox::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
		::SendMessage(m_pParentWnd->GetSafeHwnd(),UM_RBUTTONDOWN,m_nID,0);
	
	CButton::OnRButtonDown(nFlags, point);
}

void CBox::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
		::SendMessage(m_pParentWnd->GetSafeHwnd(),UM_RBUTTONUP,m_nID,0);
	
	CButton::OnRButtonUp(nFlags, point);
}

void CBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bEnable)
		::SendMessage(m_pParentWnd->GetSafeHwnd(),UM_MOUSEMOVE,m_nID,0);
	
	CButton::OnMouseMove(nFlags, point);
}

void CBox::SetBorder(BOOL bBorder)
{
	m_bBorder=bBorder;
	Invalidate();
}
