#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;
bool InitDLinkList(DLinkList &DL)
{
	//带头节点的
	DL=new DNode;
	if(DL==NULL) return false;//内存不足
	DL->prior=NULL;//头节点的前向指针为空
	DL->next=NULL;//初始化
	return true;
}

DNode* GetElem(DLinkList DL,int i)
{
	DNode*p=DL;
	int j=0;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}//找到第i个节点
	return p;
}
bool InsertNextNode(DNode *p,ElemType e)
{
	//在p节点后插入元素e
	if(p==NULL) return false;
	DNode* s=new DNode;//创建新的节点s
	s->data=e;
	s->next=p->next;
	if(p->next!=NULL)//p的下一个节点不为空的话，修改前向指针
	{
		p->next->prior=s;//p下一个节点的前向指针指向s
	}
	s->prior=p;//新节点的前向指针指向p
	p->next=s;//修改p的后一个节点为s
	return true;
}
bool DeleteNextNode(DNode *p,ElemType &e)
{
	if(p==NULL) return false;
	DNode *q=p->next;
	if(q==NULL) return false;//p没有下一个节点
    e=q->data;
	p->next=q->next;//修改p的下一个节点
	if(q->next!=NULL)//如果q的下个节点不为空，还有修改该节点的前向指针
	{
		q->next->prior=p;//q的下一个节点前向指针指向p
	}
	delete q;
	return true;
}
bool DLinkListInsert(DLinkList &DL,int i,ElemType e)
{
	if(i<1) return false;
	
	DNode *p=GetElem(DL,i-1);//找到第i-1个节点
	return InsertNextNode(p,e);
}
bool DLinkListDelete(DLinkList &DL,int i,ElemType &e)
{
	if(i<1) return false;
	DNode *p=GetElem(DL,i-1);
	return DeleteNextNode(p,e);
}
bool DLinkListRearInsert(DLinkList &DL)
{
	//带头节点的尾插法
	ElemType x;
	DL=new DNode;
	DL->prior=NULL;
	DL->next=NULL;
	DNode *s;
	DNode *r=DL;
	
	while(cin>>x,x!=0)
	{
		s=new DNode;
		s->data=x;
		s->next=NULL;
		
		s->prior=r;
		r->next=s;

		r=s;
	}
	return true;
}
bool DLinkListHeadInsert(DLinkList &DL)
{
	//带头节点的头插法
	DL=new DNode;
	DL->next=NULL;
	DL->prior=NULL;
	
	ElemType x;
	DNode* s;
	
	while(cin>>x,x!=0)
	{
		s=new DNode;
		s->data=x;

		s->next=DL->next;
		if(s->next!=NULL)
		{
			s->next->prior=s;
		}

		s->prior=DL;
		DL->next=s;
	}
	return true;
}
void BackPrint(DLinkList DL)
{//后向遍历
	DNode *p=DL->next;
	while(p!=NULL)
 	{
 		cout<<p->data<<" ";
 		p=p->next;
	}
	puts("");
}
void FrontPrint(DNode *p)
{
	DNode *t=p;
	while(t->prior!=NULL)
	{
		cout<<t->data<<" ";
		t=t->prior;
	}
	puts("");
}

int main()
{
	DLinkList DL=NULL;
	//InitDLinkList(DL);
	DLinkListRearInsert(DL);
	DLinkListInsert(DL,1,999);
	DLinkListInsert(DL,1,10000);
	BackPrint(DL);
	
	ElemType e;
	DLinkListDelete(DL,1,e);
	cout<<e<<endl;
	BackPrint(DL);
	
	
	DNode *p=GetElem(DL,4);//找到第i个节点
	FrontPrint(p);
	
	return 0;
}
