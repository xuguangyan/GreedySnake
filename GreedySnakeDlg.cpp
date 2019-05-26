// GreedySnakeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GreedySnake.h"
#include "GreedySnakeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeDlg dialog

CGreedySnakeDlg::CGreedySnakeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGreedySnakeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGreedySnakeDlg)
	m_curMapIndex = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//初始化变量
	m_foodCount=0;
	m_wallCount=0;
	m_mapCount=0;
	m_curFood=0;
	m_overID=0;
	m_bMode=MODE_GAME;
	m_bStart=FALSE;
	m_bMapModify=FALSE;
	m_bFoodExist=FALSE;
	m_hStaticBrush=CreateSolidBrush(RGB(132,221,127)); 
	m_hBkBrush=CreateSolidBrush(RGB(143,171,190)); 
	//初始化位图ID
	m_wall[0]=IDB_WALL;
	m_wall[1]=IDB_WALL01;
	m_wall[2]=IDB_WALL02;
	m_wall[3]=IDB_WALL03;
	m_wall[4]=IDB_WALL04;
	m_wall[5]=IDB_WALL05;
	m_wall[6]=IDB_WALL06;
	m_wall[7]=IDB_WALL07;
	m_wall[8]=IDB_WALL08;
	m_wall[9]=IDB_WALL09;
	m_ground[0]=IDB_GROUND;
	m_ground[1]=IDB_GROUND01;
	m_ground[2]=IDB_GROUND02;
	m_ground[3]=IDB_GROUND03;
	m_ground[4]=IDB_GROUND04;
	m_ground[5]=IDB_GROUND05;
	m_ground[6]=IDB_GROUND06;
	m_ground[7]=IDB_GROUND07;
	m_ground[8]=IDB_GROUND08;
	m_ground[9]=IDB_GROUND09;
	m_head[0]=IDB_HEAD;
	m_head[1]=IDB_HEAD01;
	m_head[2]=IDB_HEAD02;
	m_head[3]=IDB_HEAD03;
	m_head[4]=IDB_HEAD04;
	m_head[5]=IDB_HEAD05;
	m_head[6]=IDB_HEAD06;
	m_head[7]=IDB_HEAD07;
	m_head[8]=IDB_HEAD08;
	m_head[9]=IDB_HEAD09;
	m_rear[0]=IDB_BODY;
	m_rear[1]=IDB_BODY01;
	m_rear[2]=IDB_BODY02;
	m_rear[3]=IDB_BODY03;
	m_rear[4]=IDB_BODY04;
	m_rear[5]=IDB_BODY05;
	m_rear[6]=IDB_BODY06;
	m_rear[7]=IDB_BODY07;
	m_rear[8]=IDB_BODY08;
	m_rear[9]=IDB_BODY09;
	m_body[0]=IDB_BODY;
	m_body[1]=IDB_BODY01;
	m_body[2]=IDB_BODY02;
	m_body[3]=IDB_BODY03;
	m_body[4]=IDB_BODY04;
	m_body[5]=IDB_BODY05;
	m_body[6]=IDB_BODY06;
	m_body[7]=IDB_BODY07;
	m_body[8]=IDB_BODY08;
	m_body[9]=IDB_BODY09;
	m_food[0]=IDB_FOOD;
	m_food[1]=IDB_FOOD01;
	m_food[2]=IDB_FOOD02;
	m_food[3]=IDB_FOOD03;
	m_food[4]=IDB_FOOD04;
	m_food[5]=IDB_FOOD05;
	m_food[6]=IDB_FOOD06;
	m_food[7]=IDB_FOOD07;
	m_food[8]=IDB_FOOD08;
	m_food[9]=IDB_FOOD09;
}

CGreedySnakeDlg::~CGreedySnakeDlg()
{
	//注册表写入
	RegWrite();
}

void CGreedySnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGreedySnakeDlg)
	DDX_Control(pDX, IDC_BTN_DELMAP, m_btnDelMap);
	DDX_Control(pDX, IDC_BTN_ABOUT, m_btnAbout);
	DDX_Control(pDX, IDC_BTN_MODE, m_btnMode);
	DDX_Control(pDX, IDC_BTN_START, m_btnStart);
	DDX_Control(pDX, IDC_COMBO_MAP, m_comboMap);
	DDX_CBIndex(pDX, IDC_COMBO_MAP, m_curMapIndex);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGreedySnakeDlg, CDialog)
	//{{AFX_MSG_MAP(CGreedySnakeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_MODE, OnBtnMode)
	ON_CBN_SELCHANGE(IDC_COMBO_MAP, OnSelchangeComboMap)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_ABOUT, OnBtnAbout)
	ON_BN_CLICKED(IDC_BTN_DELMAP, OnBtnDelmap)
	//}}AFX_MSG_MAP
	ON_MESSAGE(UM_LBUTTONUP,OnLBtnUp)
	ON_MESSAGE(UM_RBUTTONUP,OnRBtnUp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGreedySnakeDlg message handlers

BOOL CGreedySnakeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here


	//创建框架
	int xOffset=20;//容器左上角x偏移
	int yOffset=20;//容器左上角y偏移
	int boxSize=25;//砖块大小(长宽均为25)
	CRect rect;
	int nID;
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
		{
			rect.left=xOffset+j*boxSize;
			rect.top=yOffset+i*boxSize;
			rect.right=xOffset+(j+1)*boxSize;
			rect.bottom=yOffset+(i+1)*boxSize;
			nID=2000+i*20+j;
			m_box[j][i].Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect,this,nID);
		}
	//注册表初始化
	RegInit();
	//加载地图
	LoadMap();

	//创建右栏按钮
	m_boxWall.Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(570,20,570+25,20+25),this,IDC_BOXWALL);
	m_boxWall.SetBitmap(m_wall[m_curWall]);
	m_boxGround.Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(570,50,570+25,50+25),this,IDC_BOXGROUND);
	m_boxGround.SetBitmap(m_ground[m_curGround]);
	m_boxFood.Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(570,80,570+25,80+25),this,IDC_BOXFOOD);
	m_boxFood.SetBitmap(m_food[m_curFood]);
	m_boxHead.Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(570,110,570+25,110+25),this,IDC_BOXHEAD);
	m_boxHead.SetBitmap(m_head[m_curHead]);
	m_boxBody.Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(570,140,570+25,140+25),this,IDC_BOXBODY);
	m_boxBody.SetBitmap(m_body[m_curBody]);
	m_boxRear.Create("",WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(570,170,570+25,170+25),this,IDC_BOXREAR);
	m_boxRear.SetBitmap(m_rear[m_curRear]);

	m_btnAbout.SetForeColor(RGB(0,0,128),RGB(255,255,0),RGB(0,0,128),-1);
	m_btnAbout.SetBackColor(RGB(143,171,190),RGB(157,181,197),RGB(157,181,197),RGB(157,181,197));
	m_btnMode.SetForeColor(RGB(0,0,128),RGB(255,255,0),RGB(0,0,128),-1);
	m_btnMode.SetBackColor(RGB(143,171,190),RGB(157,181,197),RGB(157,181,197),RGB(157,181,197));
	m_btnStart.SetForeColor(RGB(0,0,128),RGB(255,255,0),RGB(0,0,128),-1);
	m_btnStart.SetBackColor(RGB(143,171,190),RGB(157,181,197),RGB(157,181,197),RGB(157,181,197));
	m_btnDelMap.SetForeColor(RGB(0,0,128),RGB(255,255,0),RGB(0,0,128),-1);
	m_btnDelMap.SetBackColor(RGB(143,171,190),RGB(157,181,197),RGB(157,181,197),RGB(157,181,197));

	((CStatic *)GetDlgItem(IDC_STATIC_MAPINFO))->SetWindowText("\n "+m_strMapName+"\n 作者:"+m_strAuthorName);
	
	//设置计时器
	SetTimer(1,500,NULL);
	SetTimer(2,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGreedySnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGreedySnakeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGreedySnakeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGreedySnakeDlg::ShowSnake()
{
	ShowHead();
	ShowRear();
	ShowBody();
}

void CGreedySnakeDlg::MoveSnake(int direction)
{
	int cx=0,cy=0;
	switch(direction)
	{
	case MOVE_UP:
		cy=-1;
		break;
	case MOVE_DOWN:
		cy=1;
		break;
	case MOVE_LEFT:
		cx=-1;
		break;
	case MOVE_RIGHT:
		cx=1;
		break;
	}
	CPoint oldPoint,point;
	oldPoint=CPoint(m_snake.head->data.x,m_snake.head->data.y);
	point=oldPoint+CPoint(cx,cy);
	//判断是否可走
	int nType=m_box[point.x][point.y].GetType();
	switch(nType)
	{
	case TYPE_FOOD://食物:走,并加长
		m_snake.ListInsert(point);
		m_box[oldPoint.x][oldPoint.y].SetBitmap(m_body[m_curBody],m_ground[m_curGround]);
		m_box[point.x][point.y].SetBitmap(m_head[m_curHead],m_ground[m_curGround]);
		m_box[point.x][point.y].SetType(TYPE_SNAKE);

		m_nSnakeLen++;
		((CStatic *)GetDlgItem(IDC_STATIC_LENGTH))->SetWindowText(CCommon::IntToStr(m_nSnakeLen,3,true));
		m_bFoodExist=FALSE;
		break;
	case TYPE_GROUND://地板:走,不加长
		m_snake.ListInsert(point);
		m_box[oldPoint.x][oldPoint.y].SetBitmap(m_body[m_curBody],m_ground[m_curGround]);
		m_box[point.x][point.y].SetBitmap(m_head[m_curHead],m_ground[m_curGround]);
		m_box[point.x][point.y].SetType(TYPE_SNAKE);

		m_snake.ListDelete(&oldPoint);
		point=CPoint(m_snake.rear->data.x,m_snake.rear->data.y);
		m_box[oldPoint.x][oldPoint.y].SetBitmap(m_ground[m_curGround]);
		m_box[oldPoint.x][oldPoint.y].SetType(TYPE_GROUND);
		m_box[point.x][point.y].SetBitmap(m_rear[m_curRear],m_ground[m_curGround]);
		break;
	case TYPE_WALL:
	case TYPE_SNAKE://围墙,蛇本身:走,并标记误撞点,结束游戏
		if(nType==TYPE_WALL)
			m_overID=m_wall[m_curWall];
		else
			m_overID=m_body[m_curBody];
		m_overPoint=point;

		m_snake.ListInsert(point);
		m_box[oldPoint.x][oldPoint.y].SetBitmap(m_body[m_curBody],m_ground[m_curGround]);
		m_box[point.x][point.y].SetBitmap(IDB_NO);
		m_box[point.x][point.y].SetType(TYPE_SNAKE);

		m_snake.ListDelete(&oldPoint);
		point=CPoint(m_snake.rear->data.x,m_snake.rear->data.y);
		m_box[oldPoint.x][oldPoint.y].SetBitmap(m_ground[m_curGround]);
		m_box[oldPoint.x][oldPoint.y].SetType(TYPE_GROUND);
		m_box[point.x][point.y].SetBitmap(m_rear[m_curRear],m_ground[m_curGround]);
		GameOver();
		break;
	}
}


BOOL CGreedySnakeDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	/*扫描码表:
　　VK_RETURN    0D ENTER 键(回车)
	VK_ESCAPE    1B ESC 键(退出)
　　VK_SPACE     20 SPACEBAR键(空格)
	VK_LEFT      25 方向键盘上的 ← 键
　　VK_UP        26 方向键盘上的 ↑ 键
　　VK_RIGHT     27 方向键盘上的 → 键
　　VK_DOWN      28 方向键盘上的 ↓ 键*/
	switch(pMsg->message)
	{
	case WM_KEYDOWN:
		switch(pMsg->wParam)
		{
		case VK_UP:
			m_curDirection=MOVE_UP;
			break;
		case VK_LEFT:
			m_curDirection=MOVE_LEFT;
			break;
		case VK_RIGHT:
			m_curDirection=MOVE_RIGHT;
			break;
		case VK_DOWN:
			m_curDirection=MOVE_DOWN;
			break;
		}
		break;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CGreedySnakeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		if(m_bStart)
		{
			MoveSnake(m_curDirection);
			((CStatic *)GetDlgItem(IDC_STATIC_TIME))->SetWindowText(CCommon::GetTimeStr(m_nTime));
			if(!m_bFoodExist) RandFood();
		}
		break;
	case 2:
		if(m_bStart)
			m_nTime++;
		//误撞点闪烁效果
		if(m_overID)
		{
			static BOOL bShowOver=FALSE;
			if(bShowOver)
				m_box[m_overPoint.x][m_overPoint.y].SetBitmap(IDB_NO,m_overID);
			else
				m_box[m_overPoint.x][m_overPoint.y].SetBitmap(m_overID);
			bShowOver=!bShowOver;
		}
		break;
	}

	CDialog::OnTimer(nIDEvent);
}

