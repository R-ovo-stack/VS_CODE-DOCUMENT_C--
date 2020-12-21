#include<iostream>
using namespace std;

int count;
int Tongji(int a,int b){
	while(a<=b)
	{
		for(int i=31;i>=0;i--){
			if((a>>i&1)==1){
				count++;
			}		
		}
		a++;		    
	}
	return count;
}

int main(){
	int L,R;
	cin>>L>>R;
	cout<<Tongji(L,R);
    system("pause");
    return 0;
}