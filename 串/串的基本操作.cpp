#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
#define MAXSIZE 512  //定义长度最大

typedef struct{
	char* ch=NULL;//动态分配
	int length;//记录串的长度
}HString;

bool InitString(HString &S)
{
	S.ch=new char[MAXSIZE];
	if(S.ch==NULL)
	{
		printf("内存不足!\n");
		return false;
	}
	S.length=0;
	puts("初始化字符串数据成功!");
	return true;
}
bool StrEmpty(HString S)
{
	return S.length==0?true:false;
}
bool StrAssign(HString &S,const char *T)
{/* 生成一个其值等于chars的给串S */
	if(strlen(T)>MAXSIZE)
	{
		printf("赋值对象空间不足!\n");
		return false;
	}
	int i;
	S.length=strlen(T);
	for(int i=1;i<=strlen(T);i++)
	{
		S.ch[i]=*(T+i-1);
	}
	return true;
}
bool StrCopy(HString &S,HString T)
{
	if(S.ch==NULL)
	{
		printf("目标串尚未分配内存空间!\n");
		return false;
	}
	for(int i=1;i<=T.length;i++)
	{
		S.ch[i]=T.ch[i];//深度拷贝
	}
	S.length=T.length;
	return true;
}
int StrLength(HString S)
{
	return S.length;
}

bool SubString(HString &Sub,HString S,int pos,int len)
{

	if(Sub.ch==NULL)
	{
		cout<<"字串未初始化空间!"<<endl;
		return false;
	}
	/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
	if(pos+len-1>S.length)
	{
		cout<<"越界错误!"<<endl;
		return false;
	}
	for(int i=pos;i<pos+len;i++)//包括pos处的字符
	{
		Sub.ch[i-pos+1]=S.ch[i];
	}
	Sub.length=len;
	return true;
}
int StrCompare(const HString &S,const HString &T)
{
	//S>T Positive
	//S==T Zero
	//S<T negative
	
	for(int i=1;i<=S.length&&i<=T.length;i++)
	{
		if(S.ch[i]!=T.ch[i])
		{
			return S.ch[i]-T.ch[i];
		}
	}
	return S.length-T.length;
}
int Index(const HString &S,const HString &T)
{
	//找到主串中与之相同的字串T的位置
	int i=1,n=S.length,m=T.length;
	HString tmp;
	InitString(tmp);//暂存字串
	while(i<=n-m+1)
	{
		SubString(tmp,S,i,m);
		if(StrCompare(tmp,T))//非0时
		{
			++i;
		}
		else
			return i;//返回首个字符位置
	}
	return 0;//找不到
}

bool ClearString(HString &S)
{
	//逻辑上串长设置为0
	S.length=0;
	printf("清除字符串数据成功!\n");
	return true;
}

void printStr(HString S)
{
	if(S.ch==NULL) {
		printf("未创建对象!\n");
		return;
	}
	if(S.length==0)
	{
		return;
	}
	for(int i=1;i<=S.length;i++)
	{
		cout<<S.ch[i];
	}
    puts("");
}
bool DestroyString(HString &S)
{
	
	delete[] (S.ch);
	
	S.length=0;
	printf("销毁字符串成功!\n");
	return true;
}
bool Concat(HString &T,const HString &S1,const HString &S2)
{
	//将S1与S2相连为新的串

	int L1=S1.length,L2=S2.length;
	if(L1+L2>MAXSIZE)
	{
		cout<<"越界"<<endl;
		return false;
	}
	
	InitString(T);

	StrCopy(T,S1);
//	printf("%d",T.length);
//	printStr(T);
//	
	T.length+=L2;
	int st=L1+1,ed=L1+L2;
	for(int i=st;i<=ed;i++)
	{
		T.ch[i]=S2.ch[i-st+1];
	}
	//printStr(T);
	return true;
}
int main()
{
    HString s1,s2;
    const char* g="PVZ is good!Are you ok?";
    const char* m="PVZ is yyds!1314520!!!";
    InitString(s1);
    InitString(s2);
    StrAssign(s1,g);
    StrAssign(s2,m);
  //  auto ret=StrCompare(s1,s2);
//  	HString Sub;
//  	InitString(Sub);
//	SubString(Sub,s1,2,8);
//	printStr(Sub);
//
//    auto i=Index(s1,Sub);
//	cout<<i<<endl;
	
	HString All;
	Concat(All,s1,s2);
	printStr(All);
  
	system("pause");


	return 0;
}
