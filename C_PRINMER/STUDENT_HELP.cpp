/*
学生学籍信息管理系统
实现方式:c模块化编程
by:abin
date:2020/1/31
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define FilePath"studentInfoo.dat"   //数据文件的存储位置

class Student{
public:
    string id;   //学号
    string name; //姓名
    string sex;  //性别
    int age;     //年龄
    int cp;      //C语言成绩
    int en;      //英语成绩
    int math;    //数学成绩
    double avg;  //平均分
};

class Node{
public:
    Student stu;
    Node *next;
};

int choice = 0;  //菜单选择值

void creatNewFile(char *path);  //创建初始数据文件
Node *importData(FILE *fp);   //导入数据文件中的数据
Node *initData();   //初始化系统数据,并返回该单链表第一个节点指针
void MEAU();    //显示主菜单
void FINDMEAU(); //查找子菜单
void MODEFYMEAU();  //修改子菜单
void ALL(Node *head);  //显示所有学生信息
void ONE(Node *p);    //显示一个学生信息
Node *findBYID(Node *head, string id);  //按学号查找学生
Node *findBYNAME(Node *head, string name);  //按姓名查找学生
void MODIFY_STUDENT(Node *head);  //修改学生信息
void delete_STUDENT(Node *head);  //删除学生信息
void add_STUDENT(Node *head);  //增加一个学生
void saveDATA(Node *head);   //保存数据到文件中

int main(){
    Node *stuHEAD, *p;//存储学生信息的单链表
    string id;   //临时变量，用于接收输入的学号
    string name; //临时变量，用于接收输入的姓名
//  string sex; //临时变量，用于接收输入的性别
    stuHEAD = initData(); //初始化系统数据，导入学生信息
    while(1){
        MEAU();   //显示主操作菜单
        switch(choice)
        {
            case 1:
                ALL(stuHEAD);
                break;
            case 2:
                FINDMEAU();
                switch(choice){
                    case 1:
                        cout << endl
                             << "请输入要查找的学生学号:";
                        cin >> id;
                        p = findBYID(stuHEAD, id); //按学号进行查找
                        break;
                    case 2:
                        cout << endl
                             << "请输入要查找学生信息的姓名: ";
                        cin >> name;
                        p = findBYNAME(stuHEAD, name);
                        break;
                }
            case 3:
                MODEFYMEAU();  //修改学生信息
                break;
            case 4:
                delete_STUDENT(stuHEAD);   //删除学生
                break;
            case 5:
                add_STUDENT(stuHEAD);   //增加学生
                break;
            case 6:
                saveDATA(stuHEAD);  //保存信息到文件中
                break;
            case 0:
                saveDATA(stuHEAD);  //保存信息到文件中
                exit(0);
        }
    }
    return 0;
}

void creatNewFile(char *path)
{
    FILE *fp;  //定义文件指针
    Student stu;  //临时变量，用于接收输入的学生信息
    int i;  //统计输入的学生人数
    
    if((fp=fopen(path,"w"))==NULL)
    {
        cout << "无法建立新文件!" << endl;
        return;
    }
    cout << endl
         << "下面将输入学生的信息(学号输入\'$\'符号，结束输入): " << endl;
    while(1)
    {
        cout << "请输入第" << i++ << "名学生的信息:" << endl;
        cout << "=================" << endl;
        cout << "学号: \t";
        cin >> stu.id;
        if(stu.id=="$")
        {
            cout << "输入学生信息结束!" << endl;
            fclose(fp);
            return;
        }
        cout << "姓名: \t";
        cin >> stu.name;
        cout << "性别: \t";
        cin >> stu.sex;
        cout << "年龄: \t";
        cin >> stu.age;
        cout << "c语言成绩: \t";
        cin >> stu.cp;
        cout << "英语成绩： \t";
        cin >> stu.en;
        cout << "数学成绩： \t";
        cin >> stu.math;
        stu.avg = (stu.cp + stu.en + stu.math) / 3.0;
        cout << "=================" << endl;
        fwrite(&stu, sizeof(Student), 1, fp);   //写入数据到文件
    }
}

Node *importData(FILE *fp)
{
    Node *head = NULL, *p, *q;  //head指向链表头，p指向新节点，q指向链表最后一个节点
    Student stu; //用来存储学生信息的临时变量
    fread(&stu, sizeof(Student), 1, fp);  //从数据问价中读取一个学生信息[利用引用读取]
    while(!feof(fp))
    {
        if(head==NULL)  //处理第一个结点
        {
            //分配结点空间
            head = new Node;
            head->stu = stu;
            head->next = NULL;
            q = head;
        }
        else
        {
            p = new Node;
            p->stu = stu;
            p->next = NULL;
            q->next = p; //链接新节点到表尾
            q = p; //把q指针指向新节点，即表尾
        }
        fread(&stu, sizeof(Student), 1, fp);
    }
    return head; 
}

Node *initData()
{
    FILE *fp;
    Node *stuHEAD;
    //如果是第一次使用系统,打开文件不成功
    if((fp=fopen(FilePath,"r"))==NULL)
    {
        //可建立一个数据文件
        creatNewFile(FilePath);  //新建一个数据文件
        if ((fp = fopen(FilePath, "rb")) == NULL) {
                cout << "无法初始化数据,推出系统!" << endl;
                exit(1); //退出系统
            }
            stuHEAD = importData(fp); //导入新建的文件的数据
    }
    else
        stuHEAD = importData(fp); //导入已有的文件的数据
    fclose(fp);
    return stuHEAD;  //返回存储数据的单链表表头
}

void MEAU()
{
    while(1)
    {
        system("cls");
        cout << endl
             << "请选择操作: " << endl;
        cout << "================" << endl;
        cout << "(1).显示所有学生信息\t";
        cout << "(2).查询单个学生信息"
             << endl;
        cout << "(3).修改学生信息\t";
        cout << "(4).删除学生信息" << endl;
        cout << "(5).增加学生信息\t";
        cout << "(6).保存修改\n\n";
        cout << "(0).退出程序" << endl;
        cout << "================" << endl;
        choice = getche();
        cout << endl;
        /*
        if((choice-0)<0||(choice-0)>6)
        {
            cout << "\n请选择正确的操作！" << endl;
            system("pause");
        }
        else
            return;
        */
    }
}

