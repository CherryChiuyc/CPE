//200318 UVa 11059 Maximum Product
#include <iostream>
using namespace std;

int main(){
    int s[20]={0};
    int n,m=1;
    while(cin >> n){
        long long int max=0;
        long long int temp;
        for(int i=0;i<n;i++)    cin >> s[i];
        for(int i=0;i<n;i++){
            temp = 1;
            for(int j=i;j<n;j++){
                temp *= s[j];
                if(temp>max)    max =temp;
            }
        }
        cout << "Case #" << m <<": The maximum product is " << max << "." << endl <<endl;
        m+=1;
    }
}
