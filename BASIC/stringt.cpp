#include<string>
#include<iostream>

using namespace std;

int main(){

    char a, b;
    cin >> a >> b;
    //cin,cout效率要低于scanf("%c",&a,&b);cout<<a<<b;
    //TODO 以下两句scanf只会执行一句
    scanf("%c %c",&a,&b);
    scanf("%c%c",&a,&b);
    //上述两者的输入中,scanf("%c %c",&a,&b);中的空格会被读取并打印在控制台

    cout << a << b;

    string s1, s2;
    s1 = "hello";
    s2 = "word!";
    string s3 = s1 + s2;  //TODO string拼接
    cout << s1 << s2 << s3 << endl;
    //TODO　string 截取
    string s4 = s3.substr(0, 6); //从0开始往后数6个字符
    cout << s4 << endl;
    string s5 = s4.substr(3);  //从3开始以后所有字符
    cout << s5 << endl;
    //TODO string 的比较操作符 ==  !=  <  >  <=  >=
    //TODO string 的长度,length()和size()没有区别
    cout << s3.length() << endl;
    cout << s3.size() << endl;
    
    system("pause");
    return 0;
}