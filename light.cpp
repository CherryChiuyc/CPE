//191204 light UVa10110
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int n;
    while(cin>>n){
        if(n==0)    break;
        long long int root =0;
        root = sqrt(n);
        if(root*root==n)    cout << "yes" <<endl;
        else    cout <<"no"<< endl;
    }
}
