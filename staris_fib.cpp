//200318 climbing stairs 大數 leetcode 70
#include <iostream>
using namespace std;
#define LEN 150
#define DIGIT 100 //100的數字大約在100位數以內

struct FIBNUM{
    int num[DIGIT];
    int length;//紀錄
};

int main(){
    struct FIBNUM FN[LEN];
    FN[0].num[0]=1;
    FN[0].length=0;//只有[0]一個位數
    FN[1].num[0]=1;
    FN[0].length=0;
    for(int i=2;i<LEN;i++){
        for(int j=0;j<DIGIT;j++){
            FN[i].num[j]+=FN[i-1].num[j]+FN[i-2].num[j];
            if(FN[i].num[j]>=10){
                FN[i].num[j]-=10;
                FN[i].num[j+1]+=1; //進位
            }
            for(int j=DIGIT-1;j>=0;j--){
                if(FN[i].num[j]!=0){
                    FN[i].length=j;
                    break;
                }
            }
        }
    }
    int n;
    cin >> n;
    for(int i=FN[n].length;i>=0;i--)    cout << FN[n].num[i];
    cout << endl;
}