//右键,弹出样式选择对话框
LRESULT CGreedySnakeDlg::OnRBtnUp(WPARAM wParam,LPARAM lParam)
{
	CSettingDlg dlg;
	CPoint point;
	CRect rect;
	GetWindowRect(&rect);
	point.x=rect.right;
	switch(wParam)
	{
	case IDC_BOXWALL:
		m_boxWall.GetWindowRect(&rect);
		point.y=rect.top+25;
		dlg.m_ptWnd=point;
		dlg.m_curType=m_curWall;
		dlg.m_array=m_wall;
		if(IDOK==dlg.DoModal())
		{
			m_curWall=dlg.m_curType;
			m_boxWall.SetBitmap(m_wall[m_curWall]);
			ShowWall();
			m_bMapModify=TRUE;
		}
		SetSelectBox(IDC_BOXWALL);
		break;
	case IDC_BOXGROUND:
		m_boxGround.GetWindowRect(&rect);
		point.y=rect.top+25;
		dlg.m_ptWnd=point;
		dlg.m_curType=m_curGround;
		dlg.m_array=m_ground;
		if(IDOK==dlg.DoModal())
		{
			m_curGround=dlg.m_curType;
			m_boxGround.SetBitmap(m_ground[m_curGround]);
			ShowMap();
			m_bMapModify=TRUE;
		}
		SetSelectBox(IDC_BOXGROUND);
		break;
	case IDC_BOXHEAD:
		m_boxHead.GetWindowRect(&rect);
		point.y=rect.top+25;
		dlg.m_ptWnd=point;
		dlg.m_curType=m_curHead;
		dlg.m_array=m_head;
		if(IDOK==dlg.DoModal())
		{
			m_curHead=dlg.m_curType;
			m_boxHead.SetBitmap(m_head[m_curHead]);
			ShowHead();
			m_bMapModify=TRUE;
		}
		break;
	case IDC_BOXBODY:
		m_boxBody.GetWindowRect(&rect);
		point.y=rect.top+25;
		dlg.m_ptWnd=point;
		dlg.m_curType=m_curBody;
		dlg.m_array=m_body;
		if(IDOK==dlg.DoModal())
		{
			m_curBody=dlg.m_curType;
			m_boxBody.SetBitmap(m_body[m_curBody]);
			ShowBody();
			m_bMapModify=TRUE;
		}
		break;
	case IDC_BOXREAR:
		m_boxRear.GetWindowRect(&rect);
		point.y=rect.top+25;
		dlg.m_ptWnd=point;
		dlg.m_curType=m_curRear;
		dlg.m_array=m_rear;
		if(IDOK==dlg.DoModal())
		{
			m_curRear=dlg.m_curType;
			m_boxRear.SetBitmap(m_rear[m_curRear]);
			ShowRear();
			m_bMapModify=TRUE;
		}
		break;
	case IDC_BOXFOOD:
		m_boxFood.GetWindowRect(&rect);
		point.y=rect.top+25;
		dlg.m_ptWnd=point;
		dlg.m_curType=m_curFood;
		dlg.m_array=m_food;
		if(IDOK==dlg.DoModal())
		{
			m_curFood=dlg.m_curType;
			m_boxFood.SetBitmap(m_food[m_curFood]);
		}
		SetSelectBox(IDC_BOXFOOD);
		break;
	}
	return 1;
}

//左键
LRESULT CGreedySnakeDlg::OnLBtnUp(WPARAM wParam,LPARAM lParam)
{
	//选中样式选择按钮
	SetSelectBox(wParam);

	//在地图上添加器物(围墙\地板\食物)
	if(wParam>=2000&&wParam<2400)
	{
		CPoint point=IntToPoint(wParam-2000);
		switch(m_nAdd)
		{
		case IDC_BOXWALL:
			if(m_box[point.x][point.y].GetType()!=TYPE_WALL)
			{
				if(m_box[point.x][point.y].GetType()==TYPE_FOOD)
				{
					FoodDel(point);
				}
				m_wallInfo[m_wallCount++]=wParam-2000;

				m_box[point.x][point.y].SetBitmap(m_wall[m_curWall]);
				m_box[point.x][point.y].SetType(TYPE_WALL);
				m_bMapModify=TRUE;
			}
			break;
		case IDC_BOXFOOD:
			if(m_box[point.x][point.y].GetType()==TYPE_FOOD)
			{
				FoodEdit(point);
			}
			else
			{
				if(m_box[point.x][point.y].GetType()==TYPE_WALL)
				{
					WallDel(point);
				}
				m_foodInfo[m_foodCount].nPos=wParam-2000;
				m_foodInfo[m_foodCount].nType=m_curFood;
				m_foodCount++;
			}
			m_box[point.x][point.y].SetBitmap(m_food[m_curFood],m_ground[m_curGround]);
			m_box[point.x][point.y].SetType(TYPE_FOOD);
			m_bMapModify=TRUE;
			break;
		case IDC_BOXGROUND:
			if(m_box[point.x][point.y].GetType()!=TYPE_GROUND)
			{
				if(m_box[point.x][point.y].GetType()==TYPE_WALL)
				{
					WallDel(point);
				}
				else if(m_box[point.x][point.y].GetType()==TYPE_FOOD)
				{
					FoodDel(point);
				}
				m_box[point.x][point.y].SetBitmap(m_ground[m_curGround]);
				m_box[point.x][point.y].SetType(TYPE_GROUND);
				m_bMapModify=TRUE;
			}
			break;
		}
	}
	return 1;
}

