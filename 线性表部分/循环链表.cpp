#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
void showerror(string s)
{
	cout<<s<<endl;
}
LNode* GetElem(LinkList L,int i)
{//访问第i个节点
	if(L==NULL||L->next==L||i<1) return NULL;
	LNode *p=L;
	int j=0;
	while(p->next!=L&&j<i)
	{
		p=p->next;
		j++;
	}
	return (j==i)?p:NULL;
}
bool LinkListRearInsert(LinkList &L)
{
	L=new LNode;
	if(L==NULL) {
		showerror("内存不足");
		return false;
	}
	L->next=L;//指向自己
	
	ElemType x;
	LNode *s;
	LNode *r=L;
	while(cin>>x,x!=0)
	{
		s=new LNode;
		s->data=x;
		r->next=s;
		r=s;
	}
	r->next=L;
	return true;
}
bool LinkListHeadInsert(LinkList &L)
{
	L=new LNode;
	if(L==NULL)
	{
		showerror("Memory ERROR");
		return false;
	}
	L->next=L;
	
	ElemType x;
	LNode *s;
	while(cin>>x,x!=0)
	{
		s=new LNode;
		s->data=x;
	
		s->next=L->next;
		L->next=s;
	}
	return true;
}
bool isEmpty(LinkList L)
{
	if(L->next==L)
	{
		return true;
	}
	return false;
}
void PrintLinkList(LinkList L)
{

	if(isEmpty(L)){
		cout<<"空的"<<endl;
		return ;
	}
	LNode *p=L->next;
	while(p!=L)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	puts("");
	return;
}

bool DeleteLinkListNode(LinkList &L,int i,ElemType &e)
{
	if(i<1) {
		e=0;
		showerror("删除位置不合法");
		return false;
	}
	if(L==NULL||L->next==L){
		e=0;
		showerror("空表！不可删除");
		return false;
	}
	LNode *p=GetElem(L,i-1);
	if(p==NULL||p->next==L)
	{
		e=0;
		showerror("删除位置不合法");
		return false;
	}

	LNode *q =p->next;
	e=q->data;
	if(q->next==L)
	{
		p->next=L;
	}
	else
	{
		p->next=q->next;
	}
	if(q==L->next)
	{
		L->next=q->next;
	}
	delete q;
	return true;
}
int main()
{
	LinkList L=NULL;
	LinkListHeadInsert(L);
	PrintLinkList(L);
	
	ElemType e;
	
	DeleteLinkListNode(L,3,e);
	DeleteLinkListNode(L,3,e);
	
	cout<<e<<endl;
	PrintLinkList(L);
	return 0;
}
