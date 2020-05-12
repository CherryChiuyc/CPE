//191218 sumsets UVa10125
#include <iostream>
#include <algorithm>
using namespace std;
/*這題有幾個需要注意的地方
1. ans可能為0，不能直接拿ans當if的判斷
2. a,b,c,d皆不能相等 用sort，且內部迴圈的起始條件要比前一參數還要大
3. 找最大值。所以d的迴圈由最大數值開始
*/
int main(){
    int n,ans;
    int k[1005];
    while(cin>>n){
        if(n==0)   break;
        for(int i=0;i<n;i++)
            cin>>k[i];
        bool found = false;
        sort(k,k+n);
        //d 從大的開始數，且一有found便可不用再繼續找
        for(int d = n-1;d>=0 && !found;d--){
            for(int a=0;a<n && !found;a++){
                //countinue = 跳過不做，繼續做這個迴圈裡該做的事
                if(a==d)    continue;
                for(int b=a+1;b<n && !found;b++){
                    //此時b>a，所以b!=a，但有可能=d
                    if(b==d)    continue;
                    for(int c=b+1;c<n && !found;c++){
                        if(c==d)    continue;
                        if(k[d]==k[a]+k[b]+k[c]){
                            found = true;
                            ans = k[d];
                        }
                    }
                }
            }
        }
        if(found) cout<<ans<<endl;
        else    cout << "no solution" << endl;
    }
}
