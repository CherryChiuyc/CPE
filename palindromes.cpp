//191120 extend to palindromes UVa11475
#include <iostream>
#include <string.h>
#include <stdio.h> //為了gets`,gets 可以得到整個string
using namespace std;

char str[100005];
char strR[100005];
int pre[1000005];

//要用到KMP演算法
//failure function ，建立prefix table
//這裡的strR在字串比對裡面就是wanted的那個字串
void failure(char strR[],int pre[]){
    int i,j;
    pre[0] = -1;
    for(i=1,j=-1;strR[i];i++){
        //j一直往前跳，跳到不能再跳
        while(j>=0 && pre[i]!=pre[j+1]){
            j = pre[j];
        }
        if(pre[i]==pre[j+1])    j++;
        pre[i] = j;
    }
}

int KMP(char str[],char strR[]){
    int i,j;
    for(i=0,j=-1;str[i];i++){
        while(j>=0 && str[i]!=strR[j+1]){
            j = pre[j];
        }
        if(str[i]==strR[j+1])   j++;
    }
    return j; //最長的prefix由前數來第幾位
}

int main(){
    int len;
    while(gets(str)){
        len = strlen(str);
        //strR為顛倒字串
        for(int i=0;i<len;i++){
            strR[i] = str[len-1-i];
        }
        strR[len] ='\0';
        //build prefix table
        failure(strR,pre);
        int cut = KMP(str,strR);
        for(int i=0;i<len;i++)
            cout << str[i];
        for(int i=cut+1;i<len;i++)
            cout << strR[i];
        cout << endl;
    }
}
