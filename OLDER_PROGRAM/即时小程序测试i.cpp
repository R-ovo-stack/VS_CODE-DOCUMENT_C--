#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>    //�ӣԣ�˫�˶���
#include<list>   //S�ԣ�˫������
#include<windows.h>  //��Ҫ�õ�sleep()
#include<time.h>
using namespace std;

int queue_id=0;     //���ڶ��н��̺ŵ�ȫ�ֱ���
int list_id=0;      //����������̺ŵ�ȫ�ֱ���
int xxx_id=0;
int stime=0;        //ϵͳʱ�䣬��ʼΪ0


struct Pro                     //���Ƚ��̵����ݽṹ
{
  int PID;        //���̱�־��
  int starttime;  //��ʼִ��ʱ��
  int endtime;    //����ʱ��
  int needtime;   //Ԥ��ִ��ʱ��
  int runtime;    //�Ѿ�����ʱ��
  int count;      //������
  double pri;    //��Ӧ��
  int resttime;    //ʣ��ʱ��
};

struct node
{
    queue<Pro> qu; //��������
    int priority;  //�������ȼ�����ǰ�����ڴ����ĸ����ȼ�
    int capacity;  //ʱ��Ƭ
};

class diaodu         //������
{
public: 
    diaodu()
    {
         capacity=30;        //��ʼ��ʱ��ƬΪ30
    }
    void create_q_pro();    //��������queue�ĺ���
    void create_l_pro();    //��������list�ĺ���
    void create_node();     //����node����
    void Fcfs();            //�����ȷ�������㷨
    void Sjf();             //����ҵ���ȵ����㷨
    void RR();              //ʱ��Ƭ��ת�㷨
    void Djfkdl();          //�༶���������㷨
	void HRRN();			//����Ӧ�����ȵ����㷨
	void SRT();				//���ʣ��ʱ�����ȵ����㷨
private:
    queue<Pro>Queue;    //����
    list<Pro>Plist;     //����
    list<node>ListQ;    //�������
    int capacity;       //ʱ��Ƭ
//  vector<Pro>Array;
};
/*��������queue*/
void diaodu::create_q_pro()  
{
    Pro item;   //����һ������
    item.PID=++queue_id;  //���̱�ʶ��[����0��ʼ����]
    item.needtime=rand()%100+10;  //Ԥ��ִ��ʱ�����������ʾ
    item.runtime=0;   //��ִ��ʱ��
    item.count=0;   //����������
    Queue.push(item);  //ѹ��һ��ITEM���̽���ö���
    printf("�������� PID= %d:  ִ������ʱ�� = %d\n",item.PID,item.needtime);  //ÿѹ��һ����������ý�����Ϣ
}
/*��������list*/
void diaodu::create_l_pro()
{
    Pro item; //����һ������
    item.PID=++list_id;  //���̱�ʶ��[����0��ʼ����]
    item.count=0;   //����������
    item.needtime=rand()%200+10;   //Ԥ��ִ��ʱ�����������ʾ
    item.runtime=0;    //�Ѿ�����ʱ���ʼ��Ϊ0
    item.resttime=item.needtime-item.runtime;
    item.pri=(item.needtime+item.starttime)/item.needtime; //////////////////////////
    Plist.push_back(item);  //������itemѹ��������
    printf("�������� PID = %d:   ִ������ʱ�� = %d\n",item.PID,item.needtime); //ÿѹ��һ����������ý�����Ϣ
}
/*����node����*/
void diaodu::create_node()
{
    node nod;   //����һ��duilie
    int i;
    nod.priority=1;       //��ʼ����������ȼ�1
    nod.capacity=20;      //��ʼʱ��Ƭ20
    for(i=0;i<10;++i)     //����һ��node���ͣ�������ListQ��
    {
		 Pro item;
         item.PID=++queue_id;
         item.count=0;
         item.needtime=rand()%100+10;
         item.runtime=0;
         nod.qu.push(item);    
         printf("�������� PID= %d:  ִ������ʱ�� = %d\n",item.PID,item.needtime);
         printf("\n");
    }
    ListQ.push_back(nod);
}

