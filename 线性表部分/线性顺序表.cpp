#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;

/*
映射关系
线性表的位序 1，2，3，4，。。。n
数组下标     0，1，2，3，。。。n-1
*/
#define INITSIZE 100
#define OK true
#define ERROR false

typedef int Elemtype;//数据类型
typedef bool Status;//执行状态
typedef struct{
	Elemtype *data;
	int length;//当前长度
	int maxsize;//最大容量
}SqList;
void InitList(SqList &L);
void PrintList(SqList L);
Status IncreaseSize(SqList &L,int len);
Status ListInsert(SqList &L,int i,Elemtype e);
Status ListDelete(SqList &L,int i,Elemtype &e);
Elemtype GetElem(SqList L,int i);
int LocateElem(SqList L,Elemtype e);
Status ListUnion(SqList &L,SqList Q);
Status ListInSect(SqList &Insec,SqList L,SqList Q);

int main()
{
	srand(time(NULL));
	SqList L,Q;
	InitList(L);
	InitList(Q);
	Elemtype e;
	for(int i=1;i<=6;i++)
	{
		ListInsert(L,i,rand()%100+1);
	}
	for(int i=1;i<=9;i++)
	{
		ListInsert(Q,i,rand()%100+1);
	}
	PrintList(L);
	PrintList(Q);
	
	SqList InSec;
	InitList(InSec);
	ListInSect(InSec,L,Q);
	PrintList(InSec);

	return 0;
}
void InitList(SqList &L)
{
	//初始开辟空间
	L.data=new Elemtype[INITSIZE];
	L.length=0;//指示已经占用的部分
	L.maxsize=INITSIZE;//指示空间容量
}
void PrintList(SqList L)
{
    //遍历数组
	for(int i=0;i<L.length;i++)
	{
		printf("%d ",L.data[i]);
		if((i+1)%10==0) puts("");
	}
	puts("");
}
Status IncreaseSize(SqList &L,int len)
{
	//空间开辟更大
	if(len<0){
	 printf("len must be positive!");
	 return ERROR;
	}
	Elemtype *p=L.data;

	L.data=new Elemtype[L.maxsize+len];

	for(int i=0;i<L.length;i++)
	{
		L.data[i]=p[i];
	}
	L.maxsize=L.maxsize+len;
	delete[] p;
	return OK;
}
Status ListInsert(SqList &L,int i,Elemtype e)
{
	//表中第i个位置插入元素e   i为线性表位序 1<=i<=len+1
	if(i<1||i>L.length+1)
	{
		return ERROR;
	}
	if(L.length>=L.maxsize)//判断当前的空间容量是否足够
	{
		printf("内存不足，重新开辟空间,增量为100\n");
		IncreaseSize(L,100);
	}
	for(int j=L.length;j>=i;j--)//这里是对于数组操作 注意下标
	{
		L.data[j]=L.data[j-1];//后移
	}
	L.data[i-1]=e;
	L.length++;//长度++
	return OK;
}
Status ListDelete(SqList &L,int i,Elemtype &e)
{
	//删除线性表中位序为 i的元素，  1<=i<=len
	if(i<1||i>L.length)
	{
		return ERROR;
	}
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
	{
		L.data[j-1]=L.data[j];
	}
	L.length--;//长度减一
	return OK;
}
Elemtype GetElem(SqList L,int i)
{
	if(i<1||i>L.length)
	{
		printf("越界访问顺序表!\n");
		exit(0);
	}
	return L.data[i-1];
}
int LocateElem(SqList L,Elemtype e)
{
	//返回顺序表中的位序 1，2，3，。。。n
	//0就是没有找到
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]==e)
		{
			return i+1;
		}
	}
	return 0;
}
Status ListUnion(SqList &L,SqList Q)
{
	//合并顺序表Q到L中  取并集
	int lenL=L.length;
	int lenQ=Q.length;
	Elemtype e;
	for(int i=0;i<lenQ;i++)
	{
		e=Q.data[i];
		if(!LocateElem(L,e))
		{
			ListInsert(L,++lenL,e);
		}
	}
	return OK;
}
Status ListInSect(SqList& InSec,SqList L,SqList Q)
{
	//合并顺序表Q到L中  取并集
	int lenQ=Q.length;
	int lenInsec=InSec.length;
	Elemtype e;
	for(int i=0;i<lenQ;i++)
	{
		e=Q.data[i];
		if(LocateElem(L,e))
		{
			ListInsert(InSec,++lenInsec,e);
		}
	}
	return OK;
}




