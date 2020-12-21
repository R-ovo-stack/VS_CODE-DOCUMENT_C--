#include<queue>
#include<iostream>
using namespace std;

int main(){

    queue<int> q;
    //TODO  注意，队列和栈是不可以使用迭代器的,原因在于他们的特殊机制
    cout << q.size() << endl; //返回队列实际元素大小
    q.push(3);
    q.push(5);  
    q.push(8);  //TODO  队尾入队
    cout << q.back() << endl;  //TODO  访问队尾
    cout << q.front() << endl;  //TODO  访问对头
    q.pop(); //TODO  移除队首元素
    
    system("pause");
    return 0;
}