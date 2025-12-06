#include<iostream>

using namespace std;


void func2(int &x,int y)
{
	x++;
	y++;
	return ;
}
void func1(int &x,int y)
{
	x++;
	y++;
	func2(x,y);
}

int main()
{
	int a=1,b=1;
	func1(a,b);
	
	cout<<a<<" "<<b<<endl;
	return 0;
}
