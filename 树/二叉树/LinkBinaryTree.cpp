#include<iostream>
#include<cstdio>
#include<cstring>
#include"QueueHeadFile.h"

const int MAXSIZE =150;//初始分配空间量

int treeIndex=1;//下标，编注树的编号 
typedef char String[128];//0号单元存储长度
String str;//全局变量 存放字符串，填充树 


 
bool visit(TElemType e)//打印节点元素 
{
	printf("%c",e);
	return true;	
}
bool StrAssign(String strings,const char* strs)
{
	//将C风格的字符串赋值给T
	int i;
	int len=strlen(strs);
	if(len>MAXSIZE)
	{
		return false;
	}
	else
	{
		strings[0]=strlen(strs);
		for(int i=1;i<=strings[0];i++)
		{
			strings[i]=*(strs+i-1); 
		}
	}
	return true;
}

bool initBiTree(BiTree &T)
{
	T=NULL;//赋值为空
	return true; 
}
bool DestroyBiTree(BiTree &T)
{
	//销毁二叉树，递归
	//前提二叉树存在
	if(T)
	{
		if(T->lchild)
		{
			DestroyBiTree(T->lchild);
		}
		if(T->rchild)
		{
			DestroyBiTree(T->rchild);
		}
		delete T;
		T=NULL;
	}
}
void CreateTree(BiTree &T)
{
	/* 按前序输入二叉树中结点的值（一个字符） */
	/* #表示空树，构造二叉链表表示二叉树T。 */
	TElemType e;
	
	e=str[treeIndex++];
	if(e=='#')
	{
		T=NULL;
	}
	else
	{
		T =new BiTNode;
		if(T==NULL)
		{
			printf("内存分配不足!\n");//内存分配不足
			return; 
		}
		T->data=e;//数据填充
		CreateTree(T->lchild);//递归构造左右子树 
		CreateTree(T->rchild);
	}
	
}
bool BiTreeEmpty(BiTree T)
{
	//判断二叉树为空?
	if(T)
	{
		return false;
	}
	else
	{
		return true;	
	} 
}

int BiTreeDepth(BiTree T)
{
	//求解二叉树的深度
	int i,j;
	if(T==NULL)//根为空时 
	{
		return 0;
	} 
	if(T->lchild)
	{
		i=BiTreeDepth(T->lchild);//递归获取左子树的深度 
	}
	else
	{
		i=0;
	}
	if(T->rchild)
	{
		j=BiTreeDepth(T->rchild);//递归获取右子树的深度 
	}
	else
	{
		j=0;
	} 
	return i>j?i+1:j+1;//取较大的一支 
}
TElemType GetRoot(BiTree T)
{
	//获取树的根
	if(T==NULL)
	{
		printf("树根不存在!\n");
		return Nil;//返回空字符	
	} 
	return T->data; 
} 
TElemType GetValue(BiTree p)
{
	//获取二叉树中 p指向的结点的数据值
	return p->data; 
}
void AssignValue(BiTree p,TElemType e)
{
	//给p所指结点赋值
	p->data=e; 
}
void PreOrderVisit(BiTree T)
{
	// ROOT ->Left ->Right 前序遍历 
	if(T==NULL)//根为空时 ，基线条件 
	{
		return;
	}
	visit(T->data);//可以换为其他操作 
	PreOrderVisit(T->lchild);//递归条件 
	PreOrderVisit(T->rchild);
}
void InOrderVisit(BiTree T)
{
	// Left ->ROOT ->Right 中序遍历 
	if(T==NULL)//根为空时 
	{
		return;
	}
	InOrderVisit(T->lchild);
	visit(T->data);
	InOrderVisit(T->rchild);
} 
void PostOrderVisit(BiTree T)
{
	// Left ->Right ->ROOT 后序遍历 
	if(T==NULL)//根为空时 
	{
		return;
	}
	PostOrderVisit(T->lchild);
	PostOrderVisit(T->rchild); 
	visit(T->data);
}

void LevelVisit(BiTree T)
{
	//层序遍历二叉树
	LinkQueue Q;
	initQueue(Q);
	BiTree p;
	EnQueue(Q,T);//根结点入队
	
	while(!isEmpty(Q))//不为空时 
	{
		DeQueue(Q,p);//队头出队
		auto e=GetValue(p);//获取元素 
		visit(e);//打印
		
		if(p->lchild!=NULL)
		{
			EnQueue(Q,p->lchild);//左子树不空，入队	
		}
		if(p->rchild!=NULL)
		{
			EnQueue(Q,p->rchild);
		}
	}
		 
} 

int main()
{
	BiTree T;
	initBiTree(T);//初始化二叉树
	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");
	
	CreateTree(T);
	
	printf("构造完二叉树后，树是否为空?%d (1:为空,0:不为空)，树的深度为:%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	
	TElemType elem=Nil;
	elem=GetRoot(T);
	printf("树的根元素为:%c\n",elem);
	
	printf("\n前序遍历二叉树");
	PreOrderVisit(T);
	printf("\n中序遍历二叉树");
	InOrderVisit(T); 
	printf("\n后序遍历二叉树");
	PostOrderVisit(T);
	
	printf("\n层次遍历二叉树");
	LevelVisit(T);
	
	printf("\n销毁二叉树……");
	DestroyBiTree(T);
	
	printf("\n销毁完二叉树后，树是否为空?%d (1:为空,0:不为空)，树的深度为:%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	
	elem=GetRoot(T);
	printf("再次访问树根结点元素:");
	if(elem==Nil)
	{
		printf("树空，无结点\n");	
	} 
	

	system("pause");
	return 0;
}
