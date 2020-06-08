//LeetCode Minimum Path Sum
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 1000

int input[MAX][MAX];
int dp[MAX][MAX];

int main(){
    int n,rows,cols;
    cin >> n;
    for(int k=0;k<n;k++){
        cin >> rows >> cols;
        //每次都要初始化
        for(int i=0;i<=rows+1;i++){
            for(int j=0;j<=cols+1;j++){
                input[i][j]=MAX;
                dp[i][j]=MAX;
            }
        }
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                cin >> input[i][j];
            }
        }
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(i==1 && j==1)    dp[1][1]=input[1][1];
                else dp[i][j] = (input[i][j]+ min(dp[i-1][j],dp[i][j-1]));
            }
        }
        cout << dp[rows][cols] << endl;
    }
}
