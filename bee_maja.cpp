//191218 Bee Maja UVa10182
#include <iostream>
using namespace std;

#define SIZE 100000

//直接從0開始建表，多觀察一些規律
/*容易混淆的部分
第一圈的時候
下       左上      上      右上      右下     下?
(x,y+1) (x-1,y+1) (x-1,y) (x,y-1) (x+1,y-1) (x+1,y)
第二圈的稱呼就變了，但是對應到的操作沒有改變，注意左下在第一圈的時候沒有執行
下       左下     左上     上       右上     右下
(x,y+1) (x-1,y+1) (x-1,y) (x,y-1) (x+1,y-1) (x+1,y)
*/
//a = --i; a=i-1  a = i--; a = i; i= i-1

struct point{
    int x, y;
};
struct point p[SIZE+1];
int index;

//建表
void creat(){
    p[1].x = 0, p[1].y = 0;
    index = 2;
    int nowI = 0,nowJ = 0, count,num;
    //num 蜂窩由內而外的第幾圈
    for(num = 1; index <=SIZE;num++){
        for(count = 0; count < num && index <= SIZE; count++,index++)
            p[index].x = nowI, p[index].y = ++ nowJ;
        for(count = 0; count < (num-1) && index <= SIZE; count++,index++)
            p[index].x = -- nowI, p[index].y = ++nowJ; //第一圈沒有往左下的，且每圈執行次數都比別人少一
        for(count = 0; count < num && index <= SIZE; count++,index++)
            p[index].x = -- nowI, p[index].y = nowJ;
        for(count = 0; count < num && index <= SIZE; count++,index++)
            p[index].x = nowI, p[index].y = --nowJ;
        for(count = 0; count < num && index <= SIZE; count++,index++)
            p[index].x = ++nowI, p[index].y = --nowJ;
        for(count = 0; count < num && index <= SIZE; count++,index++)
            p[index].x = ++nowI, p[index].y = nowJ;
    }
}

int main(){
    creat();
    int n;
    while(cin>> n){
        if(n==0)    break;
        cout << p[n].x << " " << p[n].y << endl;
    }
}
