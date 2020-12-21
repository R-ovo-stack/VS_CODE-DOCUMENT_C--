#include<stdio.h>
#include<iostream>
#include<queue>   //�ӣԣ�˫�˶���
#include<list>   //S�ԣ�˫������
#include<windows.h>
using namespace std;

int q_id=0;          //���ڶ��н��̺ŵ�ȫ�ֱ���
int l_id=0;          //����������̺ŵ�ȫ�ֱ���
int stime=0;         //ϵͳʱ�䣬��ʼΪ0


struct Pro                     //���Ƚ��̵����ݽṹprocess
{
	int PID;         //���̱�־��
	int starttime;   // ��ʼִ��ʱ��[���̵���ʱ��]
	int endtime;    //����ʱ��
	int needtime;  // Ԥ��ִ��ʱ��
	int runtime;   //�Ѿ�����ʱ��
	int count;    //������
};

struct node
{
 queue<Pro> qu;  //����
 int priority;  //�������ȼ�����ǰ�����ڴ����ĸ����ȼ�
 int capacity;  //ʱ��Ƭ
};

class diaodu                //�����㷨�Լ�����Ҫ�����ݽṹ��
{
public:
	diaodu()  //�������к���
	{
		capacity=30;        //��ʼ��ʱ��ƬΪ30
	}
	void create_q_pro();    //��������queue
	void create_l_pro();    //��������list
	void create_node();     //����node����
	void Fcfs();            //�����ȷ�������㷨
	void Sjf();             //����ҵ���ȵ����㷨
	void RR();              //ʱ��Ƭ��ת�㷨
	void Djfkdl();          //�༶���������㷨
//	void HRRN();			//��Ӧ�����ȵ����㷨
//	void SRT();				//���ʣ��ʱ�����ȵ����㷨

private:
	queue<Pro>Queue;   //���̶���
    list<Pro>Plist;    //��������
	list<node>ListQ;   //������С�������С�
	int capacity;      //ʱ��Ƭ
};
/*�������̶���*/
void diaodu::create_q_pro()
{
      Pro item;
   item.PID=++q_id; //�������к������һ
   item.count=0;
   item.needtime=rand()%100+10;
   item.runtime=0;
   Queue.push(item);
   printf("�������� PID= %d:  ִ������ʱ�� = %d\n",item.PID,item.needtime);
}



void diaodu::create_l_pro()
{
 Pro item;
 item.PID=++l_id;
 item.count=0;
 item.needtime=rand()%200+10;
 item.runtime=0;
 Plist.push_back(item);
 printf("�������� PID = %d:   ִ������ʱ�� = %d\n",item.PID,item.needtime);
}

void diaodu::create_node()
{
 node nod;
 int i;
 nod.priority=1;       //��ʼ����������ȼ�1
 nod.capacity=20;      //��ʼʱ��Ƭ20
 for(i=0;i<10;++i)     //����һ��node���ͣ�������ListQ��
 {
     Pro item;
     item.PID=++q_id;
     item.count=0;
     item.needtime=rand()%100+10;
	 item.runtime=0;
     nod.qu.push(item);
     printf("�������� PID= %d:  ִ������ʱ�� = %d\n",item.PID,item.needtime);
     printf("\n");
 }
 ListQ.push_back(nod);
}

