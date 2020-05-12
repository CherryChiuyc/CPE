//200318 climbing stairs(數字較小時使用)
#include <iostream>
using namespace std;

long long int climbStairs(int n){
    if(n==1)    return 1;
    long long int first = 1;
    long long int second = 2;
    for(int i=3;i<=n;i++){
        long long int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main(){
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
}

//time complexity: O(n)
//space complexity:O(1) constant space
