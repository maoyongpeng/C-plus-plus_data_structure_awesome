#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
void PrintList(LinkList L)
{//打印含头节点的
	LNode*p=L;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->data<<" ";
	}
	puts("");
}
void PrintPtrList(LinkList L)
{
	//打印仅含头指针的
	LNode *p=L;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	puts("");
}
LinkList Head_Insert(LinkList &L)//用于链表的逆置操作
{	//带头节点的头插法
    L=new LNode;//创建头节点
    L->next=NULL;//初始化
    
    LNode *s;//要插入的节点
    ElemType x;

    while(cin>>x,x!=0)
    {
    	s=new LNode;//创建新节点
    	s->data=x;
    	s->next=L->next;
    	L->next=s;
	}
	return L;
}
LinkList ptrHead_Insert(LinkList &L)
{
	//不带头节点的头插法 仅有头指针
	ElemType x;
	LNode *s;//创建的新节点
	while(cin>>x,x!=0)
	{
        s=new LNode;
		s->data=x;
		s->next=L;
		L=s;
	}
	return L;
}
LinkList Rear_Insert(LinkList &L)
{
	//带头节点的尾插法
	L=new LNode;//创建头节点
	L->next=NULL;//初始化
	
	LNode *s;//新的节点
	LNode *r=L;//表尾节点，标识链表结尾
	ElemType x;//插入的值
	while(cin>>x,x!=0)
	{
		s=new LNode;
		s->data=x;
		s->next=NULL;
		r->next=s;//将s节点放到新的表尾
		r=s;//更新表尾位置
	}
	//r->next=NULL;//尾部节点的下一个节点为NULL
	return L;
}
LinkList ptrRear_Insert(LinkList &L)
{
	//只有头指针的尾插法
	LNode*s;
	LNode*r=L;//L可能为nullptr
	ElemType x;
	while(cin>>x,x!=0)
	{
		s=new LNode;

		s->data=x;
        s->next=NULL;
        //特殊处理第一个插入的节点 ！！！
        if(r==NULL)
        {
        	L=s;//头指针指向新节点位置
		}
		else
		{
			r->next=s;//将新节点链到上一时刻的表尾下一处
		}
		r=s;//更新表尾指针
	}

	return L;
}
int main()
{
	LinkList L=NULL;//注意要初始化为NULL
//	Head_Insert(L);
//	PrintList(L);//头插法
//	ptrHead_Insert(L);
//	PrintPtrList(L);
//	Rear_Insert(L);
//	PrintList(L);//尾插法
	ptrRear_Insert(L);
	PrintPtrList(L);
	
	return 0;
}
