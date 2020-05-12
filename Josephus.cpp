//Josephus Problem
#include <iostream>
#include <queue>
using namespace std;

//假設現在有n人，數到m就殺，不會被殺死的那個人在哪個位置
int main(){
    int n,m;
    cin >> n >> m;
    queue<int> q;
    for(int i=1;i<=n;i++)
        q.push(i);
    while(q.size()!=1){
        for(int i=1;i<m;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front() << endl;
}
