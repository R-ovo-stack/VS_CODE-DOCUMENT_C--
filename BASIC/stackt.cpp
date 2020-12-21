#include<stack>
#include<iostream>
using namespace std;
int main(){
    stack<int> s1;  //TODO  声明一个空栈
    s1.size();  //TODO  栈大小
    s1.push(1);
    s1.push(3);
    s1.push(5);   //TODO  入栈
    cout << s1.top();   //TODO  访问栈顶
    s1.pop();  //TODO  栈出--移除栈顶
    cout << s1.size();
    system("pause");
    return 0;
}