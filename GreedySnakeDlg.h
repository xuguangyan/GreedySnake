// GreedySnakeDlg.h : header file
//

#if !defined(AFX_GREEDYSNAKEDLG_H__AA4816BA_D6AC_4EB9_87C6_B4EBAF39FB9C__INCLUDED_)
#define AFX_GREEDYSNAKEDLG_H__AA4816BA_D6AC_4EB9_87C6_B4EBAF39FB9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Box.h"
#include "DLinList.h"
#include "SettingDlg.h"
#include "NewMapDlg.h"
#include "ColorBtn.h"

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeDlg dialog

class CGreedySnakeDlg : public CDialog
{
// Construction
public:
	//食物信息结构
	typedef struct
	{
		int nPos;
		int nType;
	}FoodInfo;

	//围墙信息结构
	typedef int WallInfo;

	//地图信息结构
	typedef struct
	{
		CString strMapName;
		CString strAuthorName;
		int curWall;
		int curGround;
		int curHead;
		int curBody;
		int curRear;
		FoodInfo foodInfo[300];
		WallInfo wallInfo[300];
		int foodCount;
		int wallCount;
	}MapInfo;

	//蛇信息结构(单链表)
	typedef  class DLinList CSnake;

	CGreedySnakeDlg(CWnd* pParent = NULL);	// standard constructor
	~CGreedySnakeDlg();

// Dialog Data
	//{{AFX_DATA(CGreedySnakeDlg)
	enum { IDD = IDD_GREEDYSNAKE_DIALOG };
	CColorBtn	m_btnDelMap;
	CColorBtn	m_btnAbout;
	CColorBtn	m_btnMode;
	CColorBtn	m_btnStart;
	CComboBox	m_comboMap;
	int		m_curMapIndex;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreedySnakeDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGreedySnakeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnStart();
	afx_msg void OnBtnMode();
	afx_msg void OnSelchangeComboMap();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnAbout();
	afx_msg void OnBtnDelmap();
	//}}AFX_MSG
	LRESULT OnLBtnUp(WPARAM wParam,LPARAM lParam);
	LRESULT OnRBtnUp(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	void GameOver();//游戏结束
	void SetSelectBox(UINT nBoxID);//(设计模式下)选择要插入的类型方块(墙\地板\食物)
	void ShowMap();//显示地图
	void LoadMap(BOOL bEditName=FALSE);//加载地图
	void NewMap(BOOL bInit=FALSE);//新建地图
	int PointToInt(int x,int y);//点到整型
	int PointToInt(CPoint point);//点到整型
	CPoint IntToPoint(int pos);//整形到点
	void WallDel(CPoint point);//删除墙信息
	void FoodDel(CPoint point);//删除食物信息
	void FoodEdit(CPoint point);//编辑食物信息
	void MapInfoDel();//删除地图信息
	void MapInfoRead();//读取地图信息
	void MapInfoEdit();//编辑地图信息
	void MapInfoAdd(BOOL bInit=FALSE);//插入地图信息
	void ShowGround();//显示地板
	void ShowWall();//显示围墙
	void ShowHead();//显示蛇头
	void ShowBody();//显示蛇身
	void ShowRear();//显示蛇尾
	void ShowFood();//显示食物
	void ShowSnake();//显示蛇
	void MoveSnake(int direction);//移动蛇
	void SnakeInit();//初始化蛇
	void RegInit();//注册表初始化
	void RegRead();//注册表读取
	void RegWrite();//注册表写入
	void CopyFoodInfo(FoodInfo * srcFoodInfo,FoodInfo * desFoodInfo,int srcCount);//拷贝食物信息
	void CopyWallInfo(WallInfo * srcWallInfo, WallInfo * desWallInfo, int srcCount);//拷贝围墙信息
private:
	BOOL m_bFoodExist;
	CPoint m_overPoint;//结束点(蛇头误撞点)
	UINT m_overID;//结束ID(误撞点方块图片ID)
	void RandFood();//(在FoodInfo结构中)随机生成食物
	HBRUSH m_hBkBrush;//窗口背景刷
	HBRUSH m_hStaticBrush;//静态控件刷
	int m_nTime;//用时
	int m_nSnakeLen;//蛇长
	BOOL m_bNewMap;//新建地图标志
	UINT m_nAdd;//添加类型
	BOOL m_bMapModify;//已改动标志

	BOOL m_bStart;//开始标志
	BOOL m_bMode;//模式标志(游戏/设计模式)
	int m_curDirection;//当前蛇行方向

	//编辑用方块
	CBox m_boxWall;
	CBox m_boxGround;
	CBox m_boxHead;
	CBox m_boxBody;
	CBox m_boxRear;
	CBox m_boxFood;
	//面板上方块矩阵
	CBox m_box[20][20];
	//定义蛇
	CSnake m_snake;

	//各种器物(每种10种样式)
	UINT m_wall[10],m_ground[10],m_head[10],m_rear[10],m_body[10],m_food[10];
	int m_curWall,m_curGround,m_curHead,m_curRear,m_curBody,m_curFood;
	CString m_strMapName,m_strAuthorName;

	FoodInfo m_foodInfo[300];//食物信息
	WallInfo m_wallInfo[300];//围墙信息
	MapInfo m_mapInfo[20];//地图信息
	int m_foodCount,m_wallCount,m_mapCount;
	CString m_strFoodInfo,m_strWallInfo,m_strMapInfo;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREEDYSNAKEDLG_H__AA4816BA_D6AC_4EB9_87C6_B4EBAF39FB9C__INCLUDED_)
