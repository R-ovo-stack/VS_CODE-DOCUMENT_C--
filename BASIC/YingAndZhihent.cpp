/**
 * TODO 指针存储的是一块内存的地址，通过地址，可以访问这块内存；
 * 引用则是一个变量的别名，在创建时必须初始化。
 * 引用在初始化后不能改变，指针可以修改指向的对象
 * 
 * int *p=&a; //初始化指针p,指向a的地址
 * int &r=a;  //给a取一个别名，r就是a  ||  此处的引用与JAVA中的引用不可一概而论
 */
//TODO 引用与指针的区别
#include<iostream>
using namespace std;
void swap1(int *a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int &a,int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//假swap  值传递
void swap3(int a,int b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main(){

    int a = 0, b = 1;
    int *p = &a, *q = &b;
    swap1(p, q);
    cout << "指针测试:" << a << "  " << b << endl;

    int c = 2, d = 3;
    swap2(c, d);
    cout << "引用测试: " << c << "  " << d << endl;

    int e = 6, f = 8;
    swap(e, f);
    cout << "系统swap函数测试: " << e << "  " << f << endl;
    //上述三个函数都改变了a,b的值

    int y = 9, w = 10;
    swap3(y, w);
    cout << "假swap测试:　" << y << "  " << w << endl;

    system("pause");
    return 0;
}