void diaodu::Fcfs()         
{
    int i;
//	int rd;
 printf("-------�����ȷ�������㷨-------\n");
 for(i=0;i<10;i++)
 {
  create_q_pro();
  printf("\n");
 }
 while(!Queue.empty())
 {
  Pro *p=&Queue.front();
  p->starttime=stime;
  printf("����PID=%d: ִ������ʱ��%d ��ʼִ��ʱ��%d ",p->PID,p->needtime,p->starttime);
  Sleep(p->needtime*50);
  p->endtime=stime+p->needtime;
  printf("����ʱ��%d\n",p->endtime);
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
    printf("-------����ҵ���ȵ����㷨-------\n");
 stime=0;
 for(i=0;i<10;i++)
 {
  create_l_pro();
  printf("\n");
 }
 while(!Plist.empty())
 {
     std::list<Pro>::iterator q=Plist.begin();
     for(std::list<Pro>::iterator p=Plist.begin();p!=Plist.end();++p)         //�ҵ����Ԥ��ִ��ʱ��Ľ���
  {
     if(p->needtime<q->needtime)
     { 
      q=p;
     }
  }
     q->starttime=stime;
     printf("����PID=%d: ִ������ʱ��%d ��ʼִ��ʱ��%d ",q->PID,q->needtime,q->starttime);

     Sleep(q->needtime);
     q->endtime=stime+q->needtime;
     printf("����ʱ��%d\n",q->endtime);
  printf("\n");
     stime=q->endtime;
      Plist.erase(q);           //��������
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
 printf("-------ʱ��Ƭ��ת��(ʱ��Ƭ = %d)-------\n",capacity);
 for(i=0;i<10;i++)
 {
  create_q_pro();
  printf("\n");
 }
 while(!Queue.empty())
 {
  Pro *p=&Queue.front();
  p->starttime=stime;
  printf("����PID=%d: ִ�л���ʱ��%d ��ʼִ��ʱ��%d ",p->PID,p->needtime,p->starttime);
  if(p->needtime>capacity)
  {
      Sleep(capacity);
   p->needtime-=capacity;
   p->runtime+=capacity;
   stime+=capacity;
   ++(p->count);
   printf("�� %d ��ִ�У���ִ��ʱ�� = %d\n",p->count,p->runtime);
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
            printf("�� %d ��ִ�У���ִ��ʱ�� = %d ����ʱ�� = %d ִ�����\n",p->count,p->runtime,p->endtime);
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
    int rd,flag=0;              //flag��־�Ƿ����½��̽����������
 stime=0;
 printf("-------�༶�������е���-------\n\n",capacity);
 create_node();
    for(list<node>::iterator iter=ListQ.begin();iter!=ListQ.end();)
 {
  printf("�������ȼ� = %d ����ʱ��Ƭ = %d\n",iter->priority,iter->capacity);
  while(!iter->qu.empty())
  {
   list<node>::iterator iter1=iter;
   Pro *p=&iter->qu.front();
   p->starttime=stime;
   printf("����PID=%d: ִ�л���ʱ��%d ��ʼִ��ʱ��%d ",p->PID,p->needtime,p->starttime);
   if(p->needtime>iter->capacity)
   {
    Sleep(iter->capacity);
    p->needtime-=iter->capacity;
    p->runtime+=iter->capacity;
    stime+=iter->capacity;
    ++(p->count);
    printf("�� %d ��ִ�У���ִ��ʱ�� = %d\n",p->count,p->runtime);
    if(++iter1==ListQ.end())           //���û����һ���У��򴴽���һ����
    {
     node nod;
     nod.qu.push(iter->qu.front());
     nod.priority=iter->priority+1;
     nod.capacity=iter->capacity*2;
        ListQ.push_back(nod);
    }
    else                              //����һ���У��ѵ�ǰ���̷ŵ���һ���ж�β
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
    printf("�� %d ��ִ�У���ִ��ʱ�� = %d ����ʱ�� = %d ִ�����\n",p->count,p->runtime,p->endtime);
    p->needtime=0;
    iter->qu.pop();
   }
   printf("\n");
   rd=rand()%10;
      if(rd>7)       //���½��̽�������ȼ�����
   {
    list<node>::iterator iter2=ListQ.begin();
    Pro item;
    item.PID=++q_id;
    item.count=0;
    item.needtime=rand()%100+10;
    item.runtime=0;
    iter2->qu.push(item);
    printf("�������� PID= %d:  ִ������ʱ�� = %d\n",item.PID,item.needtime);
    printf("\n");
    if(iter2->priority<iter->priority)   //����ǰ�������ȼ�����������ȼ�
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
	schedul.Fcfs();    //�����ȷ���
	printf("\n\n\n");
	cout<<endl;
	cout<<"FCFS�㷨������������"<<endl;
	Sleep(10*1000);
//	schedul.Sjf();     //����ҵ����
//	Sleep(20*1000);
//	schedul.RR();      //ʱ��Ƭ��ת           
//	Sleep(3*1000);
//	schedul.Djfkdl();  //�༶��������
	return 0;
}
