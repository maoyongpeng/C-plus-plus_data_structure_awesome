#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N=128;

typedef struct
{
	char ch[N];
	int length;
}String;



void InitString(String &T,const char *ss)
{
	int len=strlen(ss);
	for(int i=1;i<=len;i++)
	{
		T.ch[i]=*(ss+i-1);
	}
	T.length=len;
}
void get_ori_next(String Mat,int nextval[])
{
	int i=1,j=0;
	nextval[1]=0;
	while(i<Mat.length)
	{
		if(j==0||Mat.ch[i]==Mat.ch[j])
		{//首个字符就不匹配时
			i++;
			j++;
			nextval[i]=j;//记录模式串中下一个的要匹配的位置
		}
		else
		{
			j=nextval[j];
		}
	}
}
void get_opt_next(String Mat,int nextval[])
{
	int i=1,j=0;
	nextval[1]=0;
	while(i<Mat.length)
	{
		if(j==0||Mat.ch[i]==Mat.ch[j])
		{
			++i;
			++j;
			if(Mat.ch[i]!=Mat.ch[j])
			{
				nextval[i]=j;
			}
			else
				nextval[i]=nextval[j];
		}
		else
		{
			j=nextval[j];
		}
	}
}
int kmp(String src,String mat,int nextval[])
{
	/*
    src主串
    mat 模式串
	*/
	
	int i=1,j=1;
	int n=src.length,m=mat.length;
	
	while(i<=n&&j<=m)
	{
		if(j==0||src.ch[i]==mat.ch[j])//首个字符匹配失败
		{
			++i;++j;
		}
		else
			j=nextval[j];//第j个字符匹配失败，下一个模式串中应该开始匹配的位置
	}
	if(j>m)//匹配成功
		return i-m;
	else
		return 0;
}
int main()
{
	
	int nexty[N];//没有优化的数组
	//int nexta[N];//优化的next数组
	String Src,Mat;
	InitString(Src,"happy summer day!Mary and laun,Uh~");
	InitString(Mat,"May");
	
	get_ori_next(Mat,nexty);//没有优化的


 	int pos=kmp(Src,Mat,nexty);
 	if(!pos)
 	{
	  puts("Failed to find!");
	}
	else
	{
		cout<<pos<<endl;
	}

	return 0;
}
