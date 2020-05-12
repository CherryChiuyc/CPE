//prime 篩法 最簡陋那種
#include <iostream>
using namespace std;

bool prime[20000000];

//篩法
void eratosthenes(){
    for(int i=0;i<20000000;i++)
        prime[i] = true //初始化
    prime[0] = false;
    prime[1] = false; //0和1不是質數

    //找下一個未被刪除的數
    for(int i=2;i<20000000;i++){
        if(prime[i]){
            //刪掉質數i的倍數，從兩倍開始。保留原本質數
            for(int j=i+i;j<20000000;j+=i)
                prime[j]=false;
        }
    }
}
