#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXSIZE=256;
typedef struct
{
	char ch[MAXSIZE];
	int len=0;
}String;
bool StrAssign(String &dst,const char * src)
{
	int slen=strlen(src);
	if(slen>MAXSIZE){
		cout<<"空间不足溢出!"<<endl;
		return false;
	}
	dst.len=slen;
	for(int i=1;i<=slen;i++)
	{
		dst.ch[i]=*(src+i-1);
	}
	return true;
}
int match(const String &S,const String &T)
{
	//朴素模式匹配算法
	//主串S,模式串T
	int i=1,j=1;//初始化指针位置
	int n=S.len,m=T.len;
	while(i<=n&&j<=m)
	{
		if(S.ch[i]==T.ch[j])
		{
			++i;
			++j;//同时后移
		}
		else//有某个不匹配时
		{
			i=i-j+2;//主串重新找下一个字串首个位置
			j=1;//模式串从其第一个位置开始
		}
	}
	if(j>T.len)//匹配成功
	{
		return i-T.len;
	}
	return 0;
}
void Print(const String S)
{
	for(int i=1;i<=S.len;i++)
	{
		cout<<S.ch[i];
	}
	puts("");
}
int main()
{
	const char* src="Happy New Year!Hansy,007God###@@@,M~Yes";
	const char* mat="Hansy@";
	String Src,Match;
	StrAssign(Src,src);
	StrAssign(Match,mat);
//	Print(Src);
//	Print(Match);
	cout<<match(Src,Match);
	return 0;
}
