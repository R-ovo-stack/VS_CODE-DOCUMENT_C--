#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/*
 1~n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。
 照从小到大的顺序输出所有方案，每行1个。
*/

// 1 2 3 4 5 6 7 8 9 10 ... n-1 n
//挑选m个数字

int kk = 1;
void Solve(int n, int m, int size, int nums[])
{   

    nums[kk++] = n;  //控制索引修改nums数组
    if (kk == m + 1) //
    {
        //当顺序扫描至数组末尾则遍历该数组
        for (int i = 1; i < m + 1; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
        //当 kk 扫描到 nums 末尾时，控制索引 kk至return 的层次下一层-> kk = 层次 + 1;

       // kk = 9; //TODO 如何回溯??
        return;
    }

    /*5挑3
                        0
                     1 2 3 4 5
                
        2 3 4 5     3 4 5     4 5     5     []
3 4 5   4 5     5    []     4 5     5   []      5   []     []      []
    
    
    
    
    
    
    
    
    
    
    */
    if (n == size)
    {
        //当遍历至n时，控制索引 kk至return 的层次下一层-> kk = 层次 + 1;
        //kk = 0000; //TODO 如何回溯??
        return;
    }
    for (int i = 1; (i + n) <= size; i++)
    {
        Solve(n + i, m, size, nums);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    //int count = Je(n) / (Je(n - m) * Je(m)); //情况总数
    int nums[m + 1];
    memset(nums, 0, sizeof(nums));
    //vector<int> v;
    Solve(0, m, n, nums);
    system("pause");
    return 0;
}
