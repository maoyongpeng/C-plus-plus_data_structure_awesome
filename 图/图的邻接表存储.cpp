#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

#define MAXSIZE 100 //最大顶点数目

typedef char VertexType;//结点类型
typedef int EdgeType;//边类型

typedef int InfoType;//边上权值类型，可选

typedef struct ArcNode{ //边表结点
	int adjvex;//该弧指向的顶点位置
	struct ArcNode *nextarc;//指向下一条的弧的指针
	InfoType info;//网上的权值 
}ArcNode;
typedef struct VNode{//顶点表结点 
	VertexType data;//顶点数据字段
	ArcNode *firstarc;//首个依附于该顶点的弧的指针 
}VNode,AdjList[MAXSIZE];//声明邻接表 结构体数组
typedef struct{
	AdjList vertices;//邻接表 
	int vexnum,arcnum;//节点数，弧数目 
}ALGraph; 

void Create_ALGraph(ALGraph &G)
{	//无向图 
	//创建邻接表结构
	cout<<"输入结点的数目以及边的数目！\n";
	cin>>G.vexnum>>G.arcnum;
	if(G.vexnum>MAXSIZE)
	{
		cout<<"顶点数超出范围!\n";
		return;
	}
	
	cout<<"输入每个结点的数据字段!\n";
	for(int i=0;i<G.vexnum;i++)//为每个顶点表进行初始化 
	{
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;//首个指向的弧为NULL 
	}
	
	cout<<"输入顶点vi与顶点vj的序号:\n";
	ArcNode *e;//一个边表的结点
	int i,j;
	for(int k=0;k<G.arcnum;k++)
	{
		cin>>i>>j;
		
		//采用头插法 
		//vi->vj 
		e=new ArcNode;//申请空间
		e->adjvex=j;//邻接序号为 j 
		e->nextarc=G.vertices[i].firstarc;//将 e的指针指向j顶点的首个指针域 
		G.vertices[i].firstarc=e;//链接e
		
		//vj->vi
		e=new ArcNode;
		e->adjvex=i;
		e->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=e; 
		
	}
	cout<<"构建成功!"<<endl; 
}
void PrintGraph(const ALGraph G)
{
	cout<<"打印结点表序列\n";
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<G.vertices[i].data<<" ";
	}
	puts("");
	
	cout<<"打印边表序列："<<endl;
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<i<<" "<<G.vertices[i].data<<" ";
		auto p=G.vertices[i].firstarc;
		while(p!=NULL)
		{
			cout<<p->adjvex<<" ";
			p=p->nextarc;
		}
		cout<<"/";
		puts("");
	} 
	 
}

int main()
{
	ALGraph G;
	Create_ALGraph(G);
	PrintGraph(G);
	system("pause");
	return 0;
}
