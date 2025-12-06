#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define MAXVEX 100 //最大顶点数目
#define INFINITY 65535 //权值最大 无穷处 

typedef char VertexType;//结点类型
typedef int EdgeType;//边类型

typedef struct{
	VertexType vex[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//边表
	int vexnums,arcnums; //顶点数目，边数目 
}MGraph; //邻接矩阵实现 
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
void MiniSpanTree_Prim(const MGraph &G)
{
	int min,i,j,k;
	int adjvex[MAXVEX];//保存相关顶点间的权值下标
	int lowcost[MAXVEX];//保存相关顶点间的权值
	
	lowcost[0]=0;//v0加入生成树，代价设为0，不再参与后面的选择
	adjvex[0]=0;//初始化第一个顶点下标为0
	
	for(i=1;i<G.vexnums;i++)
	{
		lowcost[i]=G.arc[0][i];//将v0顶点与之有边的权值存入数组 
		adjvex[i]=0;//初始化都为v0的下标 
	} 
	for(i=1;i<G.vexnums;i++)
	{
		min=INFINITY;
		j=1;k=0;
		while(j<G.vexnums)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min=lowcost[j];//权值不为0(顶点未被选择)，权值小于min 
				k=j;//最小值下标存入k 
			}
			j++; 
		}
		printf("(%d,%d)\n",adjvex[k],k);//打印权值最小的边
		lowcost[k]=0;//vk顶点加入生成树中
		for(j=1;j<G.vexnums;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])//下标为k的顶点的各边权值小于此前之前未被加入生成树的权值
			{
				lowcost[j]=G.arc[k][j]; 
				 adjvex[j]=k;
			} 
		}
	} 
}

int main()
{
	MGraph G;
	CreateMGraph(G);
	cout<<"采用Prin算法构造最小生成树\n"; 
	MiniSpanTree_Prim(G);
	
	return 0;
}
