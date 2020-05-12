//大數 練習
#include <iostream>
using namespace std;

int main(){
    int na[25];
    int nb[25];
    int sum[25];
    int i;
    string a,b;
    cin >> a >> b;

    //把其他格子都補0，以防出事
    for(i=0;i<25;i++)   na[i]=nb[i]=sum[i] = 0;
    //int na[25]={0}
    //數字反著存，反著運算，運算結束再reverse(ASCII 0 ==48 )
    for(i=0;i<a.length();i++)   na[i]=a[a.length()-1-i]-48;
    for(i=0;i<b.length();i++)   nb[i]=b[b.length()-1-i]-48;
    //要處理進位問題
    int carry=0;
    for(i=0;i<25;i++){
        sum[i]=na[i]+nb[i]+carry;
        if(sum[i]>=10){
            sum[i]=sum[i]-10;
            carry=1;
        }
        else carry=0;
    }
    //找第一位在哪
    int start;
    for(i=24;i>=0;i--){
        if(sum[i]!=0){
            start=i;
            break;
        }
    }
    for(i=start;i>=0;i--)   cout << sum[i];
}
