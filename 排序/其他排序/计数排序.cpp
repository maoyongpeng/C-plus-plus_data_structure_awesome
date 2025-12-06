#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<ctime>
using namespace std;

void InitV(vector<int> &vec)
{
	srand(time(0));
	for(int i=0;i<12;i++)
	{
		vec.push_back(rand()%100+1);
	}
}
void Print(const vector<int> &vec)
{
	for(auto s:vec)
	{
		cout<<s<<" ";
	}
	puts("");
}
const int k=110;//辅助数组长度
int temp[k]; 
vector<int> CountSort(vector<int> &src)
{
	int i;
	vector<int> target;
	target.resize(src.size());
	memset(temp,0,sizeof temp);
	for(i=0;i<src.size();i++)//遍历输入数组，统计出现次数 
	{
		temp[src[i]]++;//Key=src[i]值  Val=次数 
	}
	for(i=1;i<k;i++)
	{
		temp[i]+=temp[i-1];//temp[x]保存的是小于等于x的元素个数 
	}
	for(i=src.size()-1;i>=0;i--)//逆向遍历 
	{
		target[temp[src[i]]-1]=src[i];//src数组中的值按照辅助数组中的次数索引放置到合适位置 
		temp[src[i]]=temp[src[i]]-1;
	}
	return target; 
}
int main()
{
	vector<int> a;
	InitV(a);
	Print(a);
	
	
	auto b=CountSort(a);
	Print(b);
	
	return 0;
} 
