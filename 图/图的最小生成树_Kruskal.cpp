#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define MAXVEX 100 //最大顶点数目
#define INFINITY 65535 //权值最大 无穷处 
#define MAXEDGE 20 //最大边数 
typedef char VertexType;//结点类型
typedef int EdgeType;//边类型

typedef struct{
	VertexType vex[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//边表
	int vexnums,arcnums; //顶点数目，边数目 
}MGraph; //邻接矩阵实现 

typedef struct{
	int begin;
	int end;
	int weight;
}Edge; //边集数据结构 
void CreateMGraph(MGraph &G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G.vexnums=9;
	G.arcnums=15;

	for (i = 0; i < G.vexnums; i++)/* 初始化图 */
	{
		for ( j = 0; j < G.vexnums; j++)
		{
			if (i==j)
				G.arc[i][j]=0;
			else
				G.arc[i][j] = G.arc[j][i] = INFINITY;
		}
	}

	G.arc[0][1]=10;
	G.arc[0][5]=11; 
	G.arc[1][2]=18; 
	G.arc[1][8]=12; 
	G.arc[1][6]=16; 
	G.arc[2][8]=8; 
	G.arc[2][3]=22; 
	G.arc[3][8]=21; 
	G.arc[3][6]=24; 
	G.arc[3][7]=16;
	G.arc[3][4]=20;
	G.arc[4][7]=7; 
	G.arc[4][5]=26; 
	G.arc[5][6]=17; 
	G.arc[6][7]=19; 

	for(i = 0; i < G.vexnums; i++)
	{
		for(j = i; j < G.vexnums; j++)
		{
			G.arc[j][i] =G.arc[i][j];
		}
	}

}
void swapEdge(Edge e[],int i,int j)
{//交换边i,j的所有属性，交换
	int temp;
	
	temp=e[i].begin;
	e[i].begin=e[j].begin;
	e[j].begin=temp;
	
	temp=e[i].end;
	e[i].end=e[j].end;
	e[j].end=temp;
	
	temp=e[i].weight;
	e[i].weight=e[j].weight;
	e[j].weight=temp;
}
void sortw(Edge edges[],const MGraph &G)
{
	//按照邻接矩阵中 边权值升序排列 
	int i,j;
	for(i=0;i<G.arcnums;i++)
	{
		for(j=i+1;j<G.arcnums;j++)
		{
			if(edges[i].weight>edges[j].weight)
			{
				swapEdge(edges,i,j);
			}
		}
	} 
	cout<<"权排序之后\n";
	for(int i=0;i<G.arcnums;i++)
	{
		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}
	puts("开始生成最小生成树");
}
int Find(int parent[],int f)
{
	//并查集，查看是否存在环
	while(parent[f]>0)
	{
		f=parent[f];	
	} 
	return f;
}

void MiniSpanTree_Kruskal(const MGraph &G)
{
	int i,j,n,m;
	Edge edges[MAXEDGE];//定义边集数组
	int parent[MAXVEX];//定义双亲数组，找父亲
	
	int k=0;//记录边集数组下标 
	/*将邻接矩阵转化为边集数组，并且按权升序排序*/
	for(i=0;i<G.vexnums-1;i++)
	{
		for(j=i+1;j<G.vexnums;j++)
		{
			if(G.arc[i][j]<INFINITY)
			{
				edges[k].begin=i;
				edges[k].end=j;
				edges[k].weight=G.arc[i][j];
				k++; 
			}
		}
	}
	sortw(edges,G);//排序
	
	/* --------------------------------------- */
	
	for(i=0;i<G.vexnums;i++)
	{
		parent[i]=0;//parent数组初始化 
	}
	
	
	/*Kruskal时间复杂度为O(eloge),稀疏图友好算法*/
	for(i=0;i<G.arcnums;i++)//O(e) 
	{
		n=Find(parent,edges[i].begin);//O(loge)
		m=Find(parent,edges[i].end);
		if(n!=m)//没有环路 
		{
			parent[n]=m;
			printf("(%d,%d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
	 
} 
int main()
{
	MGraph G;
	CreateMGraph(G);
	cout<<"采用Kruskal生成最小生成树!\n";
	MiniSpanTree_Kruskal(G);
	
	return 0;
}
