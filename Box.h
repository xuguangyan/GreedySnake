#if !defined(AFX_BOX_H__CA5F7036_723A_4520_AFBC_30959FE70D3B__INCLUDED_)
#define AFX_BOX_H__CA5F7036_723A_4520_AFBC_30959FE70D3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Box.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBox window

class CBox : public CButton
{
// Construction
public:
	CBox();
	BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID);//重载创建函数
// Attributes
public:

// Operations
public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);//重载DrawItem函数
	void SetBitmap(UINT nResID,UINT nBgResID=0);//设置位图(参数:前景图,背景图)
	void SetBitmap(LPCTSTR lpszFileName,LPCTSTR lpszBgFileName="");
	void SetBitmap(CBitmap * pBitmap,CBitmap * pBgBitmap=NULL);
	void SetBitmap(HBITMAP hBitmap,HBITMAP hBgBitmap=NULL);
	void DrawBitmap(CDC *pDC,CRect rect);//在DC上绘图
	void DrawTransparentBitmap(CDC *pDC,CRect rect);//前景透明(屏蔽白色)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetType();//获取方块类型(围墙\地板\食物\蛇)
	void SetType(int nType);//设置方块类型
	void SetSelect(BOOL bSelect=TRUE);//设置方块被选择
	void SetEnable(BOOL bEnable=TRUE);//设置方块可用作按钮
	void SetBorder(BOOL bBorder=TRUE);//设置方块有边框
	virtual ~CBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBox)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	int m_nType;//方块类型
	UINT m_nID;//方块ID
	CWnd* m_pParentWnd;//父窗口指针
	CBitmap m_background;//背景图
	CBitmap m_image;//前景图
	BOOL m_bBorder;//是否有边框
	BOOL m_bMask;//是否要屏蔽色
	BOOL m_bPaint;//是否可绘图
	BOOL m_bEnable;//是否可响应点击
	BOOL m_bSelect;//是否被选择
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOX_H__CA5F7036_723A_4520_AFBC_30959FE70D3B__INCLUDED_)
