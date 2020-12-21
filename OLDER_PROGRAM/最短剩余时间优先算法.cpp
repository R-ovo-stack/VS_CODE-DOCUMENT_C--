#include<iostream>
#include<vector>
#include<time.h>
#include<windows.h>
using namespace std;
//  const int key=0;  //设置每过两个时间单元，增加一个新进程
int pro_id=0;  //设置进程PID
int xttime=0;   //记录系统时间
struct s_pro
{
	int PID;  //进程PID
	int arrivetime;   //到达时间
	int cputime;   //已执行时间
	int resttime;   //剩余时间
//	int zt;  //状态【是否结束】
};   //s_ro 结构体类型

class moni
{
public:
	moni()
	{
		cout<<"moni constructed !"<<endl;
	}
	void create_s_pro();
	void SRT();
private:
	vector<s_pro>V_S;  //创建私有容器
	vector<s_pro>temp;
};
void moni::create_s_pro()  //创建具有抢占机制的进程
{
		s_pro item;
		item.PID=pro_id++;
		item.arrivetime=xttime+rand()%5+1;  //进程随机到达
		item.cputime=rand()%10+1;
//		item.zt=1;  //活跃状态
		item.resttime=item.cputime;
		V_S.push_back(item);
}
void moni::SRT()
{
	s_pro S;
	int rd;
	cout<<"欢迎进入最短剩余时间调度算法演示系统 ！ "<<endl;	
	//初始化5个进程
	for(int i=0;i<5;i++)
	{
		create_s_pro();
	}
	cout<<"对初始化的进程进行进程信息遍历....."<<endl<<endl;
	for(int j=0;j<V_S.size();j++)
	{
		cout<<"pid为: "<<V_S[j].PID<<endl;
		cout<<"到达时间为: "<<V_S[j].arrivetime<<endl;
		cout<<"预计执行时间: "<<V_S[j].cputime<<endl<<endl;	
	}
	while(!V_S.empty())
	{
		cout<<"time: "<<xttime<<"\t";
	//	s_pro *p;  //指向resttime=0的进程,并擦除该进程		
		int pid;  //正在进行的 进程pid
		int index=0;  //数组下标记录
		int m;		
		for(int j=0;j<V_S.size();j++)  //就绪队列加入[刷新]进程
		{
			if(V_S[j].arrivetime<=xttime )
			{
				S=V_S[j];
				temp.push_back(S);
			}
		}
	if(!temp.empty())
	{
		int mintime=10;  //  最短剩余时间转换中间值

		for( i=0;i<temp.size();i++)    //  从就绪队列找出下次运行进程的PID，并在原队列中进行调度
		{
			//找出该已到达进程队列中剩余时间最短的进程
			if(temp[i].resttime<=mintime)
			{
				mintime=temp[i].resttime;
				m=i;
			}
		}
		pid=temp[m].PID;
		cout<<"正在运行PID为 "<<pid<<" 的进程..."<<endl;
		Sleep(1*1000);
		/*对原进程队列进行进程调度模拟*/
		for(i=0;i<V_S.size();i++)
		{
			if(V_S[i].PID==pid)
			{	index=i;	}
		}
		V_S[index].resttime--;  //选中的进程剩余时间-1
		cout<<"当前进程的剩余执行时间为: "<<V_S[index].resttime<<endl;
		xttime++;  //系统时间加一
		if(V_S[index].resttime==0)
		{	
			cout<<"PID为"<<V_S[index].PID<<"的进程已运行完毕！ "<<endl;
			cout<<"======================正在从就绪队列中删除..."<<endl;
			V_S.erase(V_S.begin() + index); 
		}
		rd=rand()%10+1;
		if(rd>9)
        {
			 create_s_pro();        
			 cout<<"新加入的进程的pid为: "<<V_S.back().PID<<endl;
			 cout<<"新加入的进程的到达时间: "<<V_S.back().arrivetime<<endl;
			 cout<<"新加入的进程的预计执行时间为: "<<V_S.back().cputime<<endl;			 
			 cout<<endl;
        }
		cout<<"--------------------"<<endl;
	}	
	else
	{
		cout<<"当前时间无进程正在运行..."<<endl<<endl;
		xttime++;
		Sleep(2*1000);
	}
	temp.clear();
	}
}
void main()
{
	moni D;
	D.SRT();
}
