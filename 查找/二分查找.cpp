#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm> 
using namespace std;

typedef int ElemType;

typedef struct{
	ElemType *elem;
	int len;
}SeqArray;

bool initSeqArray(SeqArray &S,int num)
{
	srand(time(0));
	S.elem= new ElemType[num];
	for(int i=0;i<num;i++)
	{
		S.elem[i]=rand()%100+1;
	}
	S.len=num;
	puts("执行升序排列");
	sort(S.elem,S.elem+num);
	return true;
}

void PrintArray(SeqArray S)
{
	for(int i=0;i<S.len;i++)
	{
		cout<<S.elem[i]<<" ";
	}
	cout<<endl;
}
int Binary_Search(SeqArray S,ElemType key)
{
	int low=0,high=S.len-1,mid=0;
	while(low<=high)
	{
	
		mid=(low+high)/2;
		
		if(S.elem[mid]==key)
		{
			return mid;
		}
		else if(S.elem[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return -1;
} 

int main()
{
	SeqArray S;
	initSeqArray(S,20);
	
	PrintArray(S);
	int key=50;
	cout<<"二分查找"<<key<<endl;
	int ret=Binary_Search(S,key);
	if(ret>=0)
	{
		cout<<ret<<endl;
		puts("查找成功"); 
	}
	else
	{
		puts("查找失败");
	}
	delete[] S.elem;
	return 0;
}
