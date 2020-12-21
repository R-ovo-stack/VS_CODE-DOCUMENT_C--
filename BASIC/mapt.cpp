#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<string, int> m; //TODO  定义一个空映射map
    map<string, int>::iterator mit;
    //key,value
    cout << m.size() << endl; //TODO  返回map的实际元素大小
    m["test"] = 2;
    m["kk"] = 5;
    m["te"] = 9;
    m.erase("te");                               //TODO  删除指定key的元素，键值对同时删除
    cout << "isempty()???" << m.empty() << endl; //TODO  判断映射是否为空

    cout << m["kk"] << endl;
    //TODO  为什么???报错mit->first()
    for (mit = m.begin(); mit != m.end(); mit++)
    { //使用迭代器遍历map
        //cout << mit->first() << "  " << mit->second() << endl;
    }
    //TODO  判断指定key是否在map中
    //不在返回1，在返回0 <-> 此处不是true,false哦
    cout << (m.find("kk") == m.end() ? false : true) << endl;

    system("pause");
    return 0;
}