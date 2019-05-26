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
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);//����DrawItem����
	LRESULT OnMouseLeave(WPARAM wParam,LPARAM lParam); //����Ƴ�
	BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,//���ش�������
				const RECT& rect, CWnd* pParentWnd, UINT nID);
	BOOL AutoLoad(UINT nID, CWnd* pParent);//�Զ�����(����CButton�ఴť)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBtn)
	//}}AFX_VIRTUAL

// Implementation
public:
	//�豳��ɫ
	void SetBackColor(COLORREF backColor);
	void SetBackColor(COLORREF backColor,COLORREF backColorFocus,
				COLORREF backColorSelected,COLORREF backColorDisabled);
	//��ǰ��ɫ
	void SetForeColor(COLORREF foreColor);
	void SetForeColor(COLORREF foreColor,COLORREF foreColorFocus,
				COLORREF foreColorSelected,COLORREF foreColorDisabled);
	//�豳��ͼ
	void SetBitmap(UINT background);
	void SetBitmap(UINT background,UINT backgroundFocus,
				UINT backgroundSelected,UINT backgroundDisabledL);
	void SetCursor(int nCursor);//����
	void SetIsBkColor(bool bBkColor);//������ʾ����ɫ(�ֻ򱳾�ͼ)
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
	bool m_bBkColor;//�Ƿ���ʾ����ɫ
	int m_nCursor;//���ID

	COLORREF m_backColor;//����ʱ����ɫ
	COLORREF m_backColorFocus;//�۽�ʱ����ɫ
	COLORREF m_backColorSelected;//ѡ��ʱ����ɫ
	COLORREF m_backColorDisabled;//ʧЧʱ����ɫ

	COLORREF m_foreColor;//����ʱǰ��ɫ
	COLORREF m_foreColorFocus;//�۽�ʱǰ��ɫ
	COLORREF m_foreColorSelected;//ѡ��ʱǰ��ɫ
	COLORREF m_foreColorDisabled;//ʧЧʱǰ��ɫ

	UINT m_background;//����ʱ����ͼ
	UINT m_backgroundFocus;//�۽�ʱ����ͼ
	UINT m_backgroundSelected;//ѡ��ʱ����ͼ
	UINT m_backgroundDisabled;//ʧЧʱ����ͼ

	bool m_bMouseOn;//����Ƿ�������

	UINT m_nID;//����ťID
	CWnd* m_pWnd;//������ָ��
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ColorBtn_H__837372C2_DB60_4465_A00F_ACE345EF5684__INCLUDED_)
