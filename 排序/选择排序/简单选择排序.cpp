#include<iostream> 
#include<cstring>
#include<cstdio>
#include<vector>


using namespace std;

void SelectSort(vector<int> &vec)
{
	int n=vec.size();
	for(int i=0;i<n-1;i++)//一共n-1趟 
	{
		int min=i;//每次设最小下标为每趟的首个元素 
		for(int j=i+1;j<n;j++)
		{
			if(vec[j]<vec[min]) min=j;//更新最小元素的下标 
		}
		if(min!=i) swap(vec[min],vec[i]);//进行交换 
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
int main()
{
	vector<int> vec={5,2,1,6,9,3,4,100,93,54,42};
	Print(vec);
	SelectSort(vec);
	Print(vec);
	
	return 0;
}
