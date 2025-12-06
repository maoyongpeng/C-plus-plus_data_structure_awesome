#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

//采用带头节点的链表表示
typedef int ElemType;
typedef struct LNode{
	ElemType data;//这个节点的数据
	struct LNode* next;//下一个节点的存放地址
}LNode,*LinkList;//LNode* 访问的是节点   LinkList 则是链表的存放的首地址

bool InitLinkList(LinkList &L)
{
	//L=new LNode;//指向首个数据节点
	L=(LNode*)malloc(sizeof(LNode));//头节点,是头指针指向的节点
	if(L==NULL)//头节点分配失败
	{
		printf("内存不足!\n");
		return false;
	}
	L->next=NULL;//此时设置首个数据节点为NULL，等待插入操作
	return true;
}
bool IsEmpty(LinkList L)
{
	if(L->next==NULL)
	{
		return true;
	}
	return false;
}
int length(LinkList L)
{
	LNode* p=L;//指向头节点
	int cnt=0;
	while(p->next!=NULL)//头节点的下个节点单元不为空
	{
		p=p->next;//找下一个节点
		cnt++;
	}
	return cnt;
}
void PrintLinkList(LinkList L)
{
	LNode *p=L;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->data<<" ";
	}
	puts("");
}
bool LinkNextInsert(LNode *p,ElemType e)
{
	//在p节点后插入数据元素e
	if(p==NULL) return false;//p节点不存在
	LNode* s=new LNode;//创建节点s
	if(s==NULL) return false;//内存不足
	
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool LinkPriorInsert(LNode *p,ElemType e)
{
	//在p节点前面插入数据元素e
	if(p==NULL) return false;
	LNode *s=new LNode;
	if(s==NULL) return false;
	
	s->data=e;
	s->next=p->next;
	p->next=s;
	swap(s->data,p->data);//o(1)  巧妙的方法
	return true;
}
LNode* GetElem(LinkList L,int i)
{
	//寻找第i个节点  位序
	if(i<0) return NULL;
	int j=0;
	LNode *p=L;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}
LNode* LocateElem(LinkList L,ElemType e)
{
	//按照值寻找节点
	LNode*p=L->next;
	while(p!=NULL&&p->data!=e)//从首个数据节点开始寻找
	{
		p=p->next;
	}
	return p;
}

bool LinkInsert(LinkList &L,int i,ElemType e)
{
	//在链表的位序为i的位置插入元素
	LNode* p;//指向头节点
	if(i<1) return false;//位序小于1处不合法
//	int j=0;//寻找到第i-1节点,头节点为0号位置
//	while(p!=NULL&&j<i-1)
//	{
//		p=p->next;
//		j++;
//	}
    p=GetElem(L,i-1);//找第i-1节点
	
	/*
	LNode*s =new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;//后插
	*/
    return LinkNextInsert(p,e);//封装操作
}

bool LinkDelete(LinkList &L,int i,ElemType &e)
{
	//删除位序为i处的元素
	LNode*p;//指向当前节点
	
//	int j=0;//头节点为位序0
//	while(p!=NULL&&j<i-1)
//	{
//		p=p->next;
//		j++;//找到第i-1个节点位置
//	}
    p=GetElem(L,i-1);
    
	if(p==NULL||p->next==NULL)//删除位置不合法 p代表i-1位序处的节点  p==NULL 超出已有 位序范围  p->next==NULL 第i位序处没有节点
	{
		return false;
	}
	LNode* q=p->next;
	e=q->data;//返回删除节点的值
	p->next=q->next;
	delete q;
	return true;
}

int main()
{
	LinkList L;//创建指向链表的头指针
	InitLinkList(L);
	LinkInsert(L,1,13);
	LinkInsert(L,2,19);

	PrintLinkList(L);
	ElemType e;
	LinkDelete(L,1,e);
	cout<<e<<endl;
	PrintLinkList(L);
	
	return 0;
}
