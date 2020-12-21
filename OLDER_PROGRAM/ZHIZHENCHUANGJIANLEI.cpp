/*
by:liu zhifeng[fffengzai]
最后一次修改时间：2019/12/8
修正 by：luo BINBIN
*/

#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string a="1314",int b=1)
	{ number=a; age=b;}
	virtual void Active()=0 ;  //声明纯虚函数，后面是=0
	
protected:
	string number;
	int age;
};

class Student: public Person
{
public:
	Student(float a):Person(number,age){}
    virtual void Active()
	{	cout<<"学生主要任务是学习"<<endl;  }

private:
	float m_fScore;
};

class Worker: public Person
{
public:
	Worker(float a):Person(number,age){}
	virtual  void Active()
	{  cout<<"工人主要任务是工作"<<endl; }

private:
	float m_fSalary; 
};

int main()
{
	Person *p;
	p=new Student(95);
	p->Active();
	Person *q;
	q=new Worker(15000);
	q->Active();
	delete[] p;
	delete[] q;
	return 0;
	system("pause");
}

                      /*修正版*/

/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string a="1314",int b=1)
	{ 
		number=a; age=b;
		cout<<"number is : "<<number<<"\t"<<"age is : "<<age<<endl;
	}
	virtual void Active()=0 ;  //声明纯虚函数，后面是=0
	
protected:
	string number;
	int age;
};

class Student: public Person
{
public:
	Student(float a)   //:Person(number,age)
	{
		m_fScore=a;
	}
    virtual void Active()
	{
		cout<<"学生主要任务是学习"<<endl;  
		cout<<"THe score is : "<<m_fScore<<endl;
	}

private:
	float m_fScore;
};

class Worker: public Person
{
public:
	Worker(float a)  // :Person(number,age)
	{
		m_fSalary=a;
	}
	virtual  void Active()
	{
		cout<<"工人主要任务是工作"<<endl; 
		cout<<"THe salary is : "<<m_fSalary<<endl;
	}

private:
	float m_fSalary; 
};

int main()
{
	Person *p;  //此处person改为student 也行，最好是student
	p=new Student(95);
	p->Active();
	Person *q;   //此处person改为worker 也行
	q=new Worker(15000);	
	q->Active();
	cout<<endl;
	delete p;
	delete q;
	return 0;
}

*/