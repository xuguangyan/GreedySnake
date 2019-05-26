// DLinList.h: interface for the DLinList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLINLIST_H__47FEEDAE_039E_4BEC_8557_22FF85B3DBCB__INCLUDED_)
#define AFX_DLINLIST_H__47FEEDAE_039E_4BEC_8557_22FF85B3DBCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef CPoint DataType;

//定义双链表结构
typedef struct Data
{
	DataType data;
	struct Data * prior;
	struct Data * next;
}Node;

//定义双链表
class DLinList  
{
public:
	DLinList();//初始化
	virtual ~DLinList();//撤消动态申请空间
	int ListInit();//初始化链表
	int ListLength();//求数据元素个数
	int ListInsert(DataType x);//插入数据元素
	int ListDelete(DataType * x);//删除数据元素
public:
	Node * head;
	Node * rear;
};

#endif // !defined(AFX_DLINLIST_H__47FEEDAE_039E_4BEC_8557_22FF85B3DBCB__INCLUDED_)
