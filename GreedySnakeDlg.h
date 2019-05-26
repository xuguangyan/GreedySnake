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
	//ʳ����Ϣ�ṹ
	typedef struct
	{
		int nPos;
		int nType;
	}FoodInfo;

	//Χǽ��Ϣ�ṹ
	typedef int WallInfo;

	//��ͼ��Ϣ�ṹ
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

	//����Ϣ�ṹ(������)
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
	void GameOver();//��Ϸ����
	void SetSelectBox(UINT nBoxID);//(���ģʽ��)ѡ��Ҫ��������ͷ���(ǽ\�ذ�\ʳ��)
	void ShowMap();//��ʾ��ͼ
	void LoadMap(BOOL bEditName=FALSE);//���ص�ͼ
	void NewMap(BOOL bInit=FALSE);//�½���ͼ
	int PointToInt(int x,int y);//�㵽����
	int PointToInt(CPoint point);//�㵽����
	CPoint IntToPoint(int pos);//���ε���
	void WallDel(CPoint point);//ɾ��ǽ��Ϣ
	void FoodDel(CPoint point);//ɾ��ʳ����Ϣ
	void FoodEdit(CPoint point);//�༭ʳ����Ϣ
	void MapInfoDel();//ɾ����ͼ��Ϣ
	void MapInfoRead();//��ȡ��ͼ��Ϣ
	void MapInfoEdit();//�༭��ͼ��Ϣ
	void MapInfoAdd(BOOL bInit=FALSE);//�����ͼ��Ϣ
	void ShowGround();//��ʾ�ذ�
	void ShowWall();//��ʾΧǽ
	void ShowHead();//��ʾ��ͷ
	void ShowBody();//��ʾ����
	void ShowRear();//��ʾ��β
	void ShowFood();//��ʾʳ��
	void ShowSnake();//��ʾ��
	void MoveSnake(int direction);//�ƶ���
	void SnakeInit();//��ʼ����
	void RegInit();//ע����ʼ��
	void RegRead();//ע����ȡ
	void RegWrite();//ע���д��
	void CopyFoodInfo(FoodInfo * srcFoodInfo,FoodInfo * desFoodInfo,int srcCount);//����ʳ����Ϣ
	void CopyWallInfo(WallInfo * srcWallInfo, WallInfo * desWallInfo, int srcCount);//����Χǽ��Ϣ
private:
	BOOL m_bFoodExist;
	CPoint m_overPoint;//������(��ͷ��ײ��)
	UINT m_overID;//����ID(��ײ�㷽��ͼƬID)
	void RandFood();//(��FoodInfo�ṹ��)�������ʳ��
	HBRUSH m_hBkBrush;//���ڱ���ˢ
	HBRUSH m_hStaticBrush;//��̬�ؼ�ˢ
	int m_nTime;//��ʱ
	int m_nSnakeLen;//�߳�
	BOOL m_bNewMap;//�½���ͼ��־
	UINT m_nAdd;//�������
	BOOL m_bMapModify;//�ѸĶ���־

	BOOL m_bStart;//��ʼ��־
	BOOL m_bMode;//ģʽ��־(��Ϸ/���ģʽ)
	int m_curDirection;//��ǰ���з���

	//�༭�÷���
	CBox m_boxWall;
	CBox m_boxGround;
	CBox m_boxHead;
	CBox m_boxBody;
	CBox m_boxRear;
	CBox m_boxFood;
	//����Ϸ������
	CBox m_box[20][20];
	//������
	CSnake m_snake;

	//��������(ÿ��10����ʽ)
	UINT m_wall[10],m_ground[10],m_head[10],m_rear[10],m_body[10],m_food[10];
	int m_curWall,m_curGround,m_curHead,m_curRear,m_curBody,m_curFood;
	CString m_strMapName,m_strAuthorName;

	FoodInfo m_foodInfo[300];//ʳ����Ϣ
	WallInfo m_wallInfo[300];//Χǽ��Ϣ
	MapInfo m_mapInfo[20];//��ͼ��Ϣ
	int m_foodCount,m_wallCount,m_mapCount;
	CString m_strFoodInfo,m_strWallInfo,m_strMapInfo;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREEDYSNAKEDLG_H__AA4816BA_D6AC_4EB9_87C6_B4EBAF39FB9C__INCLUDED_)
