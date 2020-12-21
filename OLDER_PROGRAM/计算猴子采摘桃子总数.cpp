/*
#include<iostream>
using namespace std;

int MonKeyEatPeach(int n)  //n代表第几天
{
	int sum;  //每天剩余的桃子数 
	if(n==10)
		sum=1;
	else
		sum=(MonKeyEatPeach(n+1)+1)*2;
	return sum;
}

int main()
{
	int m;
	cout<<"请输入需要计算的第几天的桃子总数:　"<<endl;
	cin>>m;
	int rlt=MonKeyEatPeach(m);	
	MonKeyEatPeach(m);
	cout<<"第"<<m<<"天的桃子总数为:　"<<rlt<<endl;
	return 0;
}

  */