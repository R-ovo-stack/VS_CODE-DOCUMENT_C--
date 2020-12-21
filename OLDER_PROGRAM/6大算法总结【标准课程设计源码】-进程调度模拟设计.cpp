#include<iostream>
#include<stdio.h>
#include<queue>    //ＳＴＬ双端队列
#include<list>   //SＴＬ双向链表
#include<windows.h>  //需要用到sleep()
using namespace std;

int queue_id=0;     //用于队列进程号的全局变量
int list_id=0;      //用于链表进程号的全局变量
int stime=0;        //系统时间，开始为0


struct Pro                     //调度进程的数据结构
{
  int PID;        //进程标志号
  int starttime;  // 开始执行时间
  int endtime;    //结束时间
  int needtime;   // 预计执行时间
  int runtime;    //已经运行时间
  int count;      //计数器
};

struct node
{
    queue<Pro> qu; //构建队列
    int priority;  //队列优先级，当前进程在处于哪个优先级
    int capacity;  //时间片
};

class diaodu         //调度类
{
public: 
    diaodu()
    {
         capacity=30;        //初始化时间片为30
    }
    void create_q_pro();    //创建进程queue的函数
    void create_l_pro();    //创建进程list的函数
    void create_node();     //创建node队列
    void Fcfs();            //先来先服务调度算法
    void Sjf();             //短作业优先调度算法
    void RR();              //时间片轮转算法
    void Djfkdl();          //多级反馈队列算法
//	void HRRN();			//响应比优先调度算法
//	void SRT();				//最短剩余时间优先调度算法
private:
    queue<Pro>Queue;   //队列
    list<Pro>Plist;     //链表
    list<node>ListQ;   //链表队列
    int capacity;   //时间片
};
/*创建进程queue*/
void diaodu::create_q_pro()  
{
    Pro item;   //创建一个进程
    item.PID=++queue_id;  //进程标识符[均从0开始增加]
    item.needtime=rand()%100+10;  //预计执行时间以随机数表示
    item.runtime=0;   //已执行时间
    item.count=0;   //计数器置零
    Queue.push(item);  //压入一个ITEM进程进入该队列
    printf("创建进程 PID= %d:  执行所需时间 = %d\n",item.PID,item.needtime);  //每压入一个进程输出该进程信息
}
/*创建进程list*/
void diaodu::create_l_pro()
{
    Pro item; //创建一个进程
    item.PID=++list_id;  //进程标识符[均从0开始增加]
    item.count=0;   //计数器置零
    item.needtime=rand()%200+10;   //预计执行时间以随机数表示
    item.runtime=0;    //已经运行时间初始化为0
    Plist.push_back(item);  //将进程item压入链表中
    printf("创建进程 PID = %d:   执行所需时间 = %d\n",item.PID,item.needtime); //每压入一个进程输出该进程信息
}
/*创建node队列*/
void diaodu::create_node()
{
    node nod;   //创建一个
    int i;
    nod.priority=1;       //初始队列最高优先级1
    nod.capacity=20;      //初始时间片20
    for(i=0;i<10;++i)     //创建一个node类型，并放入ListQ内
    {
         Pro item;
         item.PID=++queue_id;
         item.count=0;
         item.needtime=rand()%100+10;
         item.runtime=0;
         nod.qu.push(item);
         printf("创建进程 PID= %d:  执行所需时间 = %d\n",item.PID,item.needtime);
      printf("\n");
    }
    ListQ.push_back(nod);
}

void diaodu::Fcfs()       //先来先服务调度算法
{
    int i,rd;  //rd为随机数传递中间变量,i为循环控制数
    printf("-------先来先服务调度算法-------\n");

    /*初始化队列：：创建10个进程放入队列中*/

    for(i=0;i<10;i++)
    {
        create_q_pro();  //类内函数是可以相互调用的
        printf("\n");
    }
    /*若队列不为空，则一直进行循环*/
    while(!Queue.empty())
    {
        Pro *p=&Queue.front(); //定义队头指针
        p->starttime=stime; //开始执行时间置零
        printf("进程PID=%d: 执行所需时间%d 开始执行时间%d ",p->PID,p->needtime,p->starttime); //输出
        Sleep(p->needtime);   //屏幕休眠
        p->endtime=stime+p->needtime; //计算该进程结束时间
        printf("结束时间%d\n",p->endtime);   //输出该进程结束时间
        printf("\n");
        Queue.pop();   //若进程结束，则从进程队列中删除pop
        stime=p->endtime;   //系统时间被赋值为上一结束时间
        rd=rand()%10;   //通过随机数rd 判断是否需要添加进程
        if(rd>6)   //若随机数rd大于6，则向进程队列中增加一个进程
        {
            create_q_pro();   //加入新进程 
            printf("\n");  
        }
    }
}

void diaodu::Sjf()  //短进程优先调度算法
{
    int i,rd;
    printf("-------短作业优先调度算法-------\n");
    stime=0; //系统时间置零
    /*进程链表初始化：：创建10个进程【以pid递增的随机进程】*/
    for(i=0;i<10;i++)
    {
        create_l_pro();
        printf("\n");
    }
    while(!Plist.empty())
    {
        std::list<Pro>::iterator q=Plist.begin();    
        for(std::list<Pro>::iterator p=Plist.begin();p!=Plist.end();++p)         //找到最短预计执行时间的进程
        {
            if(p->needtime<q->needtime)
            { 
                q=p;
            }
        }
        q->starttime=stime;
        printf("进程PID=%d: 执行所需时间%d 开始执行时间%d ",q->PID,q->needtime,q->starttime);
        Sleep(q->needtime);
        q->endtime=stime+q->needtime;
        printf("结束时间%d\n",q->endtime);
        printf("\n");
        stime=q->endtime;
        Plist.erase(q);           //擦除进程
        rd=rand()%10;
        if(rd>6)
        {
            create_l_pro();
             printf("\n");
        }
    }
}

