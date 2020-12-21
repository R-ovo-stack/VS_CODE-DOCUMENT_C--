//运用数组实现队列的创建以及队列的部分基本操作
//队列的基本性质: 先进先出
#include<iostream>
using namespace std;

#define MAXSIZE 20 //定义队列的最大容量为20
//由于数组第一位为array[0],所以定义-1为队列的底部
/*最开始头部和尾部都是没有元素的，位置均为-1*/
int queue[MAXSIZE];   //创建队列
int front=-1;   //定义队列头标志符
int rear=-1;    //定义队列尾标志符

void enqueue(int data)  //将新的数据加入到队列的末尾，返回新队列
{
    if(rear==MAXSIZE-1)
        cout<<"队列已满!"<<endl;
    else
        queue[++rear]=data;
}

void dequeue(int queue[])  //删除队列最前端元素，返回新队列  
{
    if(front==rear)
        cout<<"队列已空！"<<endl;
    else
        cout<<"删除的值为: ";
}

int Front_value(int queue[])
{
        return queue[++front];
}//返回队列前端的值

int main()
{
    int temp;
    int flag=1;
    char set;
    while(flag)
    {
    cout<<"[I]：存入一个数值 [G]：取出一个数值 [E]: 结束 "<<endl;
    cin>>set;
    switch(set)
    {
        case 'I' :
			cout<<"请输入要加入的值: ";
            cin>>temp;
            enqueue(temp);
            break;
        case 'G' :
            dequeue(queue);
            cout<<Front_value(queue)<<endl;
            break;
        case 'E' :
            exit(0);      
    }
    }
    return 0;
}
