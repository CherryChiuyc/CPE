//linear sieve
//一邊判斷質數，一邊建立表格
#include <iostream>
using namespace std;

const int N = 20000000;
bool sieve[N]; //預設都是false。最後留下來的質因數也是false

void linear_sieve(){
    vector<int> prime;
    for(int i=2;i<N;i++){
        //是質因數
        if(!seve[i])    prime.push_back(i);
        for(int j=0;i*prime[j]<N;j++){
            seive[i*prime[j]]=true; //刪去質數倍的
            if(i%prime[j]==0)   break;//被質數整除
        }
    }
}
