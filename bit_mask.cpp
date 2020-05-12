//191230 bit mask UVa10718
//greedy
/*
儘量讓 N 中為 0 的位元，M 為 1；N 為 1 的位元， M 為 0。
因此從高位往低位檢查，
如果 N 為 1（M 儘量為 0），若 M 不能為 0，則必是因為 M 為 1 仍小於 L；
如果 N 為 0（M 儘量為 1），若 M 不能為 1，則必是因為 M 為 0 仍大於 U（此時不可能），
換句話說，M 為 1 時，M 需不大於 U。
*/
#include <stdio.h>
#include <iostream>
//1LL == long long int 1
#define BIT(i) (1LL<<i)
using namespace std;

int main(){
    long long L,U,N,M,i;
    while(cin>>N>>L>>U){
        M = 0;
        //要從高位判斷起，使N OR M最大
        for(int i = 31;i>=0;i--){
            //N的bit i =1，M的bit i =1
            if(BIT(i)&N){
                //如果都相同了還比L小，一定要保留M的1
                if(M+BIT(i)<=L)     M+=BIT(i);
            }
            //其他所有情況只要不超過U即可
            else{
                if(M+BIT(i)<=U)     M+=BIT(i);
            }
        }
        cout << M << endl;
    }
}