void diaodu::Fcfs()       //�����ȷ�������㷨
{
    int i,rd;  //rdΪ����������м����,iΪѭ��������
    printf("-------�����ȷ�������㷨-------\n");
    /*��ʼ�����У�������10�����̷��������*/
    for(i=0;i<10;i++)
    {
        create_q_pro();  //���ں����ǿ����໥���õ�
        printf("\n");
    }
    /*�����в�Ϊ�գ���һֱ�� �н��� */
    while(!Queue.empty())
    {
        Pro *p=&Queue.front(); //�����ͷָ��
        p->starttime=stime; //��ʼִ��ʱ������,��ϵͳʱ��ı���仯,��һ�����̵Ľ���ʱ�伴Ϊ��һ���̵Ŀ�ʼִ��ʱ��
        printf("����PID=%d: ִ������ʱ��%d ��ʼִ��ʱ��%d ",p->PID,p->needtime,p->starttime); //���
        Sleep(p->needtime);   //��Ļ����
        p->endtime=stime+p->needtime; //����ý��̽���ʱ��
        printf("����ʱ��%d\n",p->endtime);   //����ý��̽���ʱ��
        printf("\n");
        Queue.pop();   //�����̽�������ӽ��̶�����ɾ��pop
        stime=p->endtime;   //ϵͳʱ�䱻��ֵΪ��һ����ʱ��
        rd=rand()%10;   //ͨ�������rd �ж��Ƿ���Ҫ��ӽ���
        if(rd>6)   //�������rd����6��������̶���������һ������
        {
            create_q_pro();   //�����½��� 
            printf("\n");  
        }
    }
}

void diaodu::Sjf()  //�̽������ȵ����㷨
{
    int i,rd;
    printf("-------����ҵ���ȵ����㷨-------\n");
    stime=0; //ϵͳʱ������
    /*���������ʼ����������10�����̡���pid������������̡�*/
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

void diaodu::RR()  //ʱ��Ƭ��ת�����㷨
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
         if(p->needtime>capacity)  //capacity:ʱ��Ƭ
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

void diaodu::Djfkdl()   //�༶�������е����㷨
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
            rd=rand()%10;  //�������rdȷ���Ƿ�����µĽ���ѹ������ȼ�����
            if(rd>7)       //���½��̽�������ȼ�����
            {
                list<node>::iterator iter2=ListQ.begin();
                Pro item;
                item.PID=++queue_id;
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

/*����Ӧ�����ȵ����㷨*/

void diaodu::HRRN()
{
    int i,rd;
    stime=0;
    printf("-------����Ӧ�����ȵ����㷨-------\n");
    for(i=0;i<10;i++)
    {
        create_q_pro();
        printf("\n");
    }
    while(!Queue.empty())
    {
        std::list<Pro>::iterator q=Plist.begin(); //ͷָ��   
        for(std::list<Pro>::iterator p=Plist.begin();p!=Plist.end();++p)  //�ҵ���Ӧ����͵Ľ���
            if(p->pri>q->pri)
            { 
                q=p;
            }
        }
        q->starttime=stime;
        printf("����PID=%d: ִ�л���ʱ��%d ��ʼִ��ʱ��%d ",p->PID,p->needtime,p->starttime);
        Sleep(q->needtime);
        q->endtime=stime+q->needtime;
        printf("����ʱ��%d\n",q->endtime);
        printf("\n");
        stime=q->endtime;
        Plist.erase(q);           //��������
        rd=rand()%10;
        if(rd>6)
        {
         create_q_pro();
         printf("\n");
        }
    }
}


/*=========���ʣ��ʱ������㷨=========*/

void diaodu::SRT() 
{
    int i��
	int	rd;
    printf("-------���ʣ��ʱ�������㷨-------\n");
    stime=0; //ϵͳʱ������
    /*���������ʼ����������10�����̡���pid������������̡�*/
    for(i=0;i<10;i++)
    {
        create_l_pro();
        printf("\n");
    }
    while(!Plist.empty())
    {
        std::list<Pro>::iterator q=Plist.begin();    
        for(std::list<Pro>::iterator p=Plist.begin();p!=Plist.end();++p)         //�ҵ�ʣ��ʱ����̵Ľ���
        {
            if(p->resttime<q->resttime)
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




int main()

{

    diaodu schedul;  //����

//    schedul.Fcfs();    //�����ȷ���

 //   printf("\n\n\n");

 //   Sleep(3*1000);   //���������1��

   // schedul.Sjf();     //����ҵ����

  //  Sleep(3*1000);  //����3��

  //  schedul.RR();      //ʱ��Ƭ��ת    

  //  Sleep(3*1000);  //����3��

   // schedul.Djfkdl();  //�༶��������

    Sleep(3*1000);  //����3��

    schedul.SRT();  //���ʣ��ʱ�������㷨

    //Sleep(10*1000);  //����10��

   // schedul.HRRN();  //����Ӧ�����ȵ����㷨

	Sleep(10*1000);  //����10��

    return 0;
}


//    Sleep(n*1000);   //���������n�뺯��