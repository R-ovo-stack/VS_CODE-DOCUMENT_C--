/*
#include<iostream>
using namespace std;

int MonKeyEatPeach(int n)  //n����ڼ���
{
	int sum;  //ÿ��ʣ��������� 
	if(n==10)
		sum=1;
	else
		sum=(MonKeyEatPeach(n+1)+1)*2;
	return sum;
}

int main()
{
	int m;
	cout<<"��������Ҫ����ĵڼ������������:��"<<endl;
	cin>>m;
	int rlt=MonKeyEatPeach(m);	
	MonKeyEatPeach(m);
	cout<<"��"<<m<<"�����������Ϊ:��"<<rlt<<endl;
	return 0;
}

  */