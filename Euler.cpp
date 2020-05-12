//uva 10299 尤拉公式 //uva 10179 參考，測資有一個過不了，可能是浮點數誤差
#include <iostream>
using namespace std;

int euler(int n){
    int ans=n;
    if(n==1)    return ans=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i * (i-1); //n(1-1/i) 質因數
            while(n%i==0)   n/=i; //除到不能再除
        }
    }
    if(n>1) ans=ans/n *(n-1); //i<4
    return ans;
}

int main(){
    int n;
    while(cin>>n&&n){
        cout << euler(n) << endl;
    }
}
