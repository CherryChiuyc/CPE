//200506 UVa10162 Last Digit
//數論，二項式定理
#include <iostream>
using namespace std;

int main(){
    //array init 沒有給值的都會是最後一個值
    int table[105]={0,1,5,2,8,3,9,2,8,7,7,
                      8,4,7,3,8,4,1,5,4,4,0};
    for(int i=21;i<100;i++)     table[i] = (table[i-20]+4)%10;
    //for(int i=0;i<100;i++)  cout << table[i] << " " ;
    string input;
    while(cin >> input && input != "0"){
        int l = input.length();
        int target;
        if(l==1 && (input[0]-48)<=10)  target = (input[l-1]-48);
        else target = (input[l-1]-48) + (input[l-2]-48)*10;
        cout << table[target] << endl;
    }
}
