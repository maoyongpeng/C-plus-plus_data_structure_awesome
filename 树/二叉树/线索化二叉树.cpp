#include<iostream>
#include<cstring>
#include<cstdio>


using namespace std;
const int MAXSIZE=150;
typedef char TElemType;
typedef struct ThreadNode{
	TElemType data;
	struct ThreadNode *lchild,*rchild;//左右孩子指针
	int ltag,rtag;
	//ltag=0指示结点有左孩子  ltag==1指示结点的前驱
	//rtag=0指示结点有右孩子  rtag==1指示结点的后继 
}ThreadNode,*ThreadTree;

TElemType Nil='#';//表示空的字符 

bool visit(TElemType e)
{
	printf("%c",e);
	return true;	
} 
TElemType GetValue(ThreadNode* p)
{
	if(p!=NULL)
	{
		return p->data;
	}
	return Nil;
}

bool CreateTree(ThreadTree &T)
{
	TElemType ch;
	scanf("%c",&ch);
	
	if(ch==Nil)
	{
		T=NULL;
	}
	else
	{
		T=new ThreadNode;
		if(T==NULL)
		{
			cout<<"内存分配不足!\n";
			return false;
		}
		
		T->data=ch;
		CreateTree(T->lchild);//递归构造左边子树 
		if(T->lchild)
		{
			T->ltag=0;//有左孩子 置为0 
		}
		
		CreateTree(T->rchild);
		if(T->rchild)
		{
			T->rtag=0;
		}
	}
	return true;
}//建树


void InThread(ThreadTree &p,ThreadTree &pre)
{
	if(p!=NULL)
	{
		InThread(p->lchild,pre);//递归线索化左树
		
		
		if(p->lchild==NULL)
		{//左孩子为空时 
			p->lchild=pre;//指向前驱
			p->ltag=1; 
		} 
		if(pre!=NULL&&pre->rchild==NULL)
		{
			//前驱结点不空 右子树为空时
			pre->rchild=p;//前驱结点的右孩子指向为p
			pre->rtag=1;//线索化 
		}
		pre=p;//更新前驱结点
		
	
		InThread(p->rchild,pre);//对右子树同样操作 
	}
} 
//中序线索化二叉树
void CreateInThread(ThreadTree T)
{
	ThreadNode* pre=NULL;//前驱指针
	
	if(T!=NULL)
	{//树空时无法线索化 
	
		InThread(T,pre);//线索化 
		
		pre->rchild=NULL;//处理最后一个结点 
		pre->rtag=1;
	} 
}

/*中序的遍历*/
ThreadNode *FirstNode(ThreadNode *p)
{
	while(p->ltag==0)
	{
		p=p->lchild;//向左下找 
	}
	return p;
}
ThreadNode *NextNode(ThreadNode *p)
{	
	//求解p在中序序列下的后继
	if(p->rtag==0)//有右孩子 
	{
		return FirstNode(p->rchild);//右子树最左下结点 
	} 
	return p->rchild;//若是线索化了，返回后继 
} 
void InOrder(const ThreadTree &T)//中序线索化遍历 
{
	for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
	{
		visit(p->data);	
	}	
} 

int main()
{
	ThreadTree T;
	printf("请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')\n");
 	CreateTree(T); /* 按前序产生二叉树 */ 
 	
	CreateInThread(T);//将其线索化 
	
	InOrder(T);
	return 0;
}
