#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;

typedef int ElemType;

typedef struct{
	ElemType *elem;
	int len;
}SeqArray;

bool initSeqArray(SeqArray &S,int num)
{
	srand(time(0));
	if(num<=0) {
		puts("数目指定非法!");
		return false;
	}
	S.elem= new ElemType[num];
	for(int i=0;i<num;i++)
	{
		S.elem[i]=rand()%100+1;
	}
	S.len=num;
	return true;
}

int Search_seq(SeqArray S,ElemType key)
{
	S.elem[0]= key;
	int i=S.len;
	while(S.elem[i]!=key)
	{
		i--;
	}
	return i;//查找失败时为0 
}
void PrintArray(SeqArray S)
{
	for(int i=0;i<S.len;i++)
	{
		cout<<S.elem[i]<<" ";
	}
	puts("");
}

int main()
{
	SeqArray S;
	initSeqArray(S,10);
	
	PrintArray(S);
	int key=50;
	cout<<"查找"<<key<<endl;
	auto ret=Search_seq(S,key);
	if(ret)
	{
		puts("查找成功"); 
	}
	else
	{
		puts("查找失败");
	}
	
	return 0;
}
