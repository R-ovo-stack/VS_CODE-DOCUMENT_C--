#include<iostream>
using namespace std;
int main(){
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    //转分钟
    int min = (c - a - 1) * 60 + d + 60 - b;
    cout << min / 60 << " " << min % 60;

    system("pause");
    return 0;
}