// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GreedySnake.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog


CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bDown=FALSE;
}


void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	ON_MESSAGE(UM_BOXCLICK,OnBoxClick)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

LRESULT CSettingDlg::OnBoxClick(WPARAM wParam,LPARAM lParam)
{
	m_curType=wParam-2000;
	CDialog::OnOK();
	return 1;
}

BOOL CSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int xOffset=10;//ÈÝÆ÷×óÉÏ½ÇxÆ«ÒÆ
	int yOffset=20;//ÈÝÆ÷×óÉÏ½ÇyÆ«ÒÆ
	int boxSize=25;//×©¿é´óÐ¡(³¤¿í¾ùÎª25)
	CRect rect;
	int nID;
	for(int i=0;i<2;i++)
		for(int j=0;j<5;j++)
		{
			rect.left=xOffset+j*boxSize;
			rect.top=yOffset+i*boxSize;
			rect.right=xOffset+(j+1)*boxSize;
			rect.bottom=yOffset+(i+1)*boxSize;
			nID=2000+i*5+j;
			m_box[i*5+j].Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect,this,nID);
			m_box[i*5+j].SetEnable();
			m_box[i*5+j].SetBitmap(m_array[i*5+j]);
			if(m_curType==i*5+j) m_box[i*5+j].SetSelect();
		}
	GetWindowRect(&rect);
	SetWindowPos(NULL,m_ptWnd.x-rect.Width()-5,m_ptWnd.y,0,0,SWP_NOZORDER|SWP_NOSIZE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDown=TRUE;
	m_ptDown=point;
	CDialog::OnLButtonDown(nFlags, point);
}

void CSettingDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDown=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}

void CSettingDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDown)
	{
		ClientToScreen(&point);
		point-=m_ptDown;
		SetWindowPos(NULL,point.x,point.y,0,0,SWP_NOZORDER|SWP_NOSIZE);
	}
	CDialog::OnMouseMove(nFlags, point);
}

BOOL CSettingDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	int nID=pWnd->GetDlgCtrlID();
	if(nID==IDCANCEL)
	{
		::SetCursor(AfxGetApp()->LoadStandardCursor(MAKEINTRESOURCE(32649)));
		return TRUE;
	}
	::SetCursor(LoadCursor(NULL,IDC_SIZEALL));
	return TRUE;
	//return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
