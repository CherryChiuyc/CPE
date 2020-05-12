//2D mine sweeper --過四個測資
//Print a blank line between 2 consecutive data sets 換行就可以了，不需要空一行
#include <iostream>
using namespace std;
#define SIZE 10

int main(){
    int game,n;
    char mine[SIZE][SIZE];
    char press[SIZE][SIZE];
    int k[SIZE][SIZE];
    char c;
    cin>>game;
    //有幾筆data
    for(int g=0;g<game;g++){
        cin >> n;
        //輸入地雷預設位置
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> c;
                mine[i][j] = c;
            }
        }
        //輸入已按下的位置
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> c;
                press[i][j] = c;
            }
        }
        //建立各個位置的數字表
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                k[i][j] = 0;
                if(mine[i-1][j-1]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i-1][j]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i-1][j+1]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i][j-1]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i][j+1]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i+1][j-1]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i+1][j]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
                if(mine[i+1][j+1]=='*' && (i>=0) && (j>=0)&& (i<=n) && (j<=n)) k[i][j] +=1;
            }
        }
        bool over = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(press[i][j]=='x' && mine[i][j]=='*'){
                    over = true;
                    break;
                }
        }
        if(over){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << mine[i][j];
                }
                cout << endl;
            }
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(press[i][j]=='x')    cout << k[i][j];
                    else    cout << '.';
                }
                cout << endl;
            }
        }
    }
}
