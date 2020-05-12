//200318 UVa 10179 - Irreducable Basic Fractions
#include <iostream>
#include <vector>
using namespace std;
#define LIMIT 50000
bool sieve[LIMIT]; //質數刪去法
vector<int> prime;//質數表

//false 是質數
void erase(){
    sieve[0]=sieve[1]=true;
    for(int i=2;i<LIMIT;i++){
        if(!sieve[i]){
            for(int k=(LIMIT-1)/i,j=i*k; k>=i; k--,j-=i){
                if(!sieve[k])   sieve[j] = true;
            }
        }
    }
    for(int i=2;i<LIMIT;i++){
        if(!sieve[i]){
            prime.push_back(i);
            //cout << i << endl;
        }
    }
}

int euler(int n){
    int ans=n;
    if(n==1)    return ans=0;
    for(int i=0;i<prime.size() && prime[i]<=n;i++){
        if(n%prime[i]==0){
            ans=ans/prime[i] * (prime[i]-1); //n(1-1/i) 質因數
            while(n%prime[i]==0)   n/=prime[i]; //除到不能再除
        }
    }
    if(n!=1) ans=ans/n *(n-1); //i<4
    return ans;
}

int main(){
    erase();
    int n;
    while(cin>>n&&n){
        cout << euler(n) << endl;
    }
}
