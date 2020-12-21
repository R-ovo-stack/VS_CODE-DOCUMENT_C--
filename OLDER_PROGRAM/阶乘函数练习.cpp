
#include<iostream>
using namespace std;

int fac(int n)
{
	if(n==0)
		return 1;
	if(n>=1)
		return n*fac(n-1);
}

int main()
{
	int m;
	cout<<"请输入需要计算的阶乘值: ";
	cin>>m;
	int result=fac(m);
	cout<<m<<"的阶乘值为: "<<result<<endl;
	return 0;
}
