#include <iostream>
#include <set>
using namespace std;

int main()
{

    set<int> s;  //TODO  创建一个空集合
    set<int>::iterator sit;  //TODO  定义集合set的迭代器
    s.insert(2);
    s.insert(3);
    s.insert(5);  //TODO  集合中添加元素,set是无序的，所以不可以使用下标遍历
    cout << s.empty() << endl;  //TODO  判断是否为空
    cout << s.max_size() << endl;   //TODO  返回集合的最大容量
    cout << s.size() << endl;  //TODO  返回集合的实际元素
    s.erase(2);  //TODO  删除指定内容元素
    s.erase(4);
    //s.begin()不可以打印,可以理解成一个虚指针
    //cout << s.begin() << endl;
    for (sit = s.begin(); sit != s.end(); sit++)
    {
        //迭代器方式遍历集合
        cout << *sit << "\t";
    }
    
    //TODO 如何判断集合是否包含某个元素??
    if(s.find(4)==s.end())
        cout << "4"
             << "不在集合set中" << endl;

    system("pause");
    return 0;
}