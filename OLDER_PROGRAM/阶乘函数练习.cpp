
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
	cout<<"��������Ҫ����Ľ׳�ֵ: ";
	cin>>m;
	int result=fac(m);
	cout<<m<<"�Ľ׳�ֵΪ: "<<result<<endl;
	return 0;
}