void diaodu::RR()  //时间片轮转调度算法
{
    int i,rd;
    stime=0;
    printf("-------时间片轮转法(时间片 = %d)-------\n",capacity);
    for(i=0;i<10;i++)
    {
        create_q_pro();
          printf("\n");
    }
    while(!Queue.empty())
    {
         Pro *p=&Queue.front();
         p->starttime=stime;
         printf("进程PID=%d: 执行还需时间%d 开始执行时间%d ",p->PID,p->needtime,p->starttime);
         if(p->needtime>capacity)
         {
             Sleep(capacity);
             p->needtime-=capacity;
             p->runtime+=capacity;
             stime+=capacity;
             ++(p->count);
             printf("第 %d 次执行，已执行时间 = %d\n",p->count,p->runtime);
             Queue.push(Queue.front());
             Queue.pop();
        }
        else
        {
            Sleep(p->needtime);
            stime+=p->needtime;
            p->endtime=stime;
            p->runtime+=p->needtime;
            ++(p->count);
            printf("第 %d 次执行，已执行时间 = %d 结束时间 = %d 执行完毕\n",p->count,p->runtime,p->endtime);
            p->needtime=0;
            Queue.pop();
        }
    printf("\n");
    rd=rand()%10;
    if(rd>6)
    {
        create_q_pro();
        printf("\n");
    }
    }
}

void diaodu::Djfkdl()   //多级反馈队列调度算法
{
    int rd,flag=0;              //flag标志是否有新进程进入初级队列
    stime=0;
    printf("-------多级反馈队列调度-------\n\n",capacity);
    create_node();
    for(list<node>::iterator iter=ListQ.begin();iter!=ListQ.end();)
    {
        printf("队列优先级 = %d 队列时间片 = %d\n",iter->priority,iter->capacity);
        while(!iter->qu.empty())
        {
            list<node>::iterator iter1=iter;
            Pro *p=&iter->qu.front();
            p->starttime=stime;
            printf("进程PID=%d: 执行还需时间%d 开始执行时间%d ",p->PID,p->needtime,p->starttime);
            if(p->needtime>iter->capacity)
            {
                Sleep(iter->capacity);
                p->needtime-=iter->capacity;
                p->runtime+=iter->capacity;
                stime+=iter->capacity;
                ++(p->count);
                printf("第 %d 次执行，已执行时间 = %d\n",p->count,p->runtime);
                if(++iter1==ListQ.end())           //如果没有下一队列，则创建下一队列
                {
                    node nod;
                    nod.qu.push(iter->qu.front());
                    nod.priority=iter->priority+1;
                    nod.capacity=iter->capacity*2;
                    ListQ.push_back(nod);
                }
                else                              //有下一队列，把当前进程放到下一队列队尾
                {
                    iter1->qu.push(iter->qu.front());
                }

                iter->qu.pop();
            }
            else
            {
                Sleep(p->needtime);
                stime+=p->needtime;
                p->endtime=stime;
                p->runtime+=p->needtime;
                ++(p->count);
                printf("第 %d 次执行，已执行时间 = %d 结束时间 = %d 执行完毕\n",p->count,p->runtime,p->endtime);
                p->needtime=0;
                iter->qu.pop();
            }
    printf("\n");
    rd=rand()%10;  //以随机数rd确定是否加入新的进程压入高优先级队列
    if(rd>7)       //有新进程进入高优先级队列
    {
        list<node>::iterator iter2=ListQ.begin();
        Pro item;
        item.PID=++queue_id;
        item.count=0;
        item.needtime=rand()%100+10;
        item.runtime=0;
        iter2->qu.push(item);
        printf("创建进程 PID= %d:  执行所需时间 = %d\n",item.PID,item.needtime);
        printf("\n");
        if(iter2->priority<iter->priority)   //若当前队列优先级不是最高优先级
        {
            flag=1;
            break;
        }
    }
    }
    if(flag==1)
    {
        iter=ListQ.begin();
    }
    else
    {
        ++iter;
    }
    flag=0;
    }
}

/*高响应比优先调度算法*/
/*
void diaodu::HRRN()
{



}*/

/*最短剩余时间调度算法*/
/*
void diaodu::SRT() 
{




}*/
int main()
{
    diaodu schedul;  //创建

    schedul.Fcfs();    //先来先服务

    printf("\n\n\n");

    Sleep(3*1000);   //计算机休眠1秒

    schedul.Sjf();     //短作业优先

    Sleep(3*1000);  //休眠3秒

    schedul.RR();      //时间片轮转    

    Sleep(3*1000);  //休眠3秒

    schedul.Djfkdl();  //多级反馈队列

    Sleep(3*1000);  //休眠3秒

    //schedul.SRT();  //最短剩余时间优先算法

    Sleep(3*1000);  //休眠3秒

    //schedul.HRRN();  //高响应比优先调度算法

    return 0;
}


//    Sleep(1000);   //计算机休眠1秒