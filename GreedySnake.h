// GreedySnake.h : main header file for the GREEDYSNAKE application
//

#if !defined(AFX_GREEDYSNAKE_H__16F1D025_C7E9_4255_B730_5A03812CAB26__INCLUDED_)
#define AFX_GREEDYSNAKE_H__16F1D025_C7E9_4255_B730_5A03812CAB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Common.h"
/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeApp:
// See GreedySnake.cpp for the implementation of this class
//

class CGreedySnakeApp : public CWinApp
{
public:
	CGreedySnakeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreedySnakeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGreedySnakeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREEDYSNAKE_H__16F1D025_C7E9_4255_B730_5A03812CAB26__INCLUDED_)
