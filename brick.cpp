//191230 Brick Wall Pattern UVa900
#include <iostream>
using namespace std;

int main(){
    int length;
    long long int table[55];
    table[0] = 1;
    table[1] = 1;
    for(int i=2;i<=50;i++)
        table[i] = table[i-1]+table[i-2];
    while(cin>>length && length){
        cout << table[length] << endl;
    }
}