void CGreedySnakeDlg::ShowWall()
{
	int i,j;
	CPoint point;
	for(i=0;i<20;i+=19)
		for(j=0;j<20;j++)
		{
			m_box[j][i].SetBitmap(m_wall[m_curWall]);
			m_box[j][i].SetType(TYPE_WALL);
		}

	for(i=0;i<20;i+=19)
		for(j=1;j<19;j++)
		{
			m_box[i][j].SetBitmap(m_wall[m_curWall]);
			m_box[i][j].SetType(TYPE_WALL);
		}

	for(i=0;i<m_wallCount;i++)
	{
		point=IntToPoint(m_wallInfo[i]);
		m_box[point.x][point.y].SetBitmap(m_wall[m_curWall]);
		m_box[point.x][point.y].SetType(TYPE_WALL);
	}
}

void CGreedySnakeDlg::ShowGround()
{
	int i,j;
	for(i=1;i<19;i++)
		for(j=1;j<19;j++)
		{
			m_box[j][i].SetBitmap(m_ground[m_curGround]);
			m_box[i][j].SetType(TYPE_GROUND);
		}
}

void CGreedySnakeDlg::ShowHead()
{
	m_box[m_snake.head->data.x][m_snake.head->data.y].SetBitmap(m_head[m_curHead],m_ground[m_curGround]);
	m_box[m_snake.head->data.x][m_snake.head->data.y].SetType(TYPE_SNAKE);
}

void CGreedySnakeDlg::ShowBody()
{
	Node *p=m_snake.head->next;
	while(p!=m_snake.rear)
	{
		m_box[p->data.x][p->data.y].SetBitmap(m_body[m_curBody],m_ground[m_curGround]);
		m_box[p->data.x][p->data.y].SetType(TYPE_SNAKE);
		p=p->next;
	}
}

void CGreedySnakeDlg::ShowRear()
{
	m_box[m_snake.rear->data.x][m_snake.rear->data.y].SetBitmap(m_rear[m_curRear],m_ground[m_curGround]);
	m_box[m_snake.rear->data.x][m_snake.rear->data.y].SetType(TYPE_SNAKE);
}

void CGreedySnakeDlg::ShowFood()
{
	CPoint point;
	if(m_bMode==MODE_DESING)
	for(int i=0;i<m_foodCount;i++)
	{
		point=IntToPoint(m_foodInfo[i].nPos);
		m_box[point.x][point.y].SetBitmap(m_food[m_foodInfo[i].nType],m_ground[m_curGround]);
		m_box[point.x][point.y].SetType(TYPE_FOOD);
	}
}

void CGreedySnakeDlg::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	if(m_bMode==MODE_GAME)//游戏模式
	{
		if(m_bStart)//暂停游戏
		{
			m_bStart=FALSE;
			m_btnStart.SetWindowText("继续游戏");
			m_btnMode.EnableWindow(TRUE);
		}
		else//开始\继续游戏
		{
			CString str;
			m_btnStart.GetWindowText(str);
			if(str!="继续游戏")//开始
			{
				LoadMap();
				m_bFoodExist=FALSE;
				m_overID=0;
				m_nTime=0;
				((CStatic *)GetDlgItem(IDC_STATIC_TIME))->SetWindowText(CCommon::GetTimeStr(m_nTime));
			}
			//继续
			m_bStart=TRUE;
			m_btnStart.SetWindowText("暂停游戏");
			m_btnMode.EnableWindow(FALSE);
		}
	}
	else//设计模式(保存按钮)
	{
		if(m_bMapModify)
		{
			if(m_foodCount==0||m_wallCount==0)
			{
				MessageBox("请至少添加一块墙和一个食物!");
				return ;
			}
			if(m_bNewMap)
			{
				MapInfoAdd();
				m_bNewMap=FALSE;
			}
			else
				MapInfoEdit();
			MessageBox("保存成功!");
			m_bMapModify=FALSE;
		}
		else
		{
			MessageBox("你没有对地图做任何改动,不能保存!");
		}
	}
}

void CGreedySnakeDlg::OnBtnMode() 
{
	// TODO: Add your control notification handler code here
	if(m_bMode==MODE_GAME)//游戏模式(进入设计)
	{
		m_overID=0;
		//提示是否新建地图
		CNewMapDlg dlg;
		dlg.m_strMapName=m_strMapName;
		dlg.m_strAuthorName=m_strAuthorName;
		dlg.m_mapCount=m_mapCount;
		if(IDOK==dlg.DoModal())
		{
			m_bNewMap=dlg.m_bNew;
			m_strMapName=dlg.m_strName;
			m_strAuthorName=dlg.m_strAuthor;
		}
		else
			return;
		
		//新建或加载地图,以进行编辑
		m_bMode=MODE_DESING;
		if(m_bNewMap)
		{
			NewMap();
			ShowMap();
			m_comboMap.AddString(m_strMapName);
			m_comboMap.SetCurSel(m_mapCount);
			((CStatic *)GetDlgItem(IDC_STATIC_MAPINFO))->SetWindowText("\n "+m_strMapName+"\n 作者:"+m_strAuthorName);
		}
		else
		{
			LoadMap(TRUE);
			m_mapInfo[m_curMapIndex].strMapName=m_strMapName;
			m_mapInfo[m_curMapIndex].strAuthorName=m_strAuthorName;
			m_comboMap.DeleteString(m_curMapIndex);
			m_comboMap.InsertString(m_curMapIndex,m_strMapName);
			m_comboMap.SetCurSel(m_curMapIndex);
		}

		//编辑按钮可用
		m_boxWall.SetEnable();
		m_boxGround.SetEnable();
		m_boxHead.SetEnable();
		m_boxBody.SetEnable();
		m_boxRear.SetEnable();
		m_boxFood.SetEnable();
		m_btnMode.SetWindowText("游戏模式");
		m_btnStart.SetWindowText("保存地图");
		
		m_boxWall.SetBitmap(m_wall[m_curWall]);
		m_boxGround.SetBitmap(m_ground[m_curGround]);
		m_boxBody.SetBitmap(m_body[m_curBody]);
		m_boxRear.SetBitmap(m_rear[m_curRear]);
		m_boxFood.SetBitmap(m_food[m_curFood]);
		SetSelectBox(IDC_BOXWALL);
		
		//游戏区方块可用(即可插入器物)
		for(int i=1;i<19;i++)
			for(int j=1;j<19;j++)
				if(m_box[j][i].GetType()!=TYPE_SNAKE)
					m_box[j][i].SetEnable(TRUE);
	}
	else//设计模式(返回游戏)
	{
		//提示改动
		if(m_bMapModify)
		{
			int nResult=MessageBox("地图已做改动,是否要保存?",NULL,MB_YESNOCANCEL);
			if(IDYES==nResult)
			{
				if(m_foodCount==0||m_wallCount==0)
				{
					MessageBox("请至少添加一块墙和一个食物!");
					return ;
				}
				if(m_bNewMap)
				{
					MapInfoAdd();
					m_bNewMap=FALSE;
				}
				else
					MapInfoEdit();
				MessageBox("保存成功!");
			}
			else if(IDNO==nResult)
			{
				if(m_bNewMap)
				{
					m_comboMap.DeleteString(m_mapCount);
					m_comboMap.SetCurSel(m_curMapIndex);
				}
			}
			else
			{
				return ;
			}
			m_bMapModify=FALSE;
		}
		else
		{
			if(m_bNewMap)
			{
				m_comboMap.DeleteString(m_mapCount);
				m_comboMap.SetCurSel(m_curMapIndex);
			}
		}
		//按钮不可用
		m_bMode=MODE_GAME;
		m_boxWall.SetEnable(FALSE);
		m_boxGround.SetEnable(FALSE);
		m_boxHead.SetEnable(FALSE);
		m_boxBody.SetEnable(FALSE);
		m_boxRear.SetEnable(FALSE);
		m_boxFood.SetEnable(FALSE);
		m_btnMode.SetWindowText("设计模式");
		m_btnStart.SetWindowText("开始游戏");
		LoadMap();
		for(int i=1;i<19;i++)
			for(int j=1;j<19;j++)
				if(m_box[j][i].GetType()!=TYPE_SNAKE)
					m_box[j][i].SetEnable(FALSE);
	}
}

