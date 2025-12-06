#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>

using namespace std;


bool match(char g[])
{
	stack<char> ss;//存储左边括号
	for(int i=0;i<strlen(g);i++)
	{
		if(g[i]=='('||g[i]=='['||g[i]=='{')
		{
			ss.push(g[i]);
		}//遇到左边括号
		else//遇到右边括号
		{
			if(ss.empty())//此时右边括号多余
			{
				cout<<"右边括号无法匹配"<<endl;
				return 0;
			}
			char topelem=ss.top();
			ss.pop();
			if(g[i]==')'&&topelem!='(')
			{
				return false;
			}
			if(g[i]==']'&&topelem!='[')
			{
				return false;
			}
			if(g[i]=='}'&&topelem!='{')
			{
				return false;
			}
		}

	}
	return ss.empty();//若左边括号(栈内不为空，匹配失败)
	//否则成功
}
char stk[100];
int tt=0;
bool arraymatch(char g[])
{
	//只用数组以及指针实现栈的结构
	for(int i=0;i<strlen(g);i++)
	{
		char c=g[i];
		if(c=='('||c=='{'||c=='[')//遇到左边的括号
		{
			stk[++tt]=c;
		}
		else//遇到右边括号
		{
			if(tt==0)//此时栈为空 (没有与之匹配的左括号)
			{
				cout<<"右边括号无法匹配"<<endl;
				return false;
			}
			char topelem=stk[tt--];//获取栈顶元素
			if(g[i]==')'&&topelem!='(')
			{
				return false;
			}
			if(g[i]==']'&&topelem!='[')
			{
				return false;
			}
			if(g[i]=='}'&&topelem!='{')
			{
				return false;
			}
		}
	}
	return tt==0;//如果栈为空 全部匹配成功
	//如果不为空，说明左边括号多余
}
int main()
{
	char g[20];
	 
	cin>>g;
	if(arraymatch(g))
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	
	return 0;
}
