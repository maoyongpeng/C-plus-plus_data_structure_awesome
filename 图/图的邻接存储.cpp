#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
//图的存储  邻接矩阵法

#define MAXSIZE 100 //顶点的最大数目
#define idxsize 256// 索引的最大数目 
#define PINF INT_MAX //初始的默认最大值


typedef char VertexType;//顶点的数据类型
typedef int EdgeType;//边的数据类型

int id=0;//结点索引 

typedef struct
{
	vector<VertexType> vex;//顶点表，  一般场景下 这个是可以忽略的'
	
	int Hashidx[idxsize];//K=顶点字符 ，V 映射下标 
	 
	EdgeType edge[MAXSIZE][MAXSIZE];//边表  邻接矩阵
	int vexnum,arcnum;//顶点数目，边数目
} MGraph;

//建立无向网的表示
void Create_UndstNet(MGraph &G)
{
	cout<<"输入顶点数目以及边的数目！\n";
	cin>>G.vexnum>>G.arcnum;
	cout<<"输入顶点信息(char),建立顶点表.\n";
	VertexType ch;
	for(int i=0; i<G.vexnum; i++)
	{
		cin>>ch;
		if(G.Hashidx[ch-'0']==0)
		{
			G.vex.push_back(ch);
			G.Hashidx[ch-'0']=++id;
		}
	}
	//默认初始化邻接矩阵(n*n)为无穷大
	for(int i=0; i<G.vexnum; i++)
	{
		for(int j=0; j<G.vexnum; j++)
		{
			G.edge[i][j]=PINF;
		}
	}
	//读入边，建立权值以及关系
	cout<<"读入顶点vi->vj(如'a'->'b')之间关系信息,并且输入权值w.\n";
	

	VertexType i,j;
	int w;//权重 
	for(int k=0; k<G.arcnum; k++)
	{
		cin>>i>>j>>w;
		auto id1=G.Hashidx[i-'0']-1;//下标从0开始计入 
		auto id2=G.Hashidx[j-'0']-1;
		
		G.edge[id1][id2]=w;
		G.edge[id2][id1]=G.edge[id1][id2];//无向图对称的 ，  若是有向图则不需要这一行
	}
}
void PrintVerInfo(MGraph G)
{
	for(auto v:G.vex)
	{
		cout<<v<<" ";
	}
	puts("");
}
//∞
void PrintGraphMatrix(const MGraph &G)
{
	
	cout<<"现在打印邻接矩阵信息!"<<endl;
	PrintVerInfo(G);
	auto size=G.vex.size();
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			EdgeType e=G.edge[i][j];
			if(e==PINF)
			{
				cout<<"∞";
			}
			else
			{
				cout<<e<<" ";
			}
		}
		puts("");
	}
}

int main()
{
	MGraph G;

	Create_UndstNet(G);
	
	PrintGraphMatrix(G);

	return 0;
}
