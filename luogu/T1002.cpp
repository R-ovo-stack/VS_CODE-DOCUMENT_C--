#include <cstring>
#include <iostream>
using namespace std;

/*
    for (int i = 0; i < 21;i++){
        for (int j = 0; j < 21;j++){
            if(Pan[i][j]==1)
                {
                    cout << i << "  " << j << endl;
                }
        }
    }
    */
//给出马的坐标,计算不可到的点坐标集
void CantGo(int x, int y, int l, int h, int A[21][21])
{ //x,y为马坐标,l,h为 B 的坐标
    A[x][y] = 1;
    if (x - 2 >= 0 && y - 1 >= 0)
        A[x - 2][y - 1] = 1;

    if (x - 2 >= 0 && y + 1 <= h)
        A[x - 2][y + 1] = 1;

    if (x + 2 <= l && y - 1 >= 0)
        A[x + 2][y - 1] = 1;

    if (x + 2 <= l && y + 1 <= h)
        A[x + 2][y + 1] = 1;

    if (x - 1 >= 0 && y - 2 >= 0)
        A[x - 1][y - 2] = 1;

    if (x - 1 >= 0 && y + 2 <= h)
        A[x - 1][y + 2] = 1;

    if (x + 1 <= l && y - 2 >= 0)
        A[x + 1][y - 2] = 1;

    if (x + 1 <= l && y + 2 <= h)
        A[x + 1][y + 2] = 1;
}
void Solve(int xx, int yy, int n, int m, int Pan[21][21], int &res)
{
    if (Pan[xx][yy] == 1 || xx > n || yy > m)
        return;
    if (xx == n && yy == m)
        res++;
    Solve(xx + 1, yy, n, m, Pan, res);
    Solve(xx, yy + 1, n, m, Pan, res);
}
int main()
{
    int xx = 0, yy = 0;
    int n, m;
    cin >> n >> m; //B坐标
    int l, h;
    cin >> l >> h;
    if ((l == 0 && h == 0) || (l == n && m == h))
    {
        return 0;
    }
    int Pan[21][21];
    memset(Pan, 0, sizeof(Pan));
    int res = 0;             //记录结果
    CantGo(l, h, n, m, Pan); //确认哪些点不可及

    Solve(xx, yy, n, m, Pan, res);
    cout << "结果: " << res;
    system("pause");
    return 0;
}
