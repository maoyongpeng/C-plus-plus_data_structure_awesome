#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXSIZE=5;
typedef int ElemType;
//顺序栈的实现
typedef struct{
	ElemType *data;
	int maxsize=0;
	int top;//栈顶指针
}SqStack;
void InitStack(SqStack &s)
{
	s.data=new ElemType[MAXSIZE];
	s.maxsize=MAXSIZE;
	s.top=-1;
}
bool isEmpty(SqStack s)
{
	if(s.top==-1)
	{
		return true;
	}
	return false;
}
bool Push(SqStack &s,ElemType e)
{
	if(s.top==s.maxsize-1)
	{
		printf("栈内存已满,无法插入!~\n");
		return false;
	}
	s.data[++s.top]=e;
	return true;
}
bool Pop(SqStack &s,ElemType &e)
{
	if(isEmpty(s))
	{
		printf("栈为空，弹出操作无效!\n");
		return false;
	}
	e=s.data[s.top];
	s.top--;
	return true;
}
bool GetElem(SqStack s,ElemType &e)
{
	if(isEmpty(s))
	{
        printf("空栈，栈顶无元素!\n");
        return false;
	}
	e=s.data[s.top];
	return true;
}

int main()
{
	SqStack s;
	InitStack(s);
	ElemType x;
	while(cin>>x,x!=0)
	{
		Push(s,x);
	}
	while(s.top!=-1)
	{
		ElemType e=0;
		Pop(s,e);
		cout<<e<<endl;
	}
	
	return 0;
}
