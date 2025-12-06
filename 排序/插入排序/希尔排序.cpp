#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

void ShellSort(vector<int> &vec)
{
	//vec[0]暂存结果 只能顺序表 
	int d,i,j;
	int n=vec.size()-1;
	for(d=n/2;d>=1;d/=2)
	{
		for(i=d+1;i<=n;i++)//每个增量子表 
		{
			if(vec[i]<vec[i-d]) //不是递增排序时 
			{
				vec[0]=vec[i];//0暂存插入元素 
				for(j=i-d;j>0&&vec[0]<vec[j];j-=d)
				{//从后向前找 将元素后移 
					vec[j+d]=vec[j];
				}
				vec[j+d]=vec[0];//空位插入元素 
			}
		}
	} 
}
void Print(const vector<int> vec)
{
	for(int i=1;i<vec.size();i++)
	{
		cout<<vec.at(i)<<" ";
	}	
	puts("");
} 

int main()
{
	vector<int> vec={-999,9,8,3,5,7,404,28,32,23,98,10,92};
	Print(vec);
	ShellSort(vec); 
	Print(vec);
	
	return 0;
} 
