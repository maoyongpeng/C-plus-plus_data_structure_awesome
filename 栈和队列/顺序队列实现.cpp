#include<iostream>
#include<cstdio>
#include<cstring>

//顺序存储
using namespace std;
const int MAXSIZE=15;
typedef int ElemType;
typedef struct{
	ElemType *data;
	int front,rear;
	//int size;
	//int tag;
}SqQueue;
//循环队列，静态数组存储
//牺牲一个存储单元判别队满/队空
void InitQueue(SqQueue &Q)
{
	Q.data=new ElemType[MAXSIZE];
	Q.front=0,Q.rear=0;
	//Q.size=0; 记录元素个数
	//Q.tag=0; 记录最后一次操作是删除还是插入
}
bool isFull(SqQueue Q)
{
	if((Q.rear+1)%MAXSIZE==Q.front)
	{//队尾指针的下一个位置为队头指针时已满
		return true;
	}
	return false;
//	if(Q.front==Q.rear&&Q.size==MAXSIZE)
//	{
//		return true;
//	}
//	return false;
//	if(Q.front==Q.rear&&Q.tag==1)
//	{
//		return true;
//	}
//	return false;
}
bool isEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
	{
		return true;
	}
	return false;
//	if(Q.front==Q.rear&&Q.size==0)
//	{
//		return true;
//	}
//	return false;
//	if(Q.front==Q.rear&&Q.tag==0)
//	{
//		return true;
//	}
//	return false;
}
bool EnQueue(SqQueue &Q,ElemType e)
{
	if(isFull(Q))
	{
		printf("队列已满，无法插入!\n");
		return false;
	}
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
//	Q.size++;
//	Q.tag=1;
	return true;
}
bool DeQueue(SqQueue &Q,ElemType &e)
{
	if(isEmpty(Q))
	{
		printf("队列为空，操作无效!\n");
		return false;
	}
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
//	Q.size--;
//	Q.tag=0;
	return true;
}
bool GetfrontElem(SqQueue Q,ElemType &e)
{
	if(isEmpty(Q))
	{
		printf("队列为空，操作无效!\n");

		return false;
	}
	e=Q.data[Q.front];
	return true;
}
int main()
{
	SqQueue Q;
	InitQueue(Q);
	ElemType x;
	while(cin>>x,x!=0)
	{
		EnQueue(Q,x);
	}
	ElemType e;
	while(!isEmpty(Q))
	{
		GetfrontElem(Q,e);
		cout<<e<<" ";
		DeQueue(Q,e);
	}
	
	return 0;
}
