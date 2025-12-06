#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
void InsertSort(int a[],int n)
{//直接插入排序O(n^2),下标从1到n 
	int i,j;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			int temp=a[i];
			for(j=i-1;temp<a[j]&&j>=0;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}
	}
	
}
void Insert_Binary_Sort(int a[],int n)
{//二分 查找  插入排序 O(n^2) 
	int i,j,low,high,mid;
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		low=0,high=i-1;//设置查找范围
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[mid]>temp) high=mid-1;//查找左边 
			else low=mid+1;//查找右边 
		}
		for(j=i-1;j>=high+1&&j>=0;j--)
		{
			a[j+1]=a[j];//右移	统一操作 
		} 
		a[high+1]=temp;//填入元素 
	}
	
	
} 
void printArr(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	cout<<endl;
}

int main()
{
	int a[10]={98,2,5,3,9,4,7,9,1,100};
	printArr(a,10);
//	InsertSort(a,10);
	Insert_Binary_Sort(a,10);	
	printArr(a,10);
		
	
	
	return 0;
} 
