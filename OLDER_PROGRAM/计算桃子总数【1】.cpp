#include<iostream>
using namespace std;

int peachcount(int n)
{
	int count=1;
	int i;
	for(i=1;i<n;i++)
		count=(count+1)*2;
	return count;
}

void main()
{
	int n;
	cout<<"——------猴子吃桃子问题-----------"<<endl;
	cout<<"请输入猴子在第几天过后吃得只剩下一个桃子了: ";
	cin>>n;
	int count;
	count=peachcount(n);
	cout<<"猴子在第"<<n<<"天后吃得只剩下一个桃子了..."<<endl;
	cout<<"第一天的总桃子数为: "<<count<<endl;
}