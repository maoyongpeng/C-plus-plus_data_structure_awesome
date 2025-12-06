#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define MAXVEX 100 //最大顶点数目


void PrintMinDis(int a[],int size);

typedef char VertexType;//结点类型
typedef int EdgeType;//边类型
/* 邻接矩阵结构 */
typedef struct
{
	VertexType vexs[MAXVEX]; /* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵,可看作边表 */
	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */ 
}MGraph;


/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点 */ 
{
	int adjvex;    /* 邻接点域,存储该顶点对应的下标 */
	//int weight;		/* 用于存储权值,对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域,指向下一个邻接点 */ 
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */ 
{
	int in;	/* 顶点入度 */
	VertexType data; /* 顶点域,存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */   
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes,numEdges; /* 图中当前顶点数和边数 */
}ALGraph;

/*链式辅助队列的实现*/
typedef struct LinkNode{
	int data; //数据区域 ,用于存储顶点下标 
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue{
	LinkNode *front,*rear;
	int length;//记录队列的长度
}LinkQueue;

//带头节点的实现 链式队列 
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
bool EnQueue(LinkQueue &Q,int x)
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
bool DeQueue(LinkQueue &Q,int &x)
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

void CreateMGraph(MGraph &G)
{
	int i, j;
	cout<<"创建邻接矩阵，填入数据中...\n";
	G.numEdges=15;
	G.numVertexes=9;

	/* 读入顶点信息,建立顶点表 */ 
	for(int i=0;i<9;i++)
	{
		G.vexs[i]='A'+i; 
	}
	for (i = 0; i < G.numVertexes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G.numVertexes; j++)
		{
			G.arc[i][j]=0;
		}
	}

	G.arc[0][1]=1;
	G.arc[0][5]=1;

	G.arc[1][2]=1; 
	G.arc[1][8]=1; 
	G.arc[1][6]=1; 
	
	G.arc[2][3]=1; 
	G.arc[2][8]=1; 
	
	G.arc[3][4]=1;
	G.arc[3][7]=1;
	G.arc[3][6]=1;
	G.arc[3][8]=1;

	G.arc[4][5]=1;
	G.arc[4][7]=1;

	G.arc[5][6]=1; 
	
	G.arc[6][7]=1; 

	
	for(i = 0; i < G.numVertexes; i++)
	{
		for(j = i; j < G.numVertexes; j++)
		{
			G.arc[j][i] =G.arc[i][j];
		}
	}

}
 
/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G,ALGraph &GL)
{
	int i,j;
	EdgeNode *e;
	

	GL.numVertexes=G.numVertexes;
	GL.numEdges=G.numEdges;
	for(i= 0;i <G.numVertexes;i++) /* 读入顶点信息,建立顶点表 */   
	{
		GL.adjList[i].in=0;
		GL.adjList[i].data=G.vexs[i];
		GL.adjList[i].firstedge=NULL; 	/* 将边表置为空表 */
	}
	
	for(i=0;i<G.numVertexes;i++) /* 建立边表 */
	{ 
		for(j=G.numVertexes-1;j>=0;j--)
		{
			if (G.arc[i][j]==1)
			{
				e=new EdgeNode;
				
				
				//正常代码下如下
				e->adjvex=j;					/* 邻接序号为j */   
				
				e->next=GL.adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				GL.adjList[i].firstedge=e;		/* 将当前顶点的指针指向e */   
				GL.adjList[j].in++;//入度加1 
	
			}
		}
	}	
}


bool visited_dfs[MAXVEX];//深搜访问数组
void DFS(ALGraph &GL,int i)
{ 
	cout<<GL.adjList[i].data<<" ";//访问顶点i的信息
	visited_dfs[i]=true;
	
	for(auto p=GL.adjList[i].firstedge;p!=NULL;p=p->next)
	{
		auto j=p->adjvex;//获取 邻接点的序号
		if(!visited_dfs[j])
		{
			DFS(GL,j);//递归访问i的邻居 j 
		} 
	} 
}
void Table_DFS(ALGraph GL)
{
	cout<<"对于邻接表进行深搜\n"; 
	for(int i=0;i<GL.numVertexes;i++)
	{
		if(!visited_dfs[i])
		{
			DFS(GL,i);	
		}	
	}
	puts("");	
} 



bool visited_bfs[MAXVEX];//广搜访问数组
int d[MAXVEX];

void BFS(ALGraph &GL,int u)//从u号顶点出发 
{
	LinkQueue Q;
	initQueue(Q);
	
//	for(int i=0;i<GL.numVertexes;i++)
//	{
//		d[i]=INT_MAX;   //表示从u->i的距离 
//	}
	
	cout<<GL.adjList[u].data<<" ";//访问结点i的信息
	visited_bfs[u]=true;
	EnQueue(Q,u);//状态加入队尾 
//	d[u]=0;
	
	while(!isEmpty(Q))
	{
		DeQueue(Q,u);//队首的结点弹出
		
		for(auto p=GL.adjList[u].firstedge;p!=NULL;p=p->next)
		{
			auto w=p->adjvex;//获取 邻接点序号
			
			if(!visited_bfs[w])
			{
				cout<<GL.adjList[w].data<<" ";
//				d[w]=d[u]+1;
				visited_bfs[w]=true;
				EnQueue(Q,w);//顶点j入队 
			}	
		}
	}
	puts("");
	//PrintMinDis(d,GL.numVertexes);
}



void Table_BFS(ALGraph GL)
{
	cout<<"对于邻接表进行广搜\n";

	for(int i=0;i<GL.numVertexes;i++)
	{
		if(!visited_bfs[i])//连通图下的只执行一次 
		{
			BFS(GL,i);
		}
	}
	puts("");
}
void PrintMinDis(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(d[i]==INT_MAX)
		{
			cout<<"∞";	
		}
		else
		{
			cout<<d[i];
		}
	}
	puts("");
}

int main()
{
	MGraph G;
	ALGraph GL;
	
	CreateMGraph(G);//创建邻接矩阵的数据副本
	
	CreateALGraph(G,GL);//根据副本将数据加载到 邻接表
	
	Table_DFS(GL);
	
	Table_BFS(GL); 
	

	system("pause");
	return 0;
}





