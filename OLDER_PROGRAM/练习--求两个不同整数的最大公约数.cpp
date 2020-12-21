#include<stdio.h>

int gy(int x,int y){   //自定义求最大公因数函数，返回值为x与y的最大公因数
    int t=0,ex=1;
    int i=0;
    if(x<y)     //使x为较大数，y 为较小数，此时并未对a,b进行排序,仅仅将形参进行一次临时排序
    {
        t=x;
        x=y;
        y=t;
    }

    for(i=y;i>0;i--)   //从a，b中较小数开始进行递减for循环
    {
		ex=i;
        if(y%i==0 && x%i==0)	break;   //当二者对i进行求余运算结果都为0时终止该循环
    }
	return ex;   //返回int类型的最大公因数
}

int main()
{
	int a, b;
	printf("输入两个不同的数：\n");
	scanf("%d%d",&a,&b);
	printf("\n");
	int maxgy=gy(a,b);  //定义maxgy为gy函数的返回值，即最大公因数
	printf("%d,%d的最大公约数为：%d\n",a,b,maxgy);	

	return 0;
}
   










//错误源码

/*
#include<stdio.h>

int main()
{
	int gy(int ,int );
int a, b;
printf("输入两个不同的数：\n");
scanf("%d%d",&a,&b);
printf("%d,%d的公约数为：%d\n",a,b,gy(a,b));
return 0;
}
   
   int gy(int x,int y)
{
 int t, r;
 if(x<y)
 {
 t=x;
 x=y;
 y=t;
 }

 if(r!=0)
{
r=x%y;
 x=y;
y=r;
return x;
}

}
*/