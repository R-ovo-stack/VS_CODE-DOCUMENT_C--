/*
约瑟夫问题
实现方式：普通一维数组
by:BIN
参考资料：C语言综合练习
DATE:2020/1/29
*/
#include<cstring>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int out = 0;   //出队人员总数计数器，当out=N，程序循环结束
int couter = 0;  //数数计数器,约瑟夫规则报数计数器
int idx = -1;    //代表姓名字符数组下标,当out=N时，重置idx=0
const int N = 5;  
//const int LEN = 5;
void joseph(string a[],int k)
{
    while(out<N)
    {
        idx++;
        if(idx==N)  //把数组索引指针看成循环指针来对待
            idx = 0;
        if(a[idx]=="\0")
            continue;
        else
            {
                couter++;  //数数计数器+1
                if(couter==k)
                {
                    out++;
                    cout << "第" << out << "个退出者" << a[idx] << endl;
                    a[idx]="\0";  //退出,用“\0”标记
                    couter = 0;
                }
            }
    }
}

int main()
{
    int k;  //出列数
    string a[N];  //字符型人名数组
    cout << "\t"
         << "请一次输入5个人名<每个人名不超过10个字符>:" << endl;
    for (int i = 0; i < N;i++)
        cin >> a[i];
    cout << "\n"
         << "请输入数到第几个人退出: " << endl;
    cin >> k;
    joseph(a, k);   //调用约瑟夫算法函数实现输出出列序列
    system("pause");
}
