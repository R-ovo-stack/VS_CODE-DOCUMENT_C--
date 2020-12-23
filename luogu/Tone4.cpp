#include <iostream>
#include <vector>
using namespace std;

/*
 1~n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。
 照从小到大的顺序输出所有方案，每行1个。
*/

// 1 2 3 4 5 6 7 8 9 10 ... n-1 n
//挑选m个数字
int Je(int n)
{
    if (n == 1)
        return 1;
    return Je(n - 1) * n;
}
void Solve(int n, int m, int size, vector<int> v)
{
    //TODO 数组如何回到上一次的状态,在不复制数组的情况下
    //TODO
    v.push_back(n);
    Solve(n + 1, m, size, v);
    if (v.size() == m + 1) //
    {
        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    if (v.empty())
        return;
    v.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    int count = Je(n) / (Je(n - m) * Je(m)); //情况总数
    vector<int> v;
    Solve(0, m, n, v);
    system("pause");
    return 0;
}
