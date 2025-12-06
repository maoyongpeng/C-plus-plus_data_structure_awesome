#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue{
	LinkNode *front,*rear;
	int length;//记录队列的长度
}LinkQueue;

//带头节点的实现
bool initQueue(LinkQueue &Q)
{
	Q.front=Q.rear=new LinkNode;
	if(Q.front==NULL)
	{
		printf("内存分配不足，退出!\n");
		return false;
	}
	Q.front->next=NULL;
	Q.length=0;
	cout<<"带头节点队列初始化成功"<<endl;
}
bool isEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
	{
		return true;
	}
	return false;
}
bool EnQueue(LinkQueue &Q,ElemType x)
{
	LinkNode* s=new LinkNode;
	if(s==NULL){
		printf("内存不足，无法创建新的节点!\n");
		return false;
	}
	s->next=NULL;
	s->data=x;
	Q.rear->next=s;
	Q.rear=s;
	Q.length++;
	return true;
}
bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if(Q.rear==Q.front)
	{
		printf("队列为空，删除无效!\n");
		return false;
	}
	LinkNode *p=Q.front->next;//指向首个数据节点
	x=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)//只有最后一个数据节点时
	{
		Q.rear=Q.front;//尾指针指向头节点
	}
	delete p;
	Q.length--;
	return true;
}
int GetQueueSize(LinkQueue Q)
{
	return Q.length;
}
void GetFrontElem(LinkQueue Q,ElemType &x)
{
	if(Q.rear==Q.front)
	{
		printf("队列为空，获取头部元素无效！\n");
		x=-1;
		return ;
	}
	LinkNode *p=Q.front->next;
	x=p->data;
	return;
}
void GetRearElem(LinkQueue Q,ElemType &x)
{
	if(Q.rear==Q.front)
	{
		printf("队列为空，获取尾部元素无效！\n");
		x=-1;
		return ;
	}
	x= Q.rear->data;
	return;
}

int main()
{
	LinkQueue Q;
	initQueue(Q);
	ElemType x;
	
	while(cin>>x,x!=0)
	{
		EnQueue(Q,x);
	}
	cout<<"队列元素数目:"<<GetQueueSize(Q)<<endl;
	ElemType fr;
	GetFrontElem(Q,fr);
	cout<<"此时队首元素为:"<<fr<<endl;
	
	ElemType ed;
	GetRearElem(Q,ed);
	cout<<"此时队尾元素为:"<<ed<<endl;
	while(!isEmpty(Q))
	{
		ElemType e;
		DeQueue(Q,e);
		cout<<e<<" ";
	}
	
	return 0;
}

//不带头节点的实现
//bool initQueue(LinkQueue &Q)
//{
//	Q.rear=Q.front=NULL;
//	Q.length=0;
//	cout<<"初始化不含头节点的队列成功!"<<endl;
//	return true;
//}
//bool isEmpty(LinkQueue Q)
//{
//	if(Q.rear==NULL&&Q.front==NULL)
//	{
//		return true;
//	}
//	return false;
//}
//bool EnQueue(LinkQueue &Q,ElemType e)
//{
//	LinkNode *s=new LinkNode;
//	if(s==NULL)
//	{
//		cout<<"内存不足，创建新节点失败!\n"<<endl;
//		return false;
//	}
//	s->data=e;
//	s->next=NULL;
//	
//	if(Q.front==NULL)
//	{
//		Q.front=s;
//		Q.rear=s;
//	}
//	else
//	{
//		Q.rear->next=s;
//		Q.rear=s;
//	}
//	Q.length++;
//	return true;
//}
//bool DeQueue(LinkQueue &Q,ElemType &e)
//{
//	if(isEmpty(Q))
//	{
//		cout<<"队列为空，出队操作无效!"<<endl;
//		return false;
//	}
//	LinkNode *p=Q.front;
//	e=p->data;
//	
//	
//	if(p==Q.rear)
//	{
//		Q.rear=NULL;
//		Q.front=NULL;
//	}
//	else
//	{
//		Q.front=p->next;
//	}
//	delete p;
//	Q.length--;
//	return true;
//}
//int GetQueueSize(LinkQueue Q)
//{
//	return Q.length;
//}
//bool GetFrontElem(LinkQueue Q,ElemType &x)
//{
//	if(isEmpty(Q))
//	{
//		cout<<"队列为空，获取队首元素无效!\n";
//		return false;
//	}
//	x=Q.front->data;
//	return true;
//}
//bool GetRearElem(LinkQueue Q,ElemType &x)
//{
//	if(isEmpty(Q))
//	{
//		cout<<"队列为空，获取队尾元素无效!\n";
//		return false;
//	}
//	x=Q.rear->data;
//	return true;
//}
//int main()
//{
//	LinkQueue Q;
//	initQueue(Q);
//	
//	ElemType x;
//	while(cin>>x,x!=0)
//	{
//		EnQueue(Q,x);
//	}
//	cout<<"元素数目为:"<<GetQueueSize(Q)<<endl;
//	ElemType f=-1000;
//	GetFrontElem(Q,f);
//	cout<<"获取队首元素为"<<f<<endl;
//	ElemType r=-1000;
//	GetRearElem(Q,r);
//	cout<<"获取队尾元素为"<<r<<endl;
//	
//	ElemType e;
//	while(!isEmpty(Q))
//	{
//		DeQueue(Q,e);
//		cout<<e<<" ";
//	}
//	return 0;
//}
