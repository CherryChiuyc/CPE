//191120 power crisis UVa151
#include <iostream>
#include <queue>
using namespace std;

//有n個廠，從第一個開始斷電，跳m個廠斷電，希望最後一個斷電的廠是13廠
//求最小的m
int main(){
    int n;
    while(cin>>n && n){
        queue<int> q;
        //1一開始就被斷電
        for(int i=1;i<=n-1;i++)
            q.push(i);
        for(int m=1;m<100000;m++){
            while(q.size()!=1){
                for(int i=1;i<m;i++){
                    q.push(q.front());
                    q.pop();
                }
                q.pop();
            }

            if(q.front() == 12){
                cout << m << endl;
                break;
            }
            else{
                q.pop();
                for(int i=1;i<=n-1;i++)
                    q.push(i);
            }
        }
    }
}
