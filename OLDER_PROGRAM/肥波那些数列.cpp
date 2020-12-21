/*
#include<iostream>
using namespace std;

//计算斐波那楔数列第n项的值

int fib(int n)   
{
	if(n==1||n==2)
		return 1;
	if(n>2)
		return fib(n-1)+fib(n-2);
}

int main()
{
	int N;
	int cott;
	cout<<"请输入你要打印的斐波那楔数列的项数: ";
	cin>>N;
	//cout<<"前"<<"N"<<"项斐波那楔数列的结果为:＂<<endl;
	cout<<endl<<"前"<<N<<"项斐波那楔数列的结果为: "<<endl;
	for(int i=1;i<=N;i++)
	{
		cott=fib(i);
		cout<<cott<<"  ";
		if(i%5==0);
			cout<<endl;
	}cout<<endl;
	return 0;
}

 */