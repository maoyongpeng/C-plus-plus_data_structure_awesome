#include<iostream>
#include<cstring>
#include<cstdio>


using namespace std;
#define MAXSIZE 50
int s[MAXSIZE];

void initSet(int s[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		s[i]=-1;
	}
}
int Find(int s[],int x)
{
	//寻找编号的根节点
	while(s[x]>=0)
	{
		x=s[x];
	}
	return x; 
}
int optFind(int s[],int x)
{
	//路径压缩的寻找编号的根结点
	int root=x;
	while(s[root]>=0)
	{
		root=s[root];//先找根结点 
	}
	while(x!=root)//原有查询编号结点不是根的编号时 
	{
		int t=s[x];//t指向x的父亲结点编号
		s[x]=root;//x父亲更新为压缩后的根， 直接挂到根上
		x=t; // 逐层向上找其父亲 
	}
	return root;
}
void Union(int s[],int r1,int r2)
{

	int p1=Find(s,r1);
	int p2=Find(s,r2);
	s[p2]=p1;
	
}
void optUnion(int s[],int r1,int r2)
{
	
	int p1=optFind(s,r1);
	int p2=optFind(s,r2);
	
	if(s[p1]>s[p2])  //根节点的数组数组的绝对值表示集合中的元素数目
	{
		//小树合并到大树   小树 r1  大树 r2 
		s[p2]+=s[p1];//更新
		s[p1]=p2;	
	} 
	else
	{
		s[p1]+=s[p2];
		s[p2]=p1;
	}
 } 
int main()
{
	
	initSet(s);
//
//	Union(s,0,9);
//	Union(s,9,10);
//	Union(s,10,11);
	
	optUnion(s,2,3);
	optUnion(s,3,5);
	optUnion(s,5,10);
	for(int i=0;i<20;i++)
	{
		cout<<optFind(s,i)<<" ";
	}
	system("pause");
	return 0;
} 
