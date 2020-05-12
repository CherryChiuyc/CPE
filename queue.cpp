//queue
#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q; //一個空的queue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();
    cout << q.size() << endl;
}

//example 2
/*
int main(){
    queue<int> q;
    for(int i=0;i<5;i++)
        q.push(i*10);
    while(q.size()!=0){
        cout << q.front() <<endl;
        q.pop();
    }
}
*/
