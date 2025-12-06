
#include<iostream>
#include<cstring>
#include<cstdio> 
#include<vector>

using namespace std;

int Partition(vector<int> &vec,int low,int high)
{ //表内划分  枢轴左侧数值小于等于 基准   右侧数值大于等于 基准 
	int pivot=vec[low];//选择区间左侧值为枢轴值 基准
	while(low<high)
	{
		while(low<high&&vec[high]>=pivot) --high;
		//从右开始向左，值大于基准时，不断左移high指针，直到找到首个小于基准的值
		vec[low]=vec[high];//将该值移动到左端
		
		 
		while(low<high&&vec[low]<=pivot) ++low;
		//从左开始向右，值小于基准时，不断右移low指针，直到找到首个大于基准的值
		vec[high]=vec[low];//将该值移动到右端			
	} 
	//high与low相遇时
	vec[low]=pivot;//将枢轴值填入划分位置
	return low; 
	
}

void QuickSort(vector<int> &vec,int low,int high)
{
	if(low<high)
	{
		int pivotpos=Partition(vec,low,high);
		QuickSort(vec,low,pivotpos-1);//左表递归 
		QuickSort(vec,pivotpos+1,high);	//右表递归 
	} 
}
void Print(const vector<int> vec)
{
	for(auto s:vec)
	{
		cout<<s<<" ";
	}
	puts("");
}
int main()
{//不稳定 
	vector<int> vec={9,8,3,5,7,404,28,32,23,98,10,92};
	Print(vec);
	QuickSort(vec,0,vec.size()-1);
	Print(vec);
	
	return 0;
} 

