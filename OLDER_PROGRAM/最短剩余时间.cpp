#include <vector>
#include <iostream>
using namespace std;
typedef struct process
{
    string name;
    int arrive_time;
    int handle_time;
    int used_time;//��¼������cpu�����˶��
}process;//���̽ṹ�� 
int main()
{
    vector<process> pro = 
    {
        {"P1", 0, 8, 0},
        {"P2", 3, 6, 0}, 
        {"P3", 5, 2, 0}, 
        {"P4", 6, 5, 0} 
    };

    int flag = 0;//��¼����ɽ��̵ĸ��� 
    int time = 0;//ģ���ʱ����ÿ��ѭ��+1 
    int cur_pro = -1;//��ǰ�����±꣬-1��ʾû������ִ�еĽ��� 
    bool ready[4] = {0};//ready[i]��ʾ��i�Ž��̵�״̬��0Ϊû�о�����1��֮�� 
    vector<string> cons;//�洢����˳���������� 
    while(flag != 4)
    {
        /* ����ǰ����״̬ */ 
        if(cur_pro != -1)
        {
            pro[cur_pro].used_time++;
            if(pro[cur_pro].used_time == pro[cur_pro].handle_time)
            {
                flag ++;
                cur_pro = -1;
            }
        }

        /* �ж��Ƿ��г���׼���� */
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

        /* ������ȳ���Ҫ�����ж� */
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

            /* ������һ�����ȵĽ��� */ 
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

            /* �洢����˳�� */
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