void CGreedySnakeDlg::OnBtnAbout() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

//注册表初始化
void CGreedySnakeDlg::RegInit()
{
	HKEY hKey;
	LONG result=RegOpenKey(HKEY_LOCAL_MACHINE,"software\\DashengSoft\\GreedySnake",&hKey);
	if(result==ERROR_SUCCESS)
	{
		RegRead();
		MapInfoRead();
	}
	else
	{
		m_strMapInfo="默认地图&大圣&0&0&0&0&0#";
		m_strFoodInfo="125,0&208,3&97,5&208,7&87,7&297,7&305,7&312,7&212,7&95,7&38,7&62,7&301,7&368,7&377,7&164,7&131,7&197,7&71,7#";
		m_strWallInfo="146&126&195&68&238&166&167&168&169&170&190&210&230&229&228&227&226&215&235&236&237&88&108&109&110&111&112&113&133&67&66&65&64&63&83&103&203&223&243&263&343&344&323&355&354&334&314&294&353&352&351&356&57&56&76&77&136&137&138&157&307&308&309&288&328&161&32&52&208#";
		m_curMapIndex=0;
		MapInfoRead();
		RegWrite();
	}
}

//注册表读取
void CGreedySnakeDlg::RegRead()
{
	HKEY hKey;
	DWORD len,type;

	RegOpenKey(HKEY_LOCAL_MACHINE,"software\\DashengSoft\\GreedySnake\\AppParam",&hKey);

	len=4;
	type=REG_DWORD;
	RegQueryValueEx(hKey,"CurMapIndex",0,&type,(BYTE*)&m_curMapIndex,&len);

	len=0;
	type=REG_SZ;
	RegQueryValueEx(hKey,"MapInfo",0,&type,NULL,&len);
	if(len>0)
	{
		char *pBuf=new char[len];
		RegQueryValueEx(hKey,"MapInfo",0,&type,(LPBYTE)pBuf,&len);
		m_strMapInfo=pBuf;
	}

	len=0;
	type=REG_SZ;
	RegQueryValueEx(hKey,"FoodInfo",0,&type,NULL,&len);
	if(len>0)
	{
		char *pBuf2=new char[len];
		RegQueryValueEx(hKey,"FoodInfo",0,&type,(LPBYTE)pBuf2,&len);
		m_strFoodInfo=pBuf2;
	}

	len=0;
	type=REG_SZ;
	RegQueryValueEx(hKey,"WallInfo",0,&type,NULL,&len);
	if(len>0)
	{
		char *pBuf3=new char[len];
		RegQueryValueEx(hKey,"WallInfo",0,&type,(LPBYTE)pBuf3,&len);
		m_strWallInfo=pBuf3;
	}
	
	RegCloseKey(hKey);
}
//注册表写入
void CGreedySnakeDlg::RegWrite()
{
	HKEY hKey;
	DWORD len;

	RegCreateKey(HKEY_LOCAL_MACHINE,"software\\DashengSoft\\GreedySnake\\AppInfo",&hKey);
	RegSetValueEx(hKey,"AppName",0,REG_SZ,(CONST BYTE*)"贪吃蛇游戏",strlen("贪吃蛇游戏"));
	RegSetValueEx(hKey,"Author",0,REG_SZ,(CONST BYTE*)"大圣",strlen("大圣"));
	RegSetValueEx(hKey,"Version",0,REG_SZ,(CONST BYTE*)"v0.1版",strlen("v0.1版"));
	RegSetValueEx(hKey,"Date",0,REG_SZ,(CONST BYTE*)"2008.11.08",strlen("2008.11.08"));
	
	RegCreateKey(HKEY_LOCAL_MACHINE,"software\\DashengSoft\\GreedySnake\\AppParam",&hKey);
	RegSetValueEx(hKey,"CurMapIndex",0,REG_DWORD,(CONST BYTE*)&m_curMapIndex,4);
	len=m_strMapInfo.GetLength();
	if(len>0)
	{
		char *pBuf=new char[len+1];
		pBuf=m_strMapInfo.GetBuffer(len);
		RegSetValueEx(hKey,"MapInfo",0,REG_SZ,(CONST BYTE*)pBuf,len+1);
	}
	else
	{
		RegSetValueEx(hKey,"MapInfo",0,REG_SZ,(CONST BYTE*)"",strlen(""));
	}

	len=m_strFoodInfo.GetLength();
	if(len>0)
	{
		char *pBuf=new char[len+1];
		pBuf=m_strFoodInfo.GetBuffer(len);
		RegSetValueEx(hKey,"FoodInfo",0,REG_SZ,(CONST BYTE*)pBuf,len+1);
	}
	else
	{
		RegSetValueEx(hKey,"FoodInfo",0,REG_SZ,(CONST BYTE*)"",strlen(""));
	}

	len=m_strWallInfo.GetLength();
	if(len>0)
	{
		char *pBuf=new char[len+1];
		pBuf=m_strWallInfo.GetBuffer(len);
		RegSetValueEx(hKey,"WallInfo",0,REG_SZ,(CONST BYTE*)pBuf,len+1);
	}
	else
	{
		RegSetValueEx(hKey,"WallInfo",0,REG_SZ,(CONST BYTE*)"",strlen(""));
	}
	
	RegCloseKey(hKey);
}

