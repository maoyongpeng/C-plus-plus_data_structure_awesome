#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define MAXSIZE 100 //最大顶点数目


typedef char VertexType;//结点类型
typedef int EdgeType;//边类型

typedef struct{
	VertexType vex[MAXSIZE];//顶点表
	EdgeType arc[MAXSIZE][MAXSIZE];//边表
	int vexnums,arcnums; //顶点数目，边数目 
}MGraph; //邻接矩阵实现 

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


void Create_UMGraph(MGraph &G)
{
	cout<<"采用邻接矩阵创建无向图!\n";
	G.vexnums=9;//9个顶点 
	G.arcnums=15;//15边
	
	cout<<"写入顶点信息...\n";
	for(int i=0;i<9;i++)
	{
		G.vex[i]='A'+i;//写入顶点； 
	}
	
	//初始化图
	for(int i=0;i<G.vexnums;i++)
	{
		for(int j=0;j<G.vexnums;j++)
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
	
	for(int i=0;i<G.vexnums;i++)
	{
		for(int j=0;j<G.vexnums;j++)
		{
			G.arc[j][i]=G.arc[i][j];
		}
	}
	
	
}

bool MatrixVisit[MAXSIZE];//邻接矩阵 顶点访问数组  BFS

void M_BFS(MGraph G,int i)
{
	LinkQueue Q;
	initQueue(Q);
	
	MatrixVisit[i]=true;//i被访问过
	EnQueue(Q,i);//顶点序号插入队列尾
	cout<<G.vex[i]<<" ";//访问i结点信息
	

	while(!isEmpty(Q))
	{
		DeQueue(Q,i);//队首元素出队  vi 
		for(int j=0;j<G.vexnums;j++)//遍历顶点表 
		{
			if(!MatrixVisit[j]&&G.arc[i][j]==1)//如果目标结点未被访问 且 vi->vj存在边 
			{
				MatrixVisit[j]=true;//访问过
				EnQueue(Q,j);//加入队列尾部
				cout<<G.vex[j]<<" ";//访问与 u相连的未曾访问过结点的信息 
			} 
		}
	}
	puts("");
}
//邻接矩阵BFS
void Matrix_BFS(MGraph G)
{
	cout<<"对于邻接矩阵广度遍历\n"; 
	for(int i=0;i<G.vexnums;i++)
	{
		if(!MatrixVisit[i])//顶点i尚未被访问 
		{
			M_BFS(G,i);
		}
	}	 
} 


bool visited[MAXSIZE];////邻接矩阵 顶点访问数组  DFS

void M_DFS(MGraph G,int i)
{
	cout<<G.vex[i]<<" ";//访问i结点信息
	visited[i]=true;
	
	for(int j=0;j<G.vexnums;j++)
	{
		if(!visited[j]&&G.arc[i][j]==1)
		{
			M_DFS(G,j);//递归调用 
		}	
	}
}

void Matrix_DFS(MGraph G)
{
	//邻接矩阵深度遍历
	cout<<"对于邻接矩阵深度遍历\n";
	for(int i=0;i<G.vexnums;i++)
	{
		if(!visited[i]){
			M_DFS(G,i);
		}
	}
	puts("");
}



void DebugInfo(const MGraph &G)
{
	cout<<"Debug Info:\n";
	cout<<"输出顶点表信息:\n";
	for(int i=0;i<G.vexnums;i++)
	{
		cout<<G.vex[i]<<" ";
	}
	puts("");
	
	cout<<"输出邻接矩阵信息:\n";
	for(int i=0;i<G.vexnums;i++)
	{
		for(int j=0;j<G.vexnums;j++)
		{
			cout<<G.arc[i][j]<<" ";
		}
		puts("");
	}
}


int main()
{
	MGraph G;
	
	Create_UMGraph(G);
	
	DebugInfo(G);
	
	Matrix_BFS(G);
	
	Matrix_DFS(G);

	
	
	system("pause");
	return 0;
}
