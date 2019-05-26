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
				const RECT& rect, CWnd* pParentWnd, UINT nID);//���ش�������
// Attributes
public:

// Operations
public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);//����DrawItem����
	void SetBitmap(UINT nResID,UINT nBgResID=0);//����λͼ(����:ǰ��ͼ,����ͼ)
	void SetBitmap(LPCTSTR lpszFileName,LPCTSTR lpszBgFileName="");
	void SetBitmap(CBitmap * pBitmap,CBitmap * pBgBitmap=NULL);
	void SetBitmap(HBITMAP hBitmap,HBITMAP hBgBitmap=NULL);
	void DrawBitmap(CDC *pDC,CRect rect);//��DC�ϻ�ͼ
	void DrawTransparentBitmap(CDC *pDC,CRect rect);//ǰ��͸��(���ΰ�ɫ)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetType();//��ȡ��������(Χǽ\�ذ�\ʳ��\��)
	void SetType(int nType);//���÷�������
	void SetSelect(BOOL bSelect=TRUE);//���÷��鱻ѡ��
	void SetEnable(BOOL bEnable=TRUE);//���÷����������ť
	void SetBorder(BOOL bBorder=TRUE);//���÷����б߿�
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
	int m_nType;//��������
	UINT m_nID;//����ID
	CWnd* m_pParentWnd;//������ָ��
	CBitmap m_background;//����ͼ
	CBitmap m_image;//ǰ��ͼ
	BOOL m_bBorder;//�Ƿ��б߿�
	BOOL m_bMask;//�Ƿ�Ҫ����ɫ
	BOOL m_bPaint;//�Ƿ�ɻ�ͼ
	BOOL m_bEnable;//�Ƿ����Ӧ���
	BOOL m_bSelect;//�Ƿ�ѡ��
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOX_H__CA5F7036_723A_4520_AFBC_30959FE70D3B__INCLUDED_)
