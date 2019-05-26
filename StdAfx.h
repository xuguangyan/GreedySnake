// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__DD1DF418_1BC6_41D5_AED5_CBFE2BFBF768__INCLUDED_)
#define AFX_STDAFX_H__DD1DF418_1BC6_41D5_AED5_CBFE2BFBF768__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#define MOVE_UP     1
#define MOVE_DOWN  -1
#define MOVE_LEFT   2
#define MOVE_RIGHT -2

#define TYPE_WALL   0
#define TYPE_GROUND 1
#define TYPE_HEAD   3
#define TYPE_BODY   4
#define TYPE_REAR   5
#define TYPE_FOOD   6
#define TYPE_SNAKE  7

#define MODE_GAME   0
#define MODE_DESING 1

#define UM_LBUTTONDOWN   WM_USER+10
#define UM_LBUTTONUP     WM_USER+11
#define UM_LBUTTONDBLCLK WM_USER+12
#define UM_RBUTTONDOWN   WM_USER+13
#define UM_RBUTTONUP     WM_USER+14
#define UM_MOUSEMOVE     WM_USER+15
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__DD1DF418_1BC6_41D5_AED5_CBFE2BFBF768__INCLUDED_)
