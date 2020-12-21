#include<iostream>
#include<conio.h>
#include<cstring>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int LEN = 10;  //人名的长度10以内
const string OVER = "exit";  //输入结束的字符串

class person{
public:
    string name;
    int pwd;  //密码
    person *next;  //定义类指针
};   //定义person类

//此处的链表为全局链表——适用于所有函数
person *head = NULL;  //指向表节点的指针
person *tail = NULL;  //指向表末结点的指针
int choose;

void InputPerson();  //输入操作，初始化链表
void MEAU();   //显示操作菜单
void Display();  //显示链表信息
void ResetPwd();  //重新输入密码
void CountAndQuit();   //开始约瑟夫游戏

int num = 0;  //记录输入的人数

int  main()
{
    InputPerson();
    for (;;)
    {
        MEAU();
        switch(choose)
        {
            case 1:
                Display();  //显示链表信息
                break;
            case 2:
                ResetPwd();  //重输密码
                break;
            case 3:
                CountAndQuit();   //开始游戏
                break;
        }
    }
    return 0;
}

void InputPerson()   //初始化链表
{
    string name;
    int pwd;
    person *p; //新增加的人,此处仅仅定义指针，尚未new新的空间
    head = tail;  //开始首尾都是NULL
    for (;;)
    {
        cout << "请输入第" << ++num << "个人的信息: 输入" << OVER << "结束" << endl;
        cout << "人名: ";
        cin >> name;
        if(name==OVER)
            return;
        p = new person;
        p->name = name;  //将姓名赋值给链表

        //输入密码
        cout << "密码: " << num;
        cin >> pwd;
        p->pwd = pwd;  //设定密码

        p->next = head;   //首尾相连

        //创建链表
        if(NULL==head) 
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
        num++;  //新人添加链表中以后，计数器+1
        cout << endl;

    }
}

void MEAU()
{
    for (;;)
    {
        cout << endl
             << "请选择操作: ";
        cout <<endl<< "===============";
        cout << endl
             << "1.显示信息 ";
        cout << endl
             << "2.重新输入每个人的密码";
        cout << endl
             << "3.开始游戏";
        cout << endl
             << "0.退出程序";
        cout << endl
             << "请选择操作: ";
        if('0'==choose)
            exit(0);
        else if((choose-'0')>=0 && (choose-'0')<=3)
            return;
    }
}

void ResetPwd()
{
    person *p = head;  //从头结点开始
    //如果没有就终止
    if(NULL==p)
        return;
    cout << "\n\n"
         << "请重新输入每个人的密码: ";
    cout << "\n"
         << "================"
         << "\n";
    //先处理第一个人的密码
    cout << p->name;
    cin >> p->pwd;
    p = p->next;
    while(p!=head)
    {
        cout << p->name;
        cin >> p->pwd;
        p = p->next;
    }
    cout << "\n"
         << "==============" << endl;
}

void Display()
{
//    int i = 0;
    person *p = head;
    if(NULL==p)
        return;
    cout << "\n"
         << "当前链表信息如下: " << endl;
    cout << "================" << endl;
    cout << p->name << ": " << p->pwd << endl;
    p = p->next;
    while(p!=head)
    {
        cout << p->name << ": " << p->pwd << endl;
        p = p->next;
    }
    cout << "================" << endl;
}

//游戏步骤进行的实现函数
void CountAndQuit()  //新增删除节点步骤
{
    int i, n, pwd;   //用于计数，保存当前密码
    //首先复制一个链表
    person *p, *c, *q;   //分别指向临时节点，新链表的当前节点，当前节点的前节点
    person *head2 = NULL, *tail2 = NULL;  //新链表的头尾
    c = head;
    //首节点不能为 NULL
    if(NULL==head)
    {
        return;
    }
    //先复制首届点
    p = new person;
    p->name = c->name;   //c为头结点
    p->pwd = c->pwd;
    p->next = p;
    head2 = tail2 = p; //第一个节点，首尾在一起
    c = c->next;
    //复制其他节点
    while(c!=head)
    {
        p = new person;
        p->pwd = c->pwd;
        p->name = c->name;
        p->next = head2;
        tail2->next = p;
        tail2 = p;
        c = c->next;
    }
    
    //开始数N 退出
    cout << "\n"
         << "游戏处理结果:"<<endl;
    cout << "=====================";
    i = 0;
    c = head2;
    q = tail2;
    pwd = c->pwd;
    while(c->next!=c)
    {
        n = 1;
        while(n<pwd)
        {
            q = c;
            c = c->next;
            n++;
        }
        //当前指针c所指的应该退出
        q->next = c->next;
        cout << "\n"
             << "第" << ++i << "个退出者" << endl;
        pwd = c->pwd;
        delete c;
        c = q->next;
    }
    //退出最后一个
    cout << "第" << ++i << "个退出者：" << c->name << endl;
    delete c;
    cout << "===================" << endl;
}