void CGreedySnakeDlg::MapInfoRead()
{
	if(!m_strMapInfo.IsEmpty())
	{
		CStringArray aryInfo,aryItem;
		aryInfo.RemoveAll();
		m_mapCount=CCommon::SplitString(m_strMapInfo,'#',aryInfo);
		for(int i=0;i<m_mapCount;i++)
		{
			aryItem.RemoveAll();
			CCommon::SplitString(aryInfo.GetAt(i),'&',aryItem);
			m_mapInfo[i].strMapName=aryItem.GetAt(0);
			m_mapInfo[i].strAuthorName=aryItem.GetAt(1);
			m_mapInfo[i].curWall=atoi(aryItem.GetAt(2));
			m_mapInfo[i].curGround=atoi(aryItem.GetAt(3));
			m_mapInfo[i].curHead=atoi(aryItem.GetAt(4));
			m_mapInfo[i].curBody=atoi(aryItem.GetAt(5));
			m_mapInfo[i].curRear=atoi(aryItem.GetAt(6));
			m_comboMap.AddString(aryItem.GetAt(0));
		}
	}
	else
		return;
	m_comboMap.SetCurSel(m_curMapIndex);

	if(!m_strFoodInfo.IsEmpty())
	{
		CStringArray aryInfo,aryItem,arySub;
		aryInfo.RemoveAll();
		CCommon::SplitString(m_strFoodInfo,'#',aryInfo);
		for(int i=0;i<m_mapCount;i++)
		{
			aryItem.RemoveAll();
			m_mapInfo[i].foodCount=CCommon::SplitString(aryInfo.GetAt(i),'&',aryItem);
			for(int j=0;j<m_mapInfo[i].foodCount;j++)
			{
				arySub.RemoveAll();
				CCommon::SplitString(aryItem.GetAt(j),',',arySub);
				m_mapInfo[i].foodInfo[j].nPos=atoi(arySub.GetAt(0));
				m_mapInfo[i].foodInfo[j].nType=atoi(arySub.GetAt(1));
			}
		}
	}
	
	if(!m_strWallInfo.IsEmpty())
	{
		CStringArray aryInfo,aryItem,arySub;
		aryInfo.RemoveAll();
		CCommon::SplitString(m_strWallInfo,'#',aryInfo);
		for(int i=0;i<m_mapCount;i++)
		{
			aryItem.RemoveAll();
			m_mapInfo[i].wallCount=CCommon::SplitString(aryInfo.GetAt(i),'&',aryItem);
			for(int j=0;j<m_mapInfo[i].wallCount;j++)
			{
				arySub.RemoveAll();
				CCommon::SplitString(aryItem.GetAt(j),',',arySub);
				m_mapInfo[i].wallInfo[j]=atoi(arySub.GetAt(0));
			}
		}
	}
}

void CGreedySnakeDlg::MapInfoDel()
{
	int i,j;
	for(i=m_curMapIndex;i<m_mapCount-1;i++)
	{		
		m_mapInfo[m_curMapIndex].strMapName=m_mapInfo[m_curMapIndex+1].strMapName;
		m_mapInfo[m_curMapIndex].strAuthorName=m_mapInfo[m_curMapIndex+1].strAuthorName;
		m_mapInfo[m_curMapIndex].curWall=m_mapInfo[m_curMapIndex+1].curWall;
		m_mapInfo[m_curMapIndex].curGround=m_mapInfo[m_curMapIndex+1].curGround;
		m_mapInfo[m_curMapIndex].curHead=m_mapInfo[m_curMapIndex+1].curHead;
		m_mapInfo[m_curMapIndex].curBody=m_mapInfo[m_curMapIndex+1].curBody;
		m_mapInfo[m_curMapIndex].curRear=m_mapInfo[m_curMapIndex+1].curRear;
		m_mapInfo[m_curMapIndex].foodCount=m_mapInfo[m_curMapIndex+1].foodCount;
		m_mapInfo[m_curMapIndex].wallCount=m_mapInfo[m_curMapIndex+1].wallCount;
		CopyFoodInfo(m_mapInfo[m_curMapIndex+1].foodInfo,m_mapInfo[m_curMapIndex].foodInfo,m_mapInfo[m_curMapIndex+1].foodCount);
		CopyWallInfo(m_mapInfo[m_curMapIndex+1].wallInfo,m_mapInfo[m_curMapIndex].wallInfo,m_mapInfo[m_curMapIndex+1].wallCount);
	}
	m_mapCount--;

	//组合字符串
	m_strMapInfo="";
	m_strFoodInfo="";
	m_strWallInfo="";
	CString str;
	for(i=0;i<m_mapCount;i++)
	{
		m_strMapInfo+=m_mapInfo[i].strMapName+"&"+m_mapInfo[i].strAuthorName+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curWall,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curGround,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curHead,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curBody,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curRear,2)+"#";
		
		for(j=0;j<m_mapInfo[i].foodCount;j++)
			m_strFoodInfo+=CCommon::IntToStr(m_mapInfo[i].foodInfo[j].nPos,3)+","+
			CCommon::IntToStr(m_mapInfo[i].foodInfo[j].nType,2)+"&";
		m_strFoodInfo=m_strFoodInfo.Left(m_strFoodInfo.GetLength()-1)+"#";
		
		for(j=0;j<m_mapInfo[i].wallCount;j++)
			m_strWallInfo+=CCommon::IntToStr(m_mapInfo[i].wallInfo[j],3)+"&";
		m_strWallInfo=m_strWallInfo.Left(m_strWallInfo.GetLength()-1)+"#";
	}
	
	m_comboMap.DeleteString(m_curMapIndex--);
	m_comboMap.SetCurSel(m_curMapIndex);
	LoadMap();
}

