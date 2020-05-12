//191204 mine sweeper UVa10279 --presentation error
#include <iostream>
using namespace std;
#define SIZE 10

int main(){
    int game;
    int n[SIZE];
    char mine[SIZE][SIZE][SIZE];
    char press[SIZE][SIZE][SIZE];
    int k[SIZE][SIZE][SIZE];
    bool over[SIZE];
    char c;
    cin>>game;
    //有幾筆data
    for(int g=0;g<game;g++){
        cin >> n[g];
        //輸入地雷預設位置
        for(int i=0;i<n[g];i++){
            for(int j=0;j<n[g];j++){
                cin >> c;
                mine[g][i][j] = c;
            }
        }
        //輸入已按下的位置
        for(int i=0;i<n[g];i++){
            for(int j=0;j<n[g];j++){
                cin >> c;
                press[g][i][j] = c;
            }
        }
        //建立各個位置的數字表
        for(int i=0;i<n[g];i++){
            for(int j=0;j<n[g];j++){
                k[g][i][j] = 0;
                if(mine[g][i-1][j-1]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i-1][j]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i-1][j+1]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i][j-1]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i][j+1]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i+1][j-1]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i+1][j]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
                if(mine[g][i+1][j+1]=='*' && (i>=0) && (j>=0)&& (i<=n[g]) && (j<=n[g])) k[g][i][j] +=1;
            }
        }
        over[g] = false;
        for(int i=0;i<n[g];i++){
            for(int j=0;j<n[g];j++)
                if(press[g][i][j]=='x' && mine[g][i][j]=='*'){
                    over[g] = true;
                    break;
                }
        }
    }
    for(int g=0;g<game;g++){
        if(over[g]){
            for(int i=0;i<n[g];i++){
                for(int j=0;j<n[g];j++){
                    cout << mine[g][i][j];
                }
                cout << endl;
            }
        }
        else{
            for(int i=0;i<n[g];i++){
                for(int j=0;j<n[g];j++){
                    if(press[g][i][j]=='x')    cout << k[g][i][j];
                    else    cout << '.';
                }
                cout << endl;
            }
        }
        if(g!=game)     cout << "\n";
    }
}
