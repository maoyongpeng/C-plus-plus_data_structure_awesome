
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef char TElemType;//树的数据元素类型 

TElemType Nil=' ';//空字符

 
/*链式二叉树存储结构*/
typedef struct BiTNode{
	TElemType data;//节点数据 
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;


typedef struct LinkNode{
	BiTree data;
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
	//cout<<"带头节点队列初始化成功"<<endl;
}
bool isEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
	{
		return true;
	}
	return false;
}
bool EnQueue(LinkQueue &Q,BiTree x)
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
bool DeQueue(LinkQueue &Q,BiTree &x)
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
