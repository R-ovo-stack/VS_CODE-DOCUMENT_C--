
#include<iostream>
using namespace std;

int count=0;  //步骤计数器

//  ======汉诺塔移动步骤打印函数以及移动算法======
void Hanio(int n,char a,char b,char c)  
{
	if(n==1){
		cout<<"步骤"<<++count<<"   ";
		cout<<"         "<<a<<" -> "<<c<<endl;
	}
	else
	{
		Hanio(n-1,a,c,b);
		cout<<"步骤"<<++count<<"   ";
		cout<<"         "<<a<<" -> "<<c<<endl;
		Hanio(n-1,b,a,c);
	}
}

int main()
{
	char A,B,C;
	int num;
	cout<<"请输入盘子总数: ";
	cin>>num;
	cout<<endl<<"========开始移动========"<<endl;
	Hanio(num,'A','B','C');
	cout<<"========移动完成========"<<endl;
	cout<<num<<"个盘子进行汉诺塔移动规则的总移动次数为:　"<<count<<endl;
	return 0;
}

