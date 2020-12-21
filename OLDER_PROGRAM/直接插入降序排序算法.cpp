#include<iostream>
using namespace std;
/*直接插入降序排序算法*/
void str_sort(int a[],int n)
{
     int i,j,temp;
     for(i=0;i<n;i++)
     {
         temp=a[i];
         for(j=i-1;j>=0;j--)
         {
             if(a[j]<temp)
                a[j+1]=a[j];
            else
                break;
         }
         a[j+1]=temp;
     }
     
}
int main()
{
    int array[10]={1,3,5,7,9,2,4,8,6,10};
	cout<<"原数组:";
    for(int j=0;j<10;j++)
    cout<<"array["<<j<<"]="<<array[j]<<endl;
    str_sort(array,10);
	cout<<"排序后数组:";
    for(int i=0;i<10;i++)
    cout<<"array["<<i<<"]="<<array[i]<<endl;
}

/*
2 4 7 5 9 8
*/
