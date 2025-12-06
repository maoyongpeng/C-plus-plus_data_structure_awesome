#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
//链式实现
typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	LinkNode *next;
}LinkNode,*LiStack;
void initStack(LiStack &s)
{
	printf("初始化链栈成功!\n");
	s=NULL;//不带头节点
}
bool isEmpty(LiStack s)
{
	if(s==NULL)
	{
//		printf("栈为空\n");
		return true;
	}
	return false;
}
bool push(LiStack &s,ElemType e)
{
	LinkNode *t=new LinkNode;
	if(t==NULL)
	{
		printf("内存不足!\n");
		return false;
	}
	if(s==NULL)
	{
		s=new LinkNode;
		s->data=e;
		s->next=NULL;
	}
	else
	{
		t->data=e;
		t->next=s;
		s=t;
	}
	return true;
}
bool pop(LiStack &s,ElemType &e)
{
	if(isEmpty(s))
	{
		printf("Pop操作无效\n");
		return false;
	}
	LinkNode *p=s;
	e=s->data;
	s=p->next;
	delete p;
	return true;
}
ElemType GetElem(LiStack s)
{
	if(s==NULL)
	{
		printf("栈为空!\n");
		return 0;
	}
	return s->data;
}


int main()
{
	LiStack s;
	initStack(s);
	ElemType x;
	while(cin>>x,x!=0)
	{
		push(s,x);
	}
	ElemType e=0;
	while(!isEmpty(s))
	{
		
		e=GetElem(s);
		cout<<e<<" ";
		pop(s,e);
	}
	system("pause");
	
	return 0;
}
