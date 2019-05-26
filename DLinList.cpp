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

//��ʼ��
DLinList::DLinList()
{
	if((head=(Node *)malloc(sizeof(Node)))==NULL) exit(1);
	if((rear=(Node *)malloc(sizeof(Node)))==NULL) exit(1);
	head->prior=NULL;
	head->next=rear;
	rear->prior=head;
	rear->next=NULL;
}

//������̬����Ŀռ�
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

//��ʼ������
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

//������Ԫ�ظ���(����ͷβ)
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

//��������Ԫ��(ͷ������)
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

//ɾ������Ԫ��(β��ɾ��)
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
