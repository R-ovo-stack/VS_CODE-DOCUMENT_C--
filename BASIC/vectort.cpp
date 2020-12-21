#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;  //声明一个int型动态数组
    vector<int>::iterator vecit;  //TODO  创建vector迭代器

    vec.push_back(1);  //TODO  末尾添加元素
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.pop_back();//TODO  末尾删除
    vec.size();//TODO  返回vec实际元素的数量
    vec.empty();  //TODO  判定是否为空
    vec.max_size();  //TODO  vec最大容量
    vec.resize(30);  //TODO  修改vec的大小为30,多出的位置全为0
    for (unsigned i = 0; i < vec.size(); i++)
    {  //可以用vec[i]访问单个元素
    //下标遍历
        cout << vec[i] << endl;
    }
    for (vecit = vec.begin(); vecit != vec.end();vecit++){
        //TODO  此处可以说明，迭代器实质上是一个指针
        //vec.begin(),end()都是指针
        cout << *vecit << endl;
    }
        system("pause");
    return 0;
}