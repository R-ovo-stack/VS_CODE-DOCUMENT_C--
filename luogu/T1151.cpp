#include <iostream>
//__gcd(a,b)求最大公约数
using namespace std;
int main()
{
    int k = 0;
    cin >> k;
    bool flag = false;
    int a, b, c;
    for (int i = 10000; i <= 30000; i++)
    {
        a = i / 100;
        b = (i / 10) % 1000;
        c = i % 1000;
        if (a % k == 0 && b % k == 0 && c % k == 0)
        {
            flag = true;
            cout << i << " ";
        }
    }
    if (!flag)
        cout << "NO";
    system("pause");
    return 0;
}