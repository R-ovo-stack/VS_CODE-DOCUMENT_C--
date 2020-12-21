//位元值为n的格雷码
#include<iostream>
using namespace std;
#define CHANGE_BIT(a) a=((a=='0')? '1':'0')  //定义宏实现改变位元值
#define NEXT_BIT(x) x=(1-(x))  //设定奇数项或偶数项
/**********构建n位元的格雷码*****************/
void findGrayCode(int n)
{
    if(n<=0)
    {
        cout<<"输入超出有效范围"<<endl;      //验证输入是否合法
        return ;
    }
    char* gray=new char[n];   //声明存储每个格雷码的数组
    for(int i=0;i<n;i++)    //初始化数组为0
    {
        gray[i]='0';
        cout<<'0';   // 打印起始格雷码0000....
    }
    cout<<endl;
    int odd=1;   //定义奇数标志.1为奇数项，2为偶数项
    int i=0;
    /*****************循环构造并输出格雷码****/
    while(1)
    {
        if(odd)  //如果为奇数项，更改最右边位元值为相反值
        {
            CHANGE_BIT(gray[0]);  //本程序为反向存储
        }
        else
        /**************/
        {
            for(i=0;i<n&&gray[i]=='0';i++);
            if(i==n-1)   //如果i为数的最左边，则退出循环，所有格雷码查找完成
            break;
            CHANGE_BIT(gray[i+1]);  //更改第一个1左边一位的值
        }
        for(i=n-1;i>=0;i--)  //输出该格雷码
        {
            cout<<gray[i];
        }
        cout<<endl;
        NEXT_BIT(odd);  //更改奇偶属性
    }
}
/**********测试主函数***********/
int main()
{
    int n;
    cout<<"输入位元数: "<<endl;
    cin>>n;
    cout<<n<<"位元的格雷码为: "<<endl;
    findGrayCode(n);
    system("pause");
    return 0;
}