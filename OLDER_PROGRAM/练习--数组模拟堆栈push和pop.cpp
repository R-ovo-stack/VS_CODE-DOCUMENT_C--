#include<iostream>
using namespace std;
# define MAXSIZE 100

/*top以及stack应该均定义为全局变量并初始化
【不可定义为静态static】*/

int top=-1;
int stack[MAXSIZE];


int isempty()   //判断堆栈元素是否为空
{
    if(top==-1)
		return 1;
    else
		return 0;
}

void push(int data)
{
    if(top>=MAXSIZE)
	{
        cout<<"堆栈已满，无法再加入元素!"<<endl;
    }
    else
    {
        stack[++top]=data;
    }
}

int pop()
{
    if(isempty())
        return -1;
    else
	{
        return stack[top--];
	}
}

int main(void)
{
    int temp;
	int i;

    cout<<"请按顺序输入10个数据:"<<endl;
    for( i=0;i<10;i++)
    {
        cin>>temp;
        push(temp);
    }
    cout<<"======================"<<endl;
    /*
    while(!empty())
        cout<<"堆栈弹出的顺序为: "<<pop()<<endl;
    */
    for( i=10;i>0;i--)
    {
        cout<<"堆栈弹出的顺序为: "<<pop()<<endl;
    }
    cout<<"======================"<<endl;
    return 0;
}