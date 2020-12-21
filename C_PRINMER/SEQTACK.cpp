
/*
实现方式： 以数组存储方式存储栈内所有数据

*/
#include <stdio.h>
#include <stdlib.h>
// 声明顺序栈的容量
const int maxsize = 6;
struct seqtack
{
    int *data; //存储栈中元素的数组
    int top;   // 栈顶下标
};

typedef struct seqtack Seq;

// 初始化操作
Seq init(Seq s)
{
    printf("初始化函数运行\n");
    s.data = (int *)malloc(maxsize * sizeof(int)); //动态分配存储空间
    if (!s.data)
    {
        printf("初始化失败");
        exit(0);
    }
    s.top = 0;
    return s;
}

//判断栈空
int empty(Seq s)
{
    printf("判断栈空\n");
    if (s.top == 0)
    {
        return 1;
    }
    return 0;
}

//进栈操作
Seq push(Seq s, int x)
{
    printf("进栈操作\n");
    // 判断栈是否满了

    if (s.top == maxsize - 1)
    {
        printf("栈满");
        return s;
    }
    else
    {

        printf("正在插入数据%d\n", x);
        s.data[s.top] = x;
        s.top++;
        return s;
    }
}

//出栈操作
Seq pop(Seq s, int *e)
{
    if (empty(s))
    {
        printf("栈空\n");
        exit(0);
    }
    else
    {
        *e = s.data[s.top - 1];
        s.top--;
        return s;
    }
}

// 打印栈中元素
void display(Seq s)
{
    if (empty(s))
    {
        printf("栈空\n");
        exit(0);
    }
    else
    {
        printf("开始打印\n");
        int num = 0;
        while (num < s.top)
        {
            printf("现在的元素是:%d\n", s.data[num++]);
        }
    }
}
// 获取栈顶元素
int gettop(Seq s)
{
    if (empty(s))
    {
        printf("栈空\n");
        exit(0);
    }
    else
    {
        return s.data[s.top - 1];
    }
}
int main()
{
    printf("代码运行中\n");
    Seq s;
    s = init(s); //初始化

    //插入两个元素
    s = push(s, 1);
    s = push(s, 2);

    display(s);
    int e;
    s = pop(s, &e);
    printf("删除的元素是:%d\n", e);

    display(s);
    system("pause");
    return 0;
}
