#include <vector>
#include <iostream>
using namespace std;
typedef struct process
{
    string name;
    int arrive_time;
    int handle_time;
    int used_time;//记录进程在cpu上跑了多久
}process;//进程结构体 
int main()
{
    vector<process> pro = 
    {
        {"P1", 0, 8, 0},
        {"P2", 3, 6, 0}, 
        {"P3", 5, 2, 0}, 
        {"P4", 6, 5, 0} 
    };

    int flag = 0;//记录已完成进程的个数 
    int time = 0;//模拟计时器，每次循环+1 
    int cur_pro = -1;//当前进程下标，-1表示没有正在执行的进程 
    bool ready[4] = {0};//ready[i]表示第i号进程的状态，0为没有就绪，1反之。 
    vector<string> cons;//存储调度顺序，最后输出。 
    while(flag != 4)
    {
        /* 处理当前进程状态 */ 
        if(cur_pro != -1)
        {
            pro[cur_pro].used_time++;
            if(pro[cur_pro].used_time == pro[cur_pro].handle_time)
            {
                flag ++;
                cur_pro = -1;
            }
        }

        /* 判断是否有程序准备好 */
        bool diaodu = false;
        for(int i = 0; i<pro.size(); i++)
        {
            if(pro[i].arrive_time == time)
            {
                ready[i] = true;
            }
            if(ready[i])
                diaodu = true;  
        }

        /* 如果调度程序要进行判断 */
        if(diaodu)
        {
            int min_left_time_p; 
            for(int i = 0; i<pro.size(); i++)
            {
                if(ready[i])
                {
                    min_left_time_p = i;
                    break;
                }
            }

            for(int i = min_left_time_p + 1; i<pro.size(); i++)
            {
                if(ready[i])
                {
                    if(
                       pro[i].handle_time - pro[i].used_time <
                       pro[min_left_time_p].handle_time - pro[min_left_time_p].used_time
                    )
                    {
                        min_left_time_p = i;    
                    }
                }
            }

            /* 决定下一个调度的进程 */ 
            if(cur_pro == -1)
            {
                cur_pro = min_left_time_p;
            }else{
                if(
                   pro[cur_pro].handle_time - pro[cur_pro].used_time >
                   pro[min_left_time_p].handle_time - pro[min_left_time_p].used_time
                )
                {
                    ready[cur_pro] = 1;
                    cur_pro = min_left_time_p;
                }
            }
            ready[cur_pro] = 0;

            /* 存储调度顺序 */
            if(cons.size())
            {
                if(cons[cons.size()-1] != pro[cur_pro].name)
                    cons.push_back(pro[cur_pro].name);
            }else{
                cons.push_back(pro[cur_pro].name);
            }
        }   
        ++time;
    }

    for(int i = 0; i<cons.size(); i++)
        cout << cons[i] << endl; 

    return 0;   
} 
