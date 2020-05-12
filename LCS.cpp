//LCS UVa10405 Longest Common Sequence
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int f[1005][1005];
char a[1005];
char b[1005];

int main(){
    while(gets(a) && gets(b)){
        memset(f,0,sizeof(f));
        int l1 = strlen(a);
        int l2 = strlen(b);
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(a[i-1]==b[j-1])  f[i][j] = f[i-1][j-1]+1;
                else f[i][j] = max(f[i-1][j],f[i][j-1]);
            }
        }
        cout << f[l1][l2] << endl;
    }
}
