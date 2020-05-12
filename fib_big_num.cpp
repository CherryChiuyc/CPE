//fab_big_num
#include <iostream>
using namespace std;
#define LEN 150
#define NUMLEN 100

struct FIbNum{
    int num[NUMLEN];
    int length;
};

int main(){
    struct FIbNum FN[LEN];
    FN[0].num[0]=1;
    FN[0].length=0;
    FN[1].num[0]=1;
    FN[1].length=0;

    for(int i=2;i<LEN;i++){
        for(int j=0;j<NUMLEN;j++){
            FN[i].num[j]+=FN[i-1].num[j]+FN[i-2].num[j];
            if(FN[i].num[j]>=10){
                FN[i].num[j]%=10;
                FN[i].num[j+1]+=1;
            }
            for(int j=NUMLEN-1;j>=0;j--){
                if(FN[i].num[j]!=0){
                    FN[i].length=j;
                    break;
                }
            }
        }
    }
    int n;
    cin >> n;
    for(int i=FN[n].length;i>=0;i--)  cout<< FN[n].num[i];
    cout << endl;
}
