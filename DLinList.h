// DLinList.h: interface for the DLinList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLINLIST_H__47FEEDAE_039E_4BEC_8557_22FF85B3DBCB__INCLUDED_)
#define AFX_DLINLIST_H__47FEEDAE_039E_4BEC_8557_22FF85B3DBCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef CPoint DataType;

//����˫����ṹ
typedef struct Data
{
	DataType data;
	struct Data * prior;
	struct Data * next;
}Node;

//����˫����
class DLinList  
{
public:
	DLinList();//��ʼ��
	virtual ~DLinList();//������̬����ռ�
	int ListInit();//��ʼ������
	int ListLength();//������Ԫ�ظ���
	int ListInsert(DataType x);//��������Ԫ��
	int ListDelete(DataType * x);//ɾ������Ԫ��
public:
	Node * head;
	Node * rear;
};

#endif // !defined(AFX_DLINLIST_H__47FEEDAE_039E_4BEC_8557_22FF85B3DBCB__INCLUDED_)
