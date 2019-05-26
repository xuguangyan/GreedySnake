// NewMapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GreedySnake.h"
#include "NewMapDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewMapDlg dialog


CNewMapDlg::CNewMapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewMapDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewMapDlg)
	m_strAuthor = _T("");
	m_strName = _T("");
	m_bNew = -1;
	//}}AFX_DATA_INIT
}


void CNewMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewMapDlg)
	DDX_Text(pDX, IDC_EDIT_AUTHOR, m_strAuthor);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Radio(pDX, IDC_RADIO_CURRENT, m_bNew);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewMapDlg, CDialog)
	//{{AFX_MSG_MAP(CNewMapDlg)
	ON_BN_CLICKED(IDC_RADIO_CURRENT, OnRadioCurrent)
	ON_BN_CLICKED(IDC_RADIO_NEW, OnRadioNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewMapDlg message handlers

BOOL CNewMapDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bNew=FALSE;
	m_strName=m_strMapName;
	m_strAuthor=m_strAuthorName;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewMapDlg::OnRadioCurrent() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_bNew)
	{
		m_strName="地图"+CCommon::IntToStr(m_mapCount+1,2,true);
		m_strAuthor="未知";
	}
	else
	{
		m_strName=m_strMapName;
		m_strAuthor=m_strAuthorName;
	}
	UpdateData(FALSE);
}

void CNewMapDlg::OnRadioNew() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_bNew)
	{
		m_strName="地图"+CCommon::IntToStr(m_mapCount+1,2,true);
		m_strAuthor="未知";
	}
	else
	{
		m_strName=m_strMapName;
		m_strAuthor=m_strAuthorName;
	}
	UpdateData(FALSE);
}

void CNewMapDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_strName=="")
	{
		MessageBox("请输入地图名称!");
		return ;
	}else if(m_strAuthor=="")
	{
		MessageBox("请输入作者名称!");
		return ;
	}
	CDialog::OnOK();
}
