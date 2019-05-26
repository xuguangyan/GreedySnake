// Common.cpp: implementation of the CCommon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommon::CCommon()
{

}

CCommon::~CCommon()
{

}

//���ô���͸��
void CCommon::SetAlpha(HWND hWnd, int alpha)
{
	HINSTANCE hInst=LoadLibrary("User32.DLL");     
	if(hInst)     
	{
		/*һЩ����:     
		WS_EX_LAYERED=0x80000;   
		LWA_ALPHA=0x2;   
		LWA_COLORKEY=0x1     
		����dwFlags��LWA_ALPHA��LWA_COLORKEY   
		LWA_ALPHA�����õĻ�,ͨ��bAlpha����͸����.   
		LWA_COLORKEY�����õĻ�,��ָ����͸��������ɫΪcrKey,������ɫ��������ʾ.   
		ע:Ҫʹʹ����ӵ��͸��Ч��,����Ҫ��WS_EX_LAYERED��չ����(��sdkҲû�е�). */  

		typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD);     
		MYFUNC fun=NULL;   
		//ȡ��SetLayeredWindowAttributes����ָ��     
		fun=(MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");   
		if(fun) fun(hWnd,0,alpha,2);     
		FreeLibrary(hInst);     
	}
}

int CCommon::SplitString(CString str, char chSplitter, CStringArray &aryItem)
{
	TCHAR* p=str.GetBuffer(0);   
	TCHAR* e=p;   
	TCHAR cEnd=*e;   
	int nCount=0;   
	while(cEnd)   
	{   
		if(*e==_T('\0'))   
			cEnd=*e;   
		else if(*e==chSplitter)   
			*e=_T('\0');   
		
		if(*e)   
			e++;   
		else   
		{   
			if(*p!=_T('\0'))   
			{   
				aryItem.Add(p);   
				nCount++;   
			}   
			p=++e;   
		}   
	}   
	return nCount; 
}

//����ת�����ַ�
//nNum:����
//nSize:��ȡ����
//bFull;�����Ȳ���,�Ƿ���ǰ�����㲹��
CString CCommon::IntToStr(int nNum, int nSize, bool bFull)
{
	char *pBuf=new char[nSize+1];
	itoa(nNum,pBuf,10);
	CString str=pBuf;
	if(!bFull)
		return str;

	int nLen=str.GetLength();
	for(int i=0;i<nSize-nLen;i++)
	{
		str="0"+str;
	}
	return str;
}

CString CCommon::GetTimeStr(int nTime)
{
	int nHour,nMinute,nSecond,nTemp;
	CString strHour,strMinute,strSecond;

	nHour=nTime/(60*60);
	nTemp=nTime%(60*60);
	nMinute=nTemp/60;
	nSecond=nTemp%60;

	strHour.Format("%d",nHour);
	strMinute.Format("%d",nMinute);
	strSecond.Format("%d",nSecond);

	if(nHour<10) strHour="0"+strHour;
	if(nMinute<10) strMinute="0"+strMinute;
	if(nSecond<10) strSecond="0"+strSecond;

	return strHour+":"+strMinute+":"+strSecond;
}