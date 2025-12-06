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

typedef int Path[MAXVEX];    /* 用于存储最短路径下标的数组 */
typedef int Dis[MAXVEX];/* 用于存储到各点最短路径的权值和 */

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
/*  Dijkstra算法，求有向网G的   v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */    
/*  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和   P[5]=4 表示v5的前驱为v4 */  
void ShortestPath_Dijkstra(MGraph G, int v0,Path P,Dis D)
{    
	int v,w,k,min;    
	int final[MAXVEX];/* final[w]=1表示求得顶点v0至vw的最短路径 ,后续不需要再求*/
	for(v=0; v<G.numVertexes; v++)    /* 初始化数据 */
	{        
		final[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
		D[v] = G.arc[v0][v];/* 将与v0点有连线的顶点加上权值 */
		P[v] = -1;				/* 初始化路径数组P为-1  */       
	}

	D[v0] = 0;  /* v0至v0路径为0 */  
	final[v0] = 1;    /* v0至v0不需要求路径 */        
	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */   
	
	
	for(v=1; v<G.numVertexes; v++)   //O(n^2)
	{
		min=GRAPH_INFINITY;    /* 当前所知离v0顶点的最近距离 */        
		for(w=0; w<G.numVertexes; w++) /* 寻找离v0最近的顶点 */    
		{            
			if(!final[w] && D[w]<min)             
			{                   
				k=w;                    
				min = D[w];    /* w顶点离v0顶点更近 */            
			}        
		}        
		final[k] = 1;    /* 将目前找到的最近的顶点置为1 */
		for(w=0; w<G.numVertexes; w++) /* 修正当前最短路径及距离 */
		{
			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
			if(!final[w] && (min+G.arc[k][w]<D[w]))   
			{ /*  说明找到了更短的路径，修改D[w]和P[w] */
				D[w] = min + G.arc[k][w];  /* 修改当前路径长度 */               
				P[w]=k;  //vw的前驱为vk      
			}       
		}   
	}
}

int main()
{
	int i,j,v0;
	MGraph G;    
	Path P;
	Dis D;
	v0=0;
	
	CreateMGraph(G);
	
	ShortestPath_Dijkstra(G, v0,P,D);  
	//system("pause");
	
	printf("最短路径倒序如下:\n");    
	for(i=1;i<G.numVertexes;++i)   
	{       
		printf("v%d - v%d : ",v0,i);
		j=i;
		cout<<i<<" ";
		while(P[j]!=-1)
		{
			printf("%d ",P[j]);
			j=P[j];
		}
		printf("\n");
	}    
	printf("\n源点到各顶点的最短路径长度为:\n");  
	for(i=1;i<G.numVertexes;++i)        
		printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);     
	return 0;
	

} 
