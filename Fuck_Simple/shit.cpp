
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
Problem:
First:不能同时输入同时输出
Second:malloc以后最终结果倒一倒三这两位总是乱码
Third:优化。


*/
//输入的第一行为一个正整数n （1<=n<=10）
int main()
{
    char a[100001]; //存储一个十六进制数
    int *b, *sum;
    //  char a[100];
    b = (int *)malloc(100000 * sizeof(int));
    sum = (int *)malloc(400000 * sizeof(int));
    // long long b[100000],sum[400] = {0};  //exist bug      【 sum 】有问题
    //*(a+i)
    // int b[100], sum[400] = {0};

    //  long long c[10][150000]; //d[10] = {0}, i, j, m, n, k, temp, p, q;  //exist bug【c】

    int **c;
    c = (int **)malloc(10 * sizeof(int *));

    for (int e = 0; e < 10; e++)
    {
        c[e] = (int *)malloc(100000 * sizeof(int));
    }

    int d[10] = {0}, i, j, m, n, k, temp, p, q;

    //int i, j, m, n, k, temp, p, q;
    //  int c[10][300];
    // int d[10];
    scanf("%d", &n);

    //先转为十进制
    for (k = 0; k < n; k++)
    {
        scanf("%s", a); //输入一个十六进制数

        for (m = 0; a[m]; m++) //每一位转换成10进制存储到b里面
        {
            if (a[m] >= 'A' && a[m] <= 'F')
            {
                b[m] = a[m] - 55;
            }

            else
            {
                b[m] = a[m] - 48;
            }
        }

        for (i = 0; i < m; i++)
        {
            //取一分四 (0,1号位用来转八时补0)
            for (p = 5 + 4 * i; p >= 4 * i + 2; p--)
            {
                sum[p] = b[i] % 2;

                b[i] = b[i] / 2;
            }
            //每4个相当于十六进制的一个位数
        }

        //二 进制的位数
        temp = 0;
        q = 0;
        //二转八，三换一
        if ((4 * m) % 3 == 2)
        { //补一个0
            for (j = 4 * m + 1; j >= 1; j--)
            {
                c[k][q] += sum[j] * pow(2, temp++);
                if (temp == 3)
                {
                    temp = 0;
                    q++;
                }
            }
        }

        else if ((4 * m) % 3 == 1)
        { //补两个0
            for (j = 4 * m + 1; j >= 0; j--)
            {
                c[k][q] += sum[j] * pow(2, temp++);
                //         cout << "shuaqide fengexian ------------" << endl;
                //     cout << "test: " << c[k][q] << "=== " << endl;
                if (temp == 3)
                {
                    temp = 0;
                    q++;
                }
            }
        }

        else if ((4 * m) % 3 == 0)
        { //不用补0
            for (j = 4 * m + 1; j >= 2; j--)
            {
                c[k][q] += sum[j] * pow(2, temp++);
                if (temp == 3)
                {
                    temp = 0;
                    q++;
                }
            }
        }

        //记录八进制位数
        d[k] = q;
        for (i = 0; i < n; i++)
        {
            for (j = q - 1; j >= 0; j--)
            {
                printf("%d", *(*(c + i) + j));
                printf("\n");
            }
            printf("\n");
        }
    }

    /*for (i = 0; i < n; i++)
    {
        for (j = d[i] - 1; j >= 0; j--)
        {
            printf("%d", *(*(c+i)+j)); printf("\n");
        }
        printf("\n");
    }*/
    //    free()
    system("pause");

    return 0;
}