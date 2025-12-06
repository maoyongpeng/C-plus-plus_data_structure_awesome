#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;
const int N=1000;
int temp[N];//辅助数组 
void Merge(vector<int> &vec,int low,int mid,int high)
{
	int i,j,k;//i指示左侧有序序列 j指示右侧有序序列
	//k用于归并后数组的下标
	for(k=low;k<=high;k++)
	{
		temp[k]=vec[k];
	}
	k=low;
	for(i=low,j=mid+1;i<=mid&&j<=high;)
	{
		if(temp[i]<=temp[j]) vec[k++]=temp[i++];
		else vec[k++]=temp[j++];
	}
	while(i<=mid) vec[k++]=temp[i++];
	while(j<=high) vec[k++]=temp[j++];
} 

void MergeSort(vector<int> &vec,int low,int high)
{
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(vec,low,mid);
		MergeSort(vec,mid+1,high);
		Merge(vec,low,mid,high);//合并 
	}
} 
void InitV(vector<int> &vec)
{
	for(int i=0;i<10;i++)
	{
		vec.push_back(rand()%100+1);
	}
	
}
void Print(vector<int> &vec)
{
	for(auto s:vec)
	{
		cout<<s<<" ";
	}
	puts("");
}

int main()
{
	vector<int> vec;
	InitV(vec);
	Print(vec);
	MergeSort(vec,0,vec.size()-1);
	Print(vec);

	
	
	
	return 0;
}
