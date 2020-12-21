#include<iostream>
#include"assert.h"
#include"DATA_STRUCTED.h"
int main()
{
    /*
    std::cout << "LIST TESTING .... " << std::endl;
    CIR_LINKLIST<int> l;
    l.Push_back(1);
    l.Push_back(2);
    l.Push_back(3);
    l.Push_back(4);
    l.Push_back(5);
    std::cout << l << std::endl;
    l.Pop_back();
    std::cout << l << std::endl;
    l.Pop_back();
    std::cout << l << std::endl;
    system("pause");
    return 0;
    // 测试完毕，Push_back and  Pop_back 测试通过
    */
    DBLINKLIST<int> l;
    for (int i = 1; i <= 10;i++)
    {
        l.Insert(i * 10, i);
    }
    l.Set(231, 3);
    l.Remove2(70);
    for (int  i= 1; i < 10;i++)
    {
        std::cout << l.Get(i) << "  ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}