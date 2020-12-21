#include<stdio.h>
#include<iostream>
#include<queue>   //ＳＴＬ双端队列
#include<list>   //SＴＬ双向链表
#include<windows.h>
using namespace std;

int q_id=0;          //用于队列进程号的全局变量
int l_id=0;          //用于链表进程号的全局变量
int stime=0;         //系统时间，开始为0


struct Pro                     //调度进程的数据结构process
{
	int PID;         //进程标志号
	int starttime;   // 开始执行时间[进程到达时间]
	int endtime;    //结束时间
	int needtime;  // 预计执行时间
	int runtime;   //已经运行时间
	int count;    //计数器
};

struct node
{
 queue<Pro> qu;  //队列
 int priority;  //队列优先级，当前进程在处于哪个优先级
 int capacity;  //时间片
};

class diaodu                //调度算法以及所需要的数据结构类
{
public:
	diaodu()  //调度运行函数
	{
		capacity=30;        //初始化时间片为30
	}
	void create_q_pro();    //创建进程queue
	void create_l_pro();    //创建进程list
	void create_node();     //创建node队列
	void Fcfs();            //先来先服务调度算法
	void Sjf();             //短作业优先调度算法
	void RR();              //时间片轮转算法
	void Djfkdl();          //多级反馈队列算法
//	void HRRN();			//响应比优先调度算法
//	void SRT();				//最短剩余时间优先调度算法

private:
	queue<Pro>Queue;   //进程队列
    list<Pro>Plist;    //进程链表
	list<node>ListQ;   //链表队列【多个队列】
	int capacity;      //时间片
};
/*创建进程队列*/
void diaodu::create_q_pro()
{
      Pro item;
   item.PID=++q_id; //进程序列号逐项加一
   item.count=0;
   item.needtime=rand()%100+10;
   item.runtime=0;
   Queue.push(item);
   printf("创建进程 PID= %d:  执行所需时间 = %d\n",item.PID,item.needtime);
}



void diaodu::create_l_pro()
{
 Pro item;
 item.PID=++l_id;
 item.count=0;
 item.needtime=rand()%200+10;
 item.runtime=0;
 Plist.push_back(item);
 printf("创建进程 PID = %d:   执行所需时间 = %d\n",item.PID,item.needtime);
}

void diaodu::create_node()
{
 node nod;
 int i;
 nod.priority=1;       //初始队列最高优先级1
 nod.capacity=20;      //初始时间片20
 for(i=0;i<10;++i)     //创建一个node类型，并放入ListQ内
 {
     Pro item;
     item.PID=++q_id;
     item.count=0;
     item.needtime=rand()%100+10;
	 item.runtime=0;
     nod.qu.push(item);
     printf("创建进程 PID= %d:  执行所需时间 = %d\n",item.PID,item.needtime);
     printf("\n");
 }
 ListQ.push_back(nod);
}

void diaodu::Fcfs()         
{
    int i;
//	int rd;
 printf("-------先来先服务调度算法-------\n");
 for(i=0;i<10;i++)
 {
  create_q_pro();
  printf("\n");
 }
 while(!Queue.empty())
 {
  Pro *p=&Queue.front();
  p->starttime=stime;
  printf("进程PID=%d: 执行所需时间%d 开始执行时间%d ",p->PID,p->needtime,p->starttime);
  Sleep(p->needtime*50);
  p->endtime=stime+p->needtime;
  printf("结束时间%d\n",p->endtime);
  printf("\n");
  Queue.pop();
  stime=p->endtime;
/*
  rd=rand()%10;
  if(rd>6)
  {
   create_q_pro();
   printf("\n");
  }
  */
 }
}

void diaodu::Sjf()
{
    int i,rd;
    printf("-------短作业优先调度算法-------\n");
 stime=0;
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

void diaodu::RR()
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

void diaodu::Djfkdl()
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
   rd=rand()%10;
      if(rd>7)       //有新进程进入高优先级队列
   {
    list<node>::iterator iter2=ListQ.begin();
    Pro item;
    item.PID=++q_id;
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

int main()
{
	diaodu schedul;
	Sleep(3*1000);
	schedul.Fcfs();    //先来先服务
	printf("\n\n\n");
	cout<<endl;
	cout<<"FCFS算法结束．．．．"<<endl;
	Sleep(10*1000);
//	schedul.Sjf();     //短作业优先
//	Sleep(20*1000);
//	schedul.RR();      //时间片轮转           
//	Sleep(3*1000);
//	schedul.Djfkdl();  //多级反馈队列
	return 0;
}
