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
	cout<<"����------���ӳ���������-----------"<<endl;
	cout<<"����������ڵڼ������Ե�ֻʣ��һ��������: ";
	cin>>n;
	int count;
	count=peachcount(n);
	cout<<"�����ڵ�"<<n<<"���Ե�ֻʣ��һ��������..."<<endl;
	cout<<"��һ�����������Ϊ: "<<count<<endl;
}