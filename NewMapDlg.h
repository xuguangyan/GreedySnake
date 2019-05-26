#if !defined(AFX_NEWMAPDLG_H__B0982EA1_0903_4784_B18F_A5E839BC7168__INCLUDED_)
#define AFX_NEWMAPDLG_H__B0982EA1_0903_4784_B18F_A5E839BC7168__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewMapDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewMapDlg dialog

class CNewMapDlg : public CDialog
{
// Construction
public:
	CNewMapDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewMapDlg)
	enum { IDD = IDD_DLG_NEWMAP };
	CString	m_strAuthor;
	CString	m_strName;
	int		m_bNew;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewMapDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewMapDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioCurrent();
	afx_msg void OnRadioNew();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CString m_strMapName;
	CString m_strAuthorName;
	int m_mapCount;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWMAPDLG_H__B0982EA1_0903_4784_B18F_A5E839BC7168__INCLUDED_)
