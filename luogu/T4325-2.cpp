#include <iostream>
#include <set>
using namespace std;
int main()
{
    //int nums[10];
    set<int> res;
    int test;
    for (int i = 0; i < 10; i++)
    {
        //cin >> nums[i];
        cin >> test;
        //res.insert(nums[i] % 42);
        res.insert(test % 42);
    }
    cout << res.size();
    system("pause");
    return 0;
}