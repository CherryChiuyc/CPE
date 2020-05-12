//191230 mid-night summer dream UVA10057
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
    int n,temp;
    int arr[100000];
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin >> temp;
            arr[i] =temp;
        }
        sort(arr,arr+n);

        int mid1 =arr[(n-1)/2];
        int mid2 = arr[n/2];

        int count = 0;
        for(int i=0;i<n;i++)
            if(arr[i]==mid1||arr[i]==mid2)  count +=1;

        cout << mid1 <<" "<< count << " " << (mid2-mid1)+1 << endl;
    }
}
