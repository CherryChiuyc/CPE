//try big number again
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define LEN 5
#define NUMLEN 3000

struct BIGNum{
    int num[NUMLEN];
    int length;
};

/*
void print(BIGNum bn){
    for(int i=bn.length;i>=0;i--)  cout<< bn.num[i];
    cout << endl;
}
*/

int main(){
    struct BIGNum BN[LEN];
    vector<int> final;
    for(int i=0;i<LEN;i++){
        BN[i].length=0;
        for(int j=0;j<NUMLEN;j++){
            BN[i].num[j] = 0;
        }
    }
    BN[0].num[0] = 0;
    BN[0].length = 0;
    BN[1].num[0] = 1;
    BN[1].length = 0;
    BN[2].num[0] = 2;
    BN[2].length = 0;
    BN[3].num[0] = 6;
    BN[3].length = 0;
    final.push_back(BN[0].num[0]);
    final.push_back(BN[1].num[0]);
    final.push_back(BN[2].num[0]);
    final.push_back(BN[3].num[0]);
    for(int i=4;i<1500;i++){
        int sum = 0;
        for(int j=0;j<NUMLEN;j++){
            BN[4].num[j] += BN[3].num[j] * i;
            if(BN[4].num[j]>=10){
                BN[4].num[j+1]+= BN[4].num[j]/10;
                BN[4].num[j]%=10;
            }
            //cout << BN[4].num[j] << endl;
        }
        for(int q=NUMLEN-1;q>=0;q--){
            if(BN[4].num[q]!=0){
                BN[4].length=q;
                //cout << "the length is:" << BN[4].length << endl;
                break;
            }
        }
        for(int k=0;k<=BN[4].length;k++)    sum+=BN[4].num[k];
        final.push_back(sum);
        BN[3]=BN[4];
        memset(BN[4].num, 0x00, sizeof(BN[4].num));
    }
    int n;
    while(cin>>n && n){
        cout << final[n] << endl;
    }
}
