// DLinList.cpp: implementation of the DLinList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GreedySnake.h"
#include "DLinList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//初始化
DLinList::DLinList()
{
	if((head=(Node *)malloc(sizeof(Node)))==NULL) exit(1);
	if((rear=(Node *)malloc(sizeof(Node)))==NULL) exit(1);
	head->prior=NULL;
	head->next=rear;
	rear->prior=head;
	rear->next=NULL;
}

//撤消动态申请的空间
DLinList::~DLinList()
{
	Node * p=head,* q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}

//初始化链表
int DLinList::ListInit()
{
	Node * p=head->next,* q;
	while(p!=rear)
	{
		q=p;
		p=p->next;
		free(q);
	}
	head->next=rear;
	rear->prior=head;
	return 1;
}

//求数据元素个数(不含头尾)
int DLinList::ListLength()
{
	Node * p=head;
	int size=0;
	while(p->next!=rear)
	{
		p=p->next;
		size++;
	}
	return size;
}

//插入数据元素(头部插入)
int DLinList::ListInsert(DataType x)
{
	Node *p;
	if((p=(Node *)malloc(sizeof(Node)))==NULL) return 0;
	p->data=head->data;
	head->data=x;
	p->prior=head;
	p->next=head->next;
	head->next->prior=p;
	head->next=p;
	return 1;
}

//删除数据元素(尾部删除)
int DLinList::ListDelete(DataType * x)
{
	Node * p;
	if(rear->prior==head) return 0;
	p=rear;
	rear=rear->prior;
	rear->next=NULL;
	*x=p->data;
	free(p);
	return 1;
}
