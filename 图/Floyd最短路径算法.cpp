#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Path[MAXVEX][MAXVEX];    /* 用于存储最短路径下标的数组 */
typedef int Dis[MAXVEX][MAXVEX];/* 用于存储到各点最短路径的权值和 */

void CreateMGraph(MGraph &G)
{

	int i, j;

	G.numEdges=16;
	G.numVertexes=9;

	for (i = 0; i < G.numVertexes; i++)/* 初始化图 */
	{
		G.vexs[i]=i;
	}

	for (i = 0; i < G.numVertexes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G.numVertexes; j++)
		{
			if (i==j)
				G.arc[i][j]=0;
			else
				G.arc[i][j] = G.arc[j][i] = GRAPH_INFINITY;
		}
	}

	G.arc[0][1]=1;
	G.arc[0][2]=5; 
	G.arc[1][2]=3; 
	G.arc[1][3]=7; 
	G.arc[1][4]=5; 

	G.arc[2][4]=1; 
	G.arc[2][5]=7; 
	G.arc[3][4]=2; 
	G.arc[3][6]=3; 
	G.arc[4][5]=3;

	G.arc[4][6]=6;
	G.arc[4][7]=9; 
	G.arc[5][7]=5; 
	G.arc[6][7]=2; 
	G.arc[6][8]=7;

	G.arc[7][8]=4;


	for(i = 0; i < G.numVertexes; i++)
	{
		for(j = i; j < G.numVertexes; j++)
		{
			G.arc[j][i] =G.arc[i][j];
		}
	}

}

void Shortest_Floyd(const MGraph &G,Path P,Dis D)
{
	/*初始化数组*/
	int v,w,k;
	for(v=0;v<G.numVertexes;v++)
	{
		for(w=0;w<G.numVertexes;w++)
		{
			D[v][w]=G.arc[v][w];//对应权值边
			P[v][w]=w;//记录前驱结点的编号 ,P[i][j]=j 表示从编号为j的点经过 
		}	
	}
	for(k=0;k<G.numVertexes;k++)//中转点的编号 
	{
		for(v=0;v<G.numVertexes;v++)//源点的编号 
		{
			for(w=0;w<G.numVertexes;w++)//汇点的编号 
			{
				if(D[v][w]>D[v][k]+D[k][w])
				{
					D[v][w]=D[v][k]+D[k][w];
					P[v][w]=P[v][k];//路径设为经过下标为k的点 ，表示从编号为k的中转点经过 
				}
			}
		}
	}
	cout<<"各个顶点之间的最短路径如下:\n";
	for(v=0;v<G.numVertexes;v++)
	{
		for(w=v+1;w<G.numVertexes;w++)
		{
			printf("v%d-v%d weight：%d ",v,w,D[v][w]);
			k=P[v][w];//找其前驱编号 
			printf(" path:%d",v);//打印源点 
			while(k!=w)//路径下标不是汇点下标 
			{
				printf(" -> %d",k);
				k=P[k][w];
			}
			printf(" -> %d\n",w);//打印终点 
		}
		puts("");
	}	
} 

int main()
{
	MGraph G;
	CreateMGraph(G);
	Path P;
	Dis D;
	cout<<"采用Floyd算法计算最短路径:\n";
	Shortest_Floyd(G,P,D);
	
	return 0;
}
