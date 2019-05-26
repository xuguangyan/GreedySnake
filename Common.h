// Common.h: interface for the CCommon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMON_H__E789D252_3A23_404C_B5D7_85C8BF271D2F__INCLUDED_)
#define AFX_COMMON_H__E789D252_3A23_404C_B5D7_85C8BF271D2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCommon  
{
public:
	static CString GetTimeStr(int nTime);
	static CString IntToStr(int nNum,int nSize,bool bFull=false);
	static int SplitString(CString str, char chSplitter, CStringArray& aryItem);
	static void SetAlpha(HWND hWnd,int alpha);//…Ë÷√¥∞ÃÂÕ∏√˜
	CCommon();
	virtual ~CCommon();

};

#endif // !defined(AFX_COMMON_H__E789D252_3A23_404C_B5D7_85C8BF271D2F__INCLUDED_)
