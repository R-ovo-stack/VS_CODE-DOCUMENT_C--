#include<iostream>
using namespace std;
//TODO 最长连号长度
//注解: 本题是洛谷 P1420,误写了文件名
int main(){
    int n;
    cin >> n;
    int a[n];  //存放整数
    int res=1;  //最终结果
    int sum=1;  //临时最大连号数值
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int j = 0; j < n;j++){
        if((a[j+1]-a[j])==1){
            sum++;
        }
        else{
            sum = 1;
        }
        res = max(res, sum);
    }
    cout << res;
    system("pause");
    return 0;
}