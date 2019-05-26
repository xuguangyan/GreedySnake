#if !defined(AFX_ColorBtn_H__837372C2_DB60_4465_A00F_ACE345EF5684__INCLUDED_)
#define AFX_ColorBtn_H__837372C2_DB60_4465_A00F_ACE345EF5684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorBtn.h : header file
//
#define UM_LBUTTONUP WM_USER+11
/////////////////////////////////////////////////////////////////////////////
// CColorBtn window

class CColorBtn : public CButton
{
// Construction
public:
	CColorBtn();

// Attributes
public:

// Operations
public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);//重载DrawItem函数
	LRESULT OnMouseLeave(WPARAM wParam,LPARAM lParam); //鼠标移出
	BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,//重载创建函数
				const RECT& rect, CWnd* pParentWnd, UINT nID);
	BOOL AutoLoad(UINT nID, CWnd* pParent);//自动加载(即绑定CButton类按钮)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBtn)
	//}}AFX_VIRTUAL

// Implementation
public:
	//设背景色
	void SetBackColor(COLORREF backColor);
	void SetBackColor(COLORREF backColor,COLORREF backColorFocus,
				COLORREF backColorSelected,COLORREF backColorDisabled);
	//设前景色
	void SetForeColor(COLORREF foreColor);
	void SetForeColor(COLORREF foreColor,COLORREF foreColorFocus,
				COLORREF foreColorSelected,COLORREF foreColorDisabled);
	//设背景图
	void SetBitmap(UINT background);
	void SetBitmap(UINT background,UINT backgroundFocus,
				UINT backgroundSelected,UINT backgroundDisabledL);
	void SetCursor(int nCursor);//设光标
	void SetIsBkColor(bool bBkColor);//设置显示背景色(抑或背景图)
	virtual ~CColorBtn();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorBtn)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	bool m_bBkColor;//是否显示背景色
	int m_nCursor;//光标ID

	COLORREF m_backColor;//正常时背景色
	COLORREF m_backColorFocus;//聚焦时背景色
	COLORREF m_backColorSelected;//选中时背景色
	COLORREF m_backColorDisabled;//失效时背景色

	COLORREF m_foreColor;//正常时前景色
	COLORREF m_foreColorFocus;//聚焦时前景色
	COLORREF m_foreColorSelected;//选中时前景色
	COLORREF m_foreColorDisabled;//失效时前景色

	UINT m_background;//正常时背景图
	UINT m_backgroundFocus;//聚焦时背景图
	UINT m_backgroundSelected;//选中时背景图
	UINT m_backgroundDisabled;//失效时背景图

	bool m_bMouseOn;//鼠标是否在上面

	UINT m_nID;//本按钮ID
	CWnd* m_pWnd;//父窗口指针
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ColorBtn_H__837372C2_DB60_4465_A00F_ACE345EF5684__INCLUDED_)
