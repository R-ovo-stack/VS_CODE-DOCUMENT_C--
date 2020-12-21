#include<iostream>
#include<cstring>
using namespace std;

//TODO P2956--Oper函数待解决
void Oper(int x,int y,int s,int t,int N[245][245],int& res){
    for (int i = x; i <= s;i++){
        for (int j = y; j <= t;j++){ //TODO 此处一定要仔细,误写y++的话不会报错,并且会死循环
            if(!N[i][j]){
                res++;
                N[i][j] = 1;
            }
        }
    }
}

int tian[245][245];
int res=0;

int main(){
    //二维数组
    int width, height, n;
    cin >> height >>  width>> n;
    memset(tian, 0, sizeof(tian));
    int x, y, s, t; //记录每次输入的两个坐标,一直覆盖
    for (int i = 0; i < n;i++){
        cin >> x >> y >> s >> t;
        Oper(x, y, s, t, tian, res);
    }
    cout << res;
    return 0;
}