void CGreedySnakeDlg::MapInfoEdit()
{
	//地图信息
	m_mapInfo[m_curMapIndex].strMapName=m_strMapName;
	m_mapInfo[m_curMapIndex].strAuthorName=m_strAuthorName;
	m_mapInfo[m_curMapIndex].curWall=m_curWall;
	m_mapInfo[m_curMapIndex].curGround=m_curGround;
	m_mapInfo[m_curMapIndex].curHead=m_curHead;
	m_mapInfo[m_curMapIndex].curBody=m_curBody;
	m_mapInfo[m_curMapIndex].curRear=m_curRear;

	m_mapInfo[m_curMapIndex].foodCount=m_foodCount;
	m_mapInfo[m_curMapIndex].wallCount=m_wallCount;
	CopyFoodInfo(m_foodInfo,m_mapInfo[m_curMapIndex].foodInfo,m_foodCount);
	CopyWallInfo(m_wallInfo,m_mapInfo[m_curMapIndex].wallInfo,m_wallCount);

	//组合字符串
	m_strMapInfo="";
	m_strFoodInfo="";
	m_strWallInfo="";
	CString str;
	int i,j;
	for(i=0;i<m_mapCount;i++)
	{
		m_strMapInfo+=m_mapInfo[i].strMapName+"&"+m_mapInfo[i].strAuthorName+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curWall,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curGround,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curHead,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curBody,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_mapInfo[i].curRear,2)+"#";

		for(j=0;j<m_mapInfo[i].foodCount;j++)
			m_strFoodInfo+=CCommon::IntToStr(m_mapInfo[i].foodInfo[j].nPos,3)+","+
				CCommon::IntToStr(m_mapInfo[i].foodInfo[j].nType,2)+"&";
		m_strFoodInfo=m_strFoodInfo.Left(m_strFoodInfo.GetLength()-1)+"#";

		for(j=0;j<m_mapInfo[i].wallCount;j++)
			m_strWallInfo+=CCommon::IntToStr(m_mapInfo[i].wallInfo[j],3)+"&";
		m_strWallInfo=m_strWallInfo.Left(m_strWallInfo.GetLength()-1)+"#";
	}

	m_comboMap.DeleteString(m_curMapIndex);
	m_comboMap.InsertString(m_curMapIndex,m_strMapName);
	m_comboMap.SetCurSel(m_curMapIndex);
}

void CGreedySnakeDlg::MapInfoAdd(BOOL bInit)
{
	//地图信息
	m_mapInfo[m_mapCount].strMapName=m_strMapName;
	m_mapInfo[m_mapCount].strAuthorName=m_strAuthorName;
	m_mapInfo[m_mapCount].curWall=m_curWall;
	m_mapInfo[m_mapCount].curGround=m_curGround;
	m_mapInfo[m_mapCount].curHead=m_curHead;
	m_mapInfo[m_mapCount].curBody=m_curBody;
	m_mapInfo[m_mapCount].curRear=m_curRear;

	m_mapInfo[m_mapCount].foodCount=m_foodCount;
	m_mapInfo[m_mapCount].wallCount=m_wallCount;
	CopyFoodInfo(m_foodInfo,m_mapInfo[m_mapCount].foodInfo,m_foodCount);
	CopyWallInfo(m_wallInfo,m_mapInfo[m_mapCount].wallInfo,m_wallCount);

	m_mapCount++;
	if(!bInit)
	{
		//组合字符串
		m_strMapInfo+=m_strMapName+"&";
		m_strMapInfo+=m_strAuthorName+"&";
		m_strMapInfo+=CCommon::IntToStr(m_curWall,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_curGround,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_curHead,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_curBody,2)+"&";
		m_strMapInfo+=CCommon::IntToStr(m_curRear,2)+"#";

		for(int i=0;i<m_foodCount;i++)
			m_strFoodInfo+=CCommon::IntToStr(m_foodInfo[i].nPos,3)+","+CCommon::IntToStr(m_foodInfo[i].nType,2)+"&";
		m_strFoodInfo=m_strFoodInfo.Left(m_strFoodInfo.GetLength()-1)+"#";

		for(int i=0;i<m_wallCount;i++)
			m_strWallInfo+=CCommon::IntToStr(m_wallInfo[i],3)+"&";
		m_strWallInfo=m_strWallInfo.Left(m_strWallInfo.GetLength()-1)+"#";

		m_curMapIndex=m_mapCount-1;
	}
}

CPoint CGreedySnakeDlg::IntToPoint(int pos)
{
	CPoint point;
	point.x=pos%20;
	point.y=pos/20;
	return point;
}

int CGreedySnakeDlg::PointToInt(int x,int y)
{
	return x+y*20;
}

int CGreedySnakeDlg::PointToInt(CPoint point)
{
	return point.x+point.y*20;
}

void CGreedySnakeDlg::ShowMap()
{
	//输出地板
	ShowGround();
	//输出墙
	ShowWall();
	//输出食物
	ShowFood();
	//输出蛇
	SnakeInit();
	ShowSnake();
}

void CGreedySnakeDlg::LoadMap(BOOL bEditName)
{
	if(m_mapCount==0||m_curMapIndex>=m_mapCount)
	{
		MessageBox("加载地图失败!");
		return ;
	}

	if(!bEditName)
	{
		m_strMapName=m_mapInfo[m_curMapIndex].strMapName;
		m_strAuthorName=m_mapInfo[m_curMapIndex].strAuthorName;
	}
	m_curWall=m_mapInfo[m_curMapIndex].curWall;
	m_curGround=m_mapInfo[m_curMapIndex].curGround;
	m_curHead=m_mapInfo[m_curMapIndex].curHead;
	m_curBody=m_mapInfo[m_curMapIndex].curBody;
	m_curRear=m_mapInfo[m_curMapIndex].curRear;
	m_foodCount=m_mapInfo[m_curMapIndex].foodCount;
	m_wallCount=m_mapInfo[m_curMapIndex].wallCount;
	CopyFoodInfo(m_mapInfo[m_curMapIndex].foodInfo,m_foodInfo,m_foodCount);
	CopyWallInfo(m_mapInfo[m_curMapIndex].wallInfo,m_wallInfo,m_wallCount);
	
	((CStatic *)GetDlgItem(IDC_STATIC_MAPINFO))->SetWindowText("\n "+m_strMapName+"\n 作者:"+m_strAuthorName);
	ShowMap();
}

