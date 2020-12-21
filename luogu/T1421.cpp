//班主任给小玉一个任务，到文具店里买尽量多的签字笔。已知一只签字笔的价格是 1 元 9 角，
//而班主任给小玉的钱是 a 元 b 角，小玉想知道，她最多能买多少只签字笔呢。
#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    cout << (10 * a + b) / 19;
    system("pause");
    return 0;
}