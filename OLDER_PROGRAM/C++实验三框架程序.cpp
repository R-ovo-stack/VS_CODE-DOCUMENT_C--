#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();  //无参构造函数
	Date(int y,int m,int d);  //带参构造函数
	Date(Date &con_Date);  //拷贝构造函数
	void set_date();  //用以修改数据成员
	void get_date();  //用以获取数据成员并打印
	~Date();  //析构函数
};

Date::Date()
{
	cout<<"Date nocan constructed !"<<endl;
    year=1998;
    month=8;
    day=28;
}

Date::~Date()
{
	cout<<"Date deleted !"<<endl;
}

Date::Date(int y,int m, int d)
{
    cout<<"Date hancan constructed !"<<endl;
    year=y;
    month=m;
    day=d;
}

Date::Date(Date &con_Date)
{
    cout<<"Date kaobeicopy constructed ! "<<endl;
    year=con_Date.year;
    month=con_Date.month;
    day=con_Date.day;
}

void Date::set_date()
{
    cout<<"year: ";
    cin>>year;
    cout<<"month: ";
    cin>>month;
    cout<<"day: ";
    cin>>day; 
}

void Date::get_date()
{  
    cout<<year<<"--"<<month<<"--"<<day;
	cout<<endl;
}

class Student
{
public:
	Student();  //无参构造函数
	Student(Student &copy_stu);  //拷贝构造函数
	void set_Student();  //设置或者修改对象成员
	void get_Student();  //获取对象成员并打印
	Student(string ,string ,int ,int ,int ,string);  //有参构造函数
	~Student();  //析构函数
    int is_change();
private:
	string name;  //姓名
	string x_num;  //学号
	Date birthday;  //Date型出生日期
	string sex;   //boy and girl
};

Student::Student():birthday()
{
	cout<<"STudent constructed !"<<endl;
    name="罗彬彬";
    x_num="201820070215";
    sex="男";
	count++;
}

Student::~Student()
{
	cout<<"STudent"<<count--<<" deleted !"<<endl;
}

void Student::set_Student()
{
    cout<<"请输入修改后的信息: "<<endl;
    cout<<"学号: ";cin>>x_num;
    cout<<"姓名: ";cin>>name;
    cout<<"性别: ";cin>>sex;
    cout<<"生日: ";birthday.set_date();
	cout<<endl;
}

void Student::get_Student()  //输出
{
	cout<<"第"<<count<<"名学生的信息为: "<<endl;
    cout<<"姓名: "<<name<<endl;
    cout<<"学号: "<<x_num<<endl;
    cout<<"性别: "<<sex<<endl;
    cout<<"生日: ";
    birthday.get_date();
	cout<<endl;

}

Student::Student(string con_name,string con_num,int y,int m,int d, string con_sex):birthday(y,m,d)
{
    name=con_name;
    x_num=con_num;
    sex=con_sex;
	count++;
}

Student::Student(Student &copy_stu)
{
	cout<<"正在调用拷贝函数..."<<endl;
    name=copy_stu.name;
    x_num=copy_stu.x_num;
    sex=copy_stu.sex;
    birthday=copy_stu.birthday;
	count++;

}

/*自定义函数以决定是否要修改对象的对应成员数据*/
//由于对象在创建时已经被初始化了，故需此判断
int Student::is_change()
{
    int det;
    cout<<"是否要对该对象修改数据?"<<endl;
    cout<<"需要修改输入1，默认请输入0";
    cin>>det;
    return det;
}

void main()
{
    //T1.cpp
    Date d1();
    Date d2(Date d1);
    //T2.cpp
	Student s1;
	Student s2;

    //T3.cpp【此处为按照题目要求写的程序】
    int n;   //定义班级学生人数变量
	cout<<"请输入班级学生人数: "<<endl;
	cin>>n;
    cout<<"对该班级的"<<n<<"名学生进行信息载入及处理..."<<endl;
	Student *Stu;
	Stu=new Student[n];
    /*对每个学生的数据进行修改以及确认*/
    for(int i=0;i<n;i++)
    {
        cout<<"第"<<i+1<<"的基本信息为: ";
        Stu[i].get_Student();
        cout<<endl;
        cout<<"对第"<<i+1<<"名学生进行数据整理..."<<endl;
        stu[i].is_change();
        if(stu[i].is_change())
            stu[i].set_Student();
        else
            continue;
    }
    for(int j=0;j<n;j++)
    {
        cout<<"第"<<j+1<<"名学生的基本信息为: "<<endl;
        Stu[j].get_Student();
        cout<<endl;T.cpp
    }

    int n;   //定义班级学生人数变量
	cout<<"请输入班级学生人数: "<<endl;
	cin>>n;
    cout<<"对该班级的"<<n<<"名学生进行信息载入及处理..."<<endl;
	Student *Stu;
	Stu=new Student[n];
    /*对每个学生的数据进行修改以及确认*/
    for(int i=0;i<n;i++)
    {
        cout<<"第"<<i+1<<"的基本信息为: ";
        Stu[i].get_Student();
        cout<<endl;
    }
}