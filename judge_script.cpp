//Uva1018 Automated Judge Script
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
using namespace std;

string s[105];
string t[105];
stack<int> s_num;
stack<int> t_num;

int main(){
    int n,m;
    int count = 0;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","o",stdout);
    while(cin>>n && n){
        count +=1;
        for(int i=0;i<=n;i++){
            getline(cin,s[i]);
        }
        cin >> m;
        for(int i=0;i<=m;i++){
            getline(cin,t[i]);
        }

        for(int i=1;i<=n;i++){
            for(unsigned int j=0;j<s[i].length();j++){
                int a = s[i][j] - 48;
                if(a>=0 && a<=9)    s_num.push(a);
            }
        }
        for(int i=1;i<=m;i++){
            for(unsigned int j=0;j<t[i].length();j++){
                int a = t[i][j] - 48;
                if(a>=0 && a<=9)    t_num.push(a);
            }
        }

        int flag = 1; //AC
        if(s_num.empty() && t_num.empty())  flag =1;
        /*
        else if(s_num.empty() && !t_num.empty())    flag =2;
        else if(!s_num.empty() && t_num.empty())    flag =3;
        */
        while(!s_num.empty() && !t_num.empty()){
            if(s_num.top()!=t_num.top())    flag = 2; //wrong
            s_num.pop();
            t_num.pop();
        }

        if(flag==1){
            for(int i=1;i<=n;i++){
                for(unsigned int j=0;j<s[i].length();j++){
                    if(s[i][j]!=t[i][j])    flag = 3; //presentation error
                }
            }
        }

        if(flag==1)     cout << "Run #" << count << ": Accepted" << endl;
        else if(flag==2)    cout << "Run #" << count << ": Wrong Answer" << endl;
        else if(flag==3)    cout << "Run #" << count << ": Presentation Error" << endl;
    }
}