void CGreedySnakeDlg::NewMap(BOOL bInit)
{
	if(m_mapCount>=20)
	{
		MessageBox("地图已满,请删掉一些再新建!");
		return ;
	}
	m_curWall=0;
	m_curGround=0;
	m_curHead=0;
	m_curBody=0;
	m_curRear=0;
	m_foodCount=0;
	m_wallCount=0;
}

void CGreedySnakeDlg::CopyFoodInfo(FoodInfo * srcFoodInfo, FoodInfo * desFoodInfo, int srcCount)
{
	for(int i=0;i<srcCount;i++)
	{
		desFoodInfo[i].nPos=srcFoodInfo[i].nPos;
		desFoodInfo[i].nType=srcFoodInfo[i].nType;
	}
}

void CGreedySnakeDlg::CopyWallInfo(WallInfo * srcWallInfo, WallInfo * desWallInfo, int srcCount)
{
	for(int i=0;i<srcCount;i++)
	{
		desWallInfo[i]=srcWallInfo[i];
	}
}

void CGreedySnakeDlg::SnakeInit()
{
	m_snake.ListInit();
	m_snake.rear->data=CPoint(1,1);
	m_snake.head->data=CPoint(2,1);
	m_snake.ListInsert(CPoint(3,1));
	m_snake.ListInsert(CPoint(4,1));
	m_snake.ListInsert(CPoint(5,1));
	m_snake.ListInsert(CPoint(6,1));
	m_snake.ListInsert(CPoint(7,1));
	m_snake.ListInsert(CPoint(8,1));
	m_snake.ListInsert(CPoint(9,1));
	
	m_curDirection=MOVE_RIGHT;
	m_nSnakeLen=7;
	((CStatic *)GetDlgItem(IDC_STATIC_LENGTH))->SetWindowText(CCommon::IntToStr(m_nSnakeLen,3,true));

}

void CGreedySnakeDlg::OnSelchangeComboMap() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	LoadMap();
}

void CGreedySnakeDlg::SetSelectBox(UINT nBoxID)
{
	switch(nBoxID)
	{
	case IDC_BOXWALL:
		m_boxWall.SetSelect(TRUE);
		m_boxFood.SetSelect(FALSE);
		m_boxGround.SetSelect(FALSE);
		m_nAdd=IDC_BOXWALL;
		break;
	case IDC_BOXFOOD:
		m_boxWall.SetSelect(FALSE);
		m_boxFood.SetSelect(TRUE);
		m_boxGround.SetSelect(FALSE);
		m_nAdd=IDC_BOXFOOD;
		break;
	case IDC_BOXGROUND:
		m_boxWall.SetSelect(FALSE);
		m_boxFood.SetSelect(FALSE);
		m_boxGround.SetSelect(TRUE);
		m_nAdd=IDC_BOXGROUND;
		break;
	case NULL:
		m_boxWall.SetSelect(FALSE);
		m_boxFood.SetSelect(FALSE);
		m_boxGround.SetSelect(FALSE);
		m_nAdd=NULL;
		break;
	}
}

void CGreedySnakeDlg::GameOver()
{
	m_bStart=FALSE;
	m_btnStart.SetWindowText("开始游戏");
	m_btnMode.EnableWindow(TRUE);
	MessageBox("很抱歉,闯关失败!");
}

HBRUSH CGreedySnakeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor==CTLCOLOR_DLG)
		return m_hBkBrush;

	int nID=pWnd->GetDlgCtrlID();
	switch(nID)
	{
	case IDC_STATIC_TIME:
	case IDC_STATIC_LENGTH:
	case IDC_STATIC_MAPINFO:
	case IDC_BTN_START:
	case IDC_BTN_MODE:
	case IDC_BTN_ABOUT:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,255)); 
		return m_hStaticBrush;
		break;
	case IDC_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,128));
		return m_hBkBrush;
		break;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CGreedySnakeDlg::RandFood()
{
	int r;
	CPoint pt;
	srand((unsigned)time(NULL));//随机种子
	r=(int)rand();
	r=r%m_foodCount;
	pt=IntToPoint(m_foodInfo[r].nPos);
	if(m_box[pt.x][pt.y].GetType()==TYPE_GROUND)
	{
		m_box[pt.x][pt.y].SetBitmap(m_food[m_foodInfo[r].nType],m_ground[m_curGround]);
		m_box[pt.x][pt.y].SetType(TYPE_FOOD);
		m_bFoodExist=TRUE;
	}
}

void CGreedySnakeDlg::OnBtnDelmap() 
{
	// TODO: Add your control notification handler code here
	if(m_curMapIndex==0)
	{
		MessageBox("默认地图不能删除!");
		return ;
	}
	m_overID=0;
	if(IDYES==MessageBox("你确认要删除该地图吗?",NULL,MB_YESNO))
	{
		MapInfoDel();
	}
}

void CGreedySnakeDlg::FoodEdit(CPoint point)
{
	int nIndex=-1;
	for(int i=0;i<m_foodCount;i++)
		if(m_foodInfo[i].nPos==PointToInt(point))
		{
			nIndex=i;
			break;
		}
	if(nIndex<0) return ;
	m_foodInfo[nIndex].nType=m_curFood;
}

void CGreedySnakeDlg::FoodDel(CPoint point)
{
	int nIndex=-1;
	for(int i=0;i<m_foodCount;i++)
		if(m_foodInfo[i].nPos==PointToInt(point))
		{
			nIndex=i;
			break;
		}
	if(nIndex<0) return ;
	for(int i=nIndex;i<m_foodCount-1;i++)
	{
		m_foodInfo[i].nPos=m_foodInfo[i+1].nPos;
		m_foodInfo[i].nType=m_foodInfo[i+1].nType;
	}
	m_foodCount--;
}

void CGreedySnakeDlg::WallDel(CPoint point)
{
	int nIndex=-1;
	for(int i=0;i<m_wallCount;i++)
		if(m_wallInfo[i]==PointToInt(point))
		{
			nIndex=i;
			break;
		}
	if(nIndex<0) return ;
	for(int i=nIndex;i<m_wallCount-1;i++)
	{
		m_wallInfo[i]=m_wallInfo[i+1];
	}
	m_wallCount--;
}
