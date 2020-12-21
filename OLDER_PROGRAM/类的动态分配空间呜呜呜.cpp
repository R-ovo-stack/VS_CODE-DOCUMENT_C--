//题目：创建一个Student类，要求其成绩用指针数组动态输入，动态输入过程建立在构造函数中，并且要有输出信息函数
//注明:动态申请的内存需要在析构函数中被清理喔
/*程序一   用静态数组在类中建立成绩数组*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Student{
public:
	Student(string xname)
	{
		cout<<"Student constructed !"<<endl;
		if(!score)
			cout<<"申请空间失败!"<<endl;
		s_name=xname;
		int i;
		int otion;
		for(i=0;i<10;i++)
		{
			cin>>otion;
			score[i]=otion;
		}
	}
	void print();
private:
	string s_name;
	int score[10];

};


void Student::print()
{
	cout<<"该学生各科成绩如下: "<<endl;
	for(int i=0;i<10;i++)
		cout<<score[i]<<endl;
}

int main()
{
	Student Stu("Luoshushu");
	Stu.print();
	return 0;
}

/*程序二    利用动态申请内存动态输入数组变量【malloc】*/

#include<iostream>
#include<cstdlib>
using namespace std;
class Student {
public:
	Student(string xname)    //构造函数
	{
		cout << "Student constructed !" << endl;
		cout << "请输入该学生的学科数目: " <<endl;
		cin >> n;
		score=new int[n];
		int i;
	/*
		for(i=0;i<n;i++)
		{
			score=new int[1];			
			if (!score)
			cout << "申请空间失败!" << endl;
		}
	*/
		s_name = xname;  //为对象取名字
		int otion;
		for (i = 0; i < n; i++)
		{
			cin >> otion;
			*(score+i) = otion;
		}
	}
	~Student()   //析构函数
	{
		delete []score;
		cout << "The student is desconstructed ! " << endl;
	}

	void print();   //打印学生姓名以及各科成绩的信息
private:
	int n;  //学生科目数
	string s_name;  //这里仅定义一个学生的姓名为name
	int *score;  //定义一个指针指向成绩数组，其申请在构造函数内进行，清理则在析构函数内进行
};

void Student::print()
{
	cout << "该学生各科成绩如下: " << endl;
	for (int i = 0; i < n; i++)
		cout << *(score+i) << endl;
}

int main()
{
	Student Stu("Luoshushu");   //创建一个学生Student对象
	Stu.print();
	return 0;
}

/*
注意：对于new和delete的对应使用
new 与 delete 均指一个对象
new[] 与 delete[] 均指一个数组
在使用的时候必须两者一一对应，不然会出现内存泄露的问题
最好不要重复进行new行为，容易内存泄露，delete 无法释放第一次之后申请的内存，必定会引发内存泄露
*/