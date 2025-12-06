#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

void BubbleSort(vector<int> &vec)
{
	//n个元素，冒泡趟数为n-1 
	for(int i=0;i<vec.size()-1;i++)
	{
		bool flag=false;//本趟是否出现比较后需要交换的
		for(int j=vec.size()-1;j>i;j--) //一趟的冒泡过程 
		{
			if(vec[j-1]>vec[j])
			{//存在逆序 
				swap(vec[j-1],vec[j]);
				flag=true; 
			}
		}
		if(flag==false) //本趟未发生交换，那么说明有序 算法结束 
			return;
	}
}
void Print(const vector<int> vec) 
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	puts("");
}
int main()
{
	vector<int> vec={9,8,3,5,7,404,28,32,23,98,10,92};
	Print(vec);
	BubbleSort(vec); 
	Print(vec);
	
	return 0;
} 
