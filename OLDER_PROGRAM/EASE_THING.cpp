#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a = 0;
    cout << "PLEASE INPUT A NUMBER WHICH YOU THINK NOW : " << endl;
    cin >> a;
    while(a++<1000)
    {
        cout << a<<"\t";
    }
    system("pause");
    return 0;
}