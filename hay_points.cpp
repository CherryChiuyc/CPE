//191218 Hay points UVa10295
#include <iostream>
#include <string>
#include <map> //一種DS
using namespace std;

int main(){
    int m,n;
    map <string,int> dic;
    while(cin>>m>>n){
        for(int i =0; i <m;i++){
            char word[20];
            int value;
            cin >> word >> value;
            dic[string(word)] = value;
        }
        for(int i =0;i<n;i++){
            string letter;
            int salary = 0;
            //while一訂要加{}
            while(cin>>letter && letter != "."){
                salary += dic[letter];
            }
            cout << salary << endl;
        }
    }
}
