#include<iostream>
#include<cstdio>
#include<cstring> 
#include<stack>

#define MAXEDGE 20
#define MAXVEX 14

using namespace std;
/* 邻接矩阵结构 */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点  */
{
	int adjvex;    /* 邻接点域，存储该顶点对应的下标 */
	int weight;		/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	int data; /* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* 图中当前顶点数和边数 */
}graphAdjList,*GraphAdjList;
/* **************************** */


void CreateMGraph(MGraph &G)/* 构件图 */
{
	int i, j;
	
	G.numEdges=MAXEDGE;
	G.numVertexes=MAXVEX;

	for (i = 0; i < G.numVertexes; i++)/* 初始化图 */
	{
		G.vexs[i]=i;
	}

	for (i = 0; i < G.numVertexes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G.numVertexes; j++)
		{
			G.arc[i][j]=0;//边权为 0 
		}
	}

	G.arc[0][4]=1;
	G.arc[0][5]=1; 
	G.arc[0][11]=1; 
	G.arc[1][2]=1; 
	G.arc[1][4]=1; 
	G.arc[1][8]=1; 
	G.arc[2][5]=1; 
	G.arc[2][6]=1;
	G.arc[2][9]=1;
	G.arc[3][2]=1; 
	G.arc[3][13]=1;
	G.arc[4][7]=1;
	G.arc[5][8]=1;
	G.arc[5][12]=1; 
	G.arc[6][5]=1; 
	G.arc[8][7]=1;
	G.arc[9][10]=1;
	G.arc[9][11]=1;
	G.arc[10][13]=1;
	G.arc[12][9]=1;

}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G,GraphAdjList &GL)
{
	int i,j;
	EdgeNode *e;

	GL = new graphAdjList;

	GL->numVertexes=G.numVertexes;
	GL->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* 读入顶点信息，建立顶点表 */
	{
		GL->adjList[i].in=0;
		GL->adjList[i].data=G.vexs[i];
		GL->adjList[i].firstedge=NULL; 	/* 将边表置为空表 */
	}
	
	for(i=0;i<G.numVertexes;i++) /* 建立边表 */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=new EdgeNode;
				e->adjvex=j;					/* 邻接序号为j  */                        
				e->next=GL->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				GL->adjList[i].firstedge=e;		/* 将当前顶点的指针指向e  */  
				GL->adjList[j].in++;	
			}
		}
	}
	
}
bool TopologicalSort(const GraphAdjList &AL)
{
	int cnt=0;//统计成功排序的结点数目 
	stack<int> stk;
	for(int i=0;i<AL->numVertexes;i++)
	{
		if(AL->adjList[i].in==0)
		{
			stk.push(i);//将入度为0的点压入栈 
		}
	}
	
	int k=0;//记录表中邻接点的编号信息 
	while(!stk.empty())
	{
		auto topid=stk.top();
		stk.pop();//栈顶元素编号出栈
		 
		printf("%d ->",AL->adjList[topid].data);//打印结点数据信息
		
		cnt++;
		
		for(auto e=AL->adjList[topid].firstedge;e!=NULL;e=e->next)
		{
			k=e->adjvex;
			if(!(--AL->adjList[k].in))
			{
				//一旦该结点的对应的邻接点的入度为0时 入栈
				stk.push(k);	
			} 
		}		
	} 
	puts("");
	if(cnt<AL->numVertexes)
	{
		puts("图中存在环路，无法拓扑排序！");
		return false;
	}
	else
	{
		puts("拓扑排序完成!");
		return true;
	}
	
}

int main()
{
	MGraph G;
	GraphAdjList AL;
	CreateMGraph(G);
	CreateALGraph(G,AL);
	
	TopologicalSort(AL);
	return 0;
}

