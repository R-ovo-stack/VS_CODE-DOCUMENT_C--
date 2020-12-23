#include <cstring>
#include <iostream>
#include <set>
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
int main()
{
    int n, m;
    cin >> n >> m;
    int count = Je(n) / (Je(n - m) * Je(m)); //情况总数
    set<vector<int>> s;                      //存储不重复的vector
    int flag[n];
    memset(flag, 0, sizeof(flag));
    int kk = 0;
    int h1, h2;
    while (s.size() != count)
    { //在n中挑m个加入vector,将所有vector加入s
        vector<int> v;
        h1 = s.size();
        for (int i = 1; i <= n; i++)
        {

            if (!flag[i])
            {
                v.push_back(i);
                flag[i] = 1;
                kk++;
            }
            if (kk == m)
            {
                kk = 0;
                break;
            }
        }
        s.insert(v);
        h2 = s.size();
        if (h2 > h1)
        {
            for (int i = 0; i < m; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        memset(flag, 0, sizeof(flag)); //重新置零
    }
    system("pause");
    return 0;
}