void FINDMEAU()
{
    while(1)
    {
        system("cls");
        cout << "\n请选择查找操作: \n";
        cout << "===============" << endl;
        cout << "(1).按学号查找信息\t(2).按姓名查找信息\n\n";
        cout << "===============" << endl;
        choice = getche();
        cout << endl;
        /*
        if((choice-0)<1||(choice-0)>2)
        {
            cout << "\n请选择正确的操作！" << endl;
            system("pause");
        }
        else
            return;
        */
    }
}

void MODEFYMEAU()
{
    while(1)
    {
        system("cls");
        cout << "\n请输入修改操作:\n";
        cout << "===============" << endl;
        cout << "(1).修改学生的年龄\t\t(2).修改学生C语言成绩\n";
        cout << "(3).修改学生的英语成绩\t\t(4).修改学生的数学成绩\n\n";
        cout << "===============" << endl;
        choice = getche();
        /*
        if((choice-0)<1||(choice-0)>4)
        {
            cout << "\n请选择正确的操作！" << endl;
            system("pause");
        }
        else
            return;
        */
    }
}

void ALL(Node *head)
{
    Node *p = head;
    system("cls");
    if(head==NULL)
    {
        cout << "\n没有学生信息!\n";
        return;
    }
    cout << "\n所有学生信息:\n=================\n";
    cout << "学号姓名性别年龄C语言英语数学平均分\n";
    cout << "=================\n";
    while(p!=NULL)
    {
        cout << p->stu.id << p->stu.name << p->stu.sex << p->stu.cp << p->stu.en << p->stu.math;
        p = p->next;
    }
    cout << "=================\n";
    system("pause");
}

void ONE(Node *p)
{
    system("cls");
    if(p==NULL)
    {
        cout << "\n学生不存在!\n";
        system("pause");
        return;
    }
    cout << "查找的学生信息如下： \n";
    cout << "学号姓名性别年龄C语言英语数学平均分\n";
    cout << "=================\n";
    cout << p->stu.id << p->stu.name << p->stu.sex << p->stu.cp << p->stu.en << p->stu.math;
    cout << "=================\n";
    system("pause");
}

Node *findBYID(Node *head,string id)
{

}
Node *findBYNAME(Node *head,string name)
{

}
void MODIFY_STUDENT(Node *head)
{

}
void delete_STUDENT(Node *head)
{

}
void add_STUDENT(Node *head)
{

}
void saveDATA(Node *head)
{

}