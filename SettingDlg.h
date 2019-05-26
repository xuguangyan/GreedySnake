#if !defined(AFX_SETTINGDLG_H__7C9ED5D8_2122_4C44_8EDD_00782A103C70__INCLUDED_)
#define AFX_SETTINGDLG_H__7C9ED5D8_2122_4C44_8EDD_00782A103C70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingDlg.h : header file
//
#define UM_BOXCLICK WM_USER+10

#include "Box.h"

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog

class CSettingDlg : public CDialog
{
// Construction
public:
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_DLG_SETTING };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	LRESULT OnBoxClick(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_ptWnd;
	int m_curType;
	UINT *m_array;
private:
	CPoint m_ptDown;
	BOOL m_bDown;
	CBox m_box[10];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDLG_H__7C9ED5D8_2122_4C44_8EDD_00782A103C70__INCLUDED_)
