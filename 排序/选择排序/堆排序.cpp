#include<iostream> 
#include<cstring>
#include<cstdio>
#include<vector>


using namespace std;

void HeapAdjust(vector<int> &vec,int k,int len)
{//以小根堆为例子 
	//将对于元素k为根的子树进行调整 
	int temp=vec[k];
	for(int i=2*k;i<len;i*=2)//关键字较小的向下筛选 
	{
		if(i<len&&vec[i]>vec[i+1])//子树的右孩子小于于左孩子时 
		{
			i++;//选择右边的孩子 
		} 
		if(temp<=vec[i]) break;//如果暂存值（Root<Min(Left,Right)） 
		else
		{
			vec[k]=vec[i];//交换Root=Min(Left,Right) 
			k=i;//对于孩子继续筛选 
		} 
	}
	vec[k]=temp;//被筛选的值放回最终位置 
}
void BuildMaxHeap(vector<int>&vec)
{
	int len=vec.size();
	for(int i=len/2-1;i>=0;i--)//从无序序列中不断调整堆，满足大小性质 
	{
		HeapAdjust(vec,i,len);	
	} 
}

void HeapSort(vector<int> &vec)
{
	int len=vec.size();
	BuildMaxHeap(vec);//初始建堆
	for(int i=len-1;i>0;i--)//n-i趟的交换建立堆的过程 
	{
		swap(vec[i],vec[0]);// 交换堆底元素和堆顶元素
		HeapAdjust(vec,0,i-1);//调整堆 
	}
}
void Print(vector<int> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	puts("");
}
void HeapInsert(vector<int> &vec,int elem)
{
	vec.push_back(elem);//直接加到堆底
	int idx=vec.size()-1;//插入新元素的下标
	//小根堆为例 
	
	for(int i=idx;i>=0;i/=2)
	{
		
		int &root=vec[i/2];
		int &child=vec[i];
		if(child>=root) break;
	//	cout<<i<<"/"<<" "<<root<<" "<<child<<endl;
		if(child<root)
		{
			swap(child,root);
		}	
	} 	
}
void HeapDelete(vector<int> &vec,int target)
{
	//按照值 删除  用堆底元素代替
	int end_idx=vec.size()-1;
	int k=0;
	for(int i=0;i<vec.size();i++)
	{
		if(target==vec[i])
		{
			swap(vec[i],vec[end_idx]);
			vec.pop_back();//尾部删除 
			k=i;
			break;
		}
	}
	int len=vec.size();
	
	int temp=vec[k];
	for(int i=2*k;i<len;i*=2)//关键字较小的向下筛选 
	{
		if(i<len&&vec[i]>vec[i+1])//子树的右孩子小于于左孩子时 
		{
			i++;//选择右边的孩子 
		} 
		if(temp<=vec[i]) break;//如果暂存值（Root<Min(Left,Right)） 
		else
		{
			vec[k]=vec[i];//交换Root=Min(Left,Right) 
			k=i;//对于孩子继续筛选 
		} 
	}
	vec[k]=temp;
	
	
}
int main()
{
	vector<int> vec={9,2,77,5,7,1,100,92,36,84,73,31,42,22};
	Print(vec);
	HeapSort(vec);
	Print(vec);
	
//	HeapInsert(vec,0);
//	Print(vec);
//	HeapDelete(vec,2);
//	Print(vec);
	
	
	return 0;	
} 
