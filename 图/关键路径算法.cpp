#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>

using namespace std;

#define MAXEDGE 30
#define MAXVEX 30
#define GRAPH_INFINITY 65535

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
	
	G.numEdges=13;
	G.numVertexes=10;

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
				G.arc[i][j]=GRAPH_INFINITY;
		}
	}

	G.arc[0][1]=3;
	G.arc[0][2]=4; 
	G.arc[1][3]=5; 
	G.arc[1][4]=6; 
	G.arc[2][3]=8; 
	G.arc[2][5]=7; 
	G.arc[3][4]=3;
	G.arc[4][6]=9; 
	G.arc[4][7]=4;
	G.arc[5][7]=6; 
	G.arc[6][9]=2;
	G.arc[7][8]=5;
	G.arc[8][9]=3;

}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G,GraphAdjList &GL)
{
	int i,j;


	GL = new graphAdjList;

	GL->numVertexes=G.numVertexes;
	GL->numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* 读入顶点信息，建立顶点表 */
	{
		GL->adjList[i].in=0;
		GL->adjList[i].data=G.vexs[i];
		GL->adjList[i].firstedge=NULL; 	/* 将边表置为空表 */
	}
	EdgeNode *e;
	for(i=0;i<G.numVertexes;i++) /* 建立边表 */
	{ 
		for(j=0;j<G.numVertexes;j++)
		{
			if (G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e=new EdgeNode;
				e->adjvex=j;					/* 邻接序号为j */   
				e->weight=G.arc[i][j];
				e->next=GL->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				GL->adjList[i].firstedge=e;		/* 将当前顶点的指针指向e  */  
				GL->adjList[j].in++;		
			}
		}
	}
	
}

int etv[MAXVEX+1],ltv[MAXVEX+1]; /* 事件最早发生时间和最迟发生时间数组 */
stack<int> stk_tp;   /* 用于存储拓扑序列的栈 */

bool TopologicalSort(GraphAdjList GL)//拓扑排序 
{
	stack<int> stk_in;//用于存储入度为0的拓扑序列辅助栈
	int topid=0;//顶点编号
	int cnt=0;//记录成功拓扑排序的顶点数目
	for(int i=0;i<GL->numVertexes;i++)
	{
	   if(GL->adjList[i].in==0)
	   {
	       stk_in.push(i);	
       }
	}
	for(int i=0;i<GL->numVertexes;i++)
	{
		etv[i]=0;//初始化事件最早发生时间 
	}
	
	int k=0;
	while(!stk_in.empty())
	{
		topid=stk_in.top();//入度为0的顶点取出 
		stk_in.pop();
		cnt++;
		
		stk_tp.push(topid);//能够拓扑的顶点存放到栈中
		for(auto e=GL->adjList[topid].firstedge;e!=NULL;e=e->next)
		{
		    k=e->adjvex;//记录邻接点编号
			if(!(--GL->adjList[k].in))
			{
				//入度为0的加入拓扑序列
				stk_in.push(k); 
			}
			                 
			etv[k] =max(etv[k],etv[topid] + e->weight);//求各个顶点事件最早发生的时间的etv的值
		} 
	}
	if(cnt<GL->numVertexes)
	{
		puts("图中存在环路，无法拓扑排序！"); 
		return false;
	}
	else
	{
		puts("成功拓扑排序！"); 
		return true;
	}
}
void criticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int topid,k;
	int ete,lte;//活动最早的发生时间和最迟的发生时间 
	TopologicalSort(GL);
	for(int i=0;i<GL->numVertexes;i++)
	{
		ltv[i]=etv[GL->numVertexes-1];//初始化 活动最迟发生 时间 
	}
//	for(int i=0;i<GL->numVertexes;i++)
//	{
//		cout<<ltv[i]<<" ";//初始化 活动最迟发生 时间 
//	}
	while(!stk_tp.empty())
	{
		topid=stk_tp.top();
		stk_tp.pop();//弹出
		for(e=GL->adjList[topid].firstedge;e!=NULL;e=e->next)
		{
			k=e->adjvex;//获取其邻接点的编号
			
			              
			ltv[topid] = min(ltv[topid],ltv[k] - e->weight);  
			//各个顶点事件的最迟发生时间 
		} 
	}
	
	for(int j=0;j<GL->numVertexes;j++)  
	{
		for(e=GL->adjList[j].firstedge;e!=NULL;e=e->next)
		{
			k=e->adjvex;//j ---> k
			ete=etv[j]; //活动的最早开始时间 
			lte=ltv[k]-e->weight;//活动的最迟开始时间
			if(ete==lte)//关键活动 
			{
				printf("<v%d - v%d> length: %d\n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
			}
		}
	}
} 


int main()
{
	MGraph G;
	GraphAdjList GL;
	CreateMGraph(G);
	CreateALGraph(G,GL);
	
	cout<<"开始计算关键路径！\n";
	criticalPath(GL);
	
	
	return 0;
}

