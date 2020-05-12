//ch1
//add number in  an array
void summation(){
  int arr[5] ={3, 6, 9, -8, 1};

  int sum = 0;
  for(int i = 0; i < 5; i++){
    sum += arr[i];
  }
}

//copy a string
void copuy(){
  char s[15] = "incremental", t[15] = "";
  int i;
  for(i = 0; s[i]!= '\0'; i ++){
    t[i] = s[i];
  }
  t[i] = '\0';
}

//slection sort : choose min to put it first
void selection_sort(){
  int arr[5] = {3, 6, 9, -8, 1};
  for(int i =0; i<5;i++){
    int min_index =i;
    for(int j = i+1; j<5;j++)
      if(arr[j]<arr[min_index])
        min_index = j;
    swap(arr[i],arr[min_index]);
  }
}

//A traingle
void print_line(int n){
  for(int i =1; i <=n; i++){
    cout << 'A';
  }
  cout <<'\n';
}
void print_triangle(int n){
  for(int i = n; i >=1; i --){
    print_line(i);
  }
}
void print_solution(){
  print_triangle(5)
}

//A diamond
void print_line(int n,int max){
  int space = (max-n)/2;
  for(int i =1; i <= space;i++)
    cout << ' ';
  for(int i =1;i <=n;i++)
    cout <<'A';
  cout <<'\n';
}
void print_triangle(int n){
  for(int i = 1; i <=n; i +=2) print_line(i,n);
  for(int i = n-2; i >=1; i -=2) print_line(i,n);
}
//lower case
void print_lowercase(){
  char s[15]="Hello World!";

  for(int i =0; s[i]; i ++){
    if(s[i]>='A' && s[i]<='Z')
      cout << char(s[i] - 'A' + 'a');
    else
      cout <<s[i];
  }
}

//ch2
//preprocessing and memoization - sum_of_cubes
int memo[10+1];

int sum_of_cubes(int n){
  if(memo[n]!= 0) return memo[n];

  int v =0;
  for(int i = 0; i <=n ;i++){
    v += i* i *i;
  }
  return memo[n] =v;
}

int main(){
  for(int i = 0; i <=10; i ++)
    memo[1] = 0;

  int n;
  while(cin>>n){
    cout << sum_of_cubes(n) << '\n';
  }
  return 0;
}

//prime lookup table
//first method 把是質數的存起來
void prime_table(){
  int prime1[30];
  int size = 0;

  for(int i =2; i <100;i++){
    bool is_i_prime = true;
    for(int j =2;j<i;j++){
      if(i%j==0){
        is_i_prime = false;
        break;
      }
    }
  }
  if(is_i_prime)
    prime1[size++] = i;
}
//second method 把所有數都貼上TF標籤，看它是否為質數
void prime_table(){
  bool prime2[100];

  for(int i =2;i<100;i++){
    prime2[i] = true;
    for(int j =2;j<i;j++){
      if(i%j==0){
        prime2[i] = false;
        break;
      }
    }
  }
}

//count letter
void count_letter(){
  char s[15] = "Hello World!";
  int c[26] = {0};

  for(int i =0; s[i]; i++){
    if(s[i]>='A' && s[i]<='Z')
      s[i] = s[i]-'A'+'a';
  }

  for(int i =0; s[i];i++){
    if(s[i]>='a' && s[i]<='z')
      c[s[i]-'a']++;
  }
}

//正整數集合的聯集、交集、差集 method1
void int_relation{
  int mul3[50]={0};
  int mul5[50]={0};
  int union1[100]={0};
  int insertion[50]={0};
  int difference[50]={0};
  int size_3 = 0,size_5 = 0,size = 0,size1=0,size2=0;
  for(int i =1; i<100;i++){
    if(i%3==0)
      mul3[size_3++] = i;
    if(i%5==0)
      mul5[size_5++] = i;
  }
  for(int i=1;i<100;i++){
    if(i%3==0 || i%5 ==0)
      union1[size1++] = i;
    if(i%15!=0){
      if(i%3==0||i%5==0)
        difference[size2++] = i;
    }
    else
       insertion[size++] = i;
  }
}
int main(){
  for(int i =0; mul3[i];i++)
    cout << mul3[i]<<' ';
  cout <<'\n';
  for(int i =0;mul5[i];i++)
    cout << mul5[i] <<' ';
  cout <<'\n';
  for(int i =0;union1[i];i++)
    cout << union1[i]<<' ';
  cout <<'\n';
  for(int i =0;insertion[i];i++)
    cout << insertion[i]<<' ' ;
  cout <<'\n';
  for(int i =0;difference[i];i++)
    cout << difference[i]<<' ';
  cout <<'\n';
}
//正整數集合的聯集、交集、差集 method1
void int relation(){
  bool mul3[100]={0};
  bool mul5[100]={0};
  bool union1[100]={0};
  bool insertion[100]={0};
  bool difference[100]={0};
  for(int i =1;i <100;i++){
    if(i%3==0)
      mul3[i] = true;
    if(i%5==0)
      mul5[i] = true;
    if(i%3==0||i%5==0){
      union1[i] = true;
      if(i%15!=0)
        difference[i]= true;
      else
        insertion[i] = true;
    }
  }
}
int main(){
  for(int i =1;i <100;i++){
    if(mul3[i])
        cout << i <<' ';
  }
   cout <<'\n';
   for(int i =1;i <100;i++){
    if(mul5[i])
        cout << i <<' ';
  }
   cout <<'\n';
   for(int i =1;i <100;i++){
    if(union1[i])
        cout << i <<' ';
  }
   cout <<'\n';
   for(int i =1;i <100;i++){
    if(insertion[i])
        cout << i <<' ';
  }
   cout <<'\n';
   for(int i =1;i <100;i++){
    if(difference[i])
        cout << i <<' ';
  }
   cout <<'\n';
}

//count letter one-pass
void count_letter(){
  char s[15] = "Hello World!";
  int c[26] = {0};

  for(int i =0; s[i]; i++){
    if(s[i]>='A' && s[i]<='Z')
      s[i] = s[i]-'A'+'a';
    if(s[i]>='a' && s[i]<='z')
        c[s[i]-'a']++;
  }
}

//Ch3
//square method 1
void generate_squares(){
  for(int i =1; i<=100; i++)
    cout << i*i << "是平方數";
}
//square method 2
#include <cmath>
void generate_squares(){
  for(int i = 1; i <=100*100;i++){
    int squrt_i = sqrt(i);
    if(squrt_i*squrt_i == i )
      cout << i << "是平方數";
  }
}

//find_maximum
void find_maximum(){
  int arr[5] = {3,6,9,18,1};

  in max = -2147483648;
  for(int i =0;i<5;i++){
    if(arr[i]>max)
      max = arr[i];
  }
  cout << "The maximum is " << max;
}

//find number
int arr[5] = {3,6,9,-8,1};
bool find_number(int n){
  for(int i =0; i<5;i++){
    if(arr[i]==n)
      return true;
  }
  return false;
}

//find number 2D array
int arr[3][5] ={
  {3,6,9,-8,1},
  {2,4,6,8,10},
  {11,7,5,3,2}
};

bool find(int n){
  for(int i =0; i<3; i++){
    for(int j = 0; j<5; j++){
      if(arr[i][j]==n)
        return true;
    }
  }
  return false;
}

//closest pair problem method 1
#include <cmath>
void closest_pair(){
  float pair[10][2]={
    {3,3},{1,5},{4,6},{2,8},{9,9},{2,1},{7,2},{6,5},{9,4},{5,9}
  };
  int min_distnace = 1e9;

  for(int i =0; i <10;i++){
    for(int j=i+1; j<10;j++){
      float dx = point[i][0] - point[j][0];
      float dy = point[i][1] - point[j][1];
      float d = sqrt(dx*dx+dy*dy);

      if(d<min_distnace)
        min_distnace =d;
    }
    cout << "距離是" << min_distnace;
  }
}
//closest pair problem method 2
#include <cmath>
struct Point{float x, y;};

float dist(Point& a, Point& b){
  float dx = a.x - b.x;
  float dy = a.y - b.y;
  return sqrt(dx*dx+dy*dy);
}

void closest_pair(){
  Point point[10] = {
    {3,3},{1,5},{4,6},{2,8},{9,9},{2,1},{7,2},{6,5},{9,4},{5,9}
  };
  float min_distnace = 1e9;

  for(int i =0;i<10;i++){
    for(int j =i+1'j<10;j++){
      min_distnace=min(min_distnace,dist(point[i],point[j]));
    }
  }
  cout << "距離是" <<min_distnace;
}

//string matching
void string_matching(){
  char text[15] = "It's a pencil.";
  char pattern[6] = "a pen";

  for(int i =0;i<14,i++){
    bool match =true;
    for(int j =0; j<5;j++){
      if (text[i+j]!=pattern[j])
        match = false;
    }
    if(match)
      cout<< "短字串出現在第" << i <<"個字元";
  }
}
//string matching v2
void string_matching(){
  char text[15] = "It's a pencil.";
  char pattern[6] = "a pen";

  for(int i =0; i <9;i++){
    bool match =true;
    for(int j =0;j<5;j++){
      if(text[i+j]!=pattern[j]){
        match =false;
        break;
      }
    }
    if(match)
      cout << "短字串出現在第" << i <<"個字元";
  }
}

//count letter enumerate method
void count_letter(){
  char s[15] = "Hello World!";
  for(int i =0; s[i];i++){
    if(s[i]>='A' && s[i]<='Z')
      s[i] = s[i]-'A'+'a';
  }
  for(int i =0; i<26;i++){
    int c = 0;
    for(int j =0;s[j];j++){
      if(s[j]==i)
        c++;
    }
    cout << char(i)<<':'<<c;
  }
}

//ch4
//transform string to integer
void string_to_integer(){
  char s[10] = "29646787";

  int n =0;
  for(int i =0; s[i];i++){
    n*=10;
    n+= s[i]-'0';
  }
  cout << n;
}
//atoi 用法
#include <cstdlib>
void string_to_integer(){
  char s[10] = "29646787";
  int n;
  n = atoi(s);
  cout << n;
}

//Collatz conjecture 遞推次數
void collatz_conjecture(int n){
  int c = 0;
  while(n!=1){
    if(n%2==0)
      n = n/2;
    else
      n = n*3+1;
    c++;
  }
  cout << "遞推次數是:" << c << "次";
}

//reapting dicimal
void repeating_decimal(){
  //除數53 被除數1
  int appear[53] ={0}; //餘數出現在哪一次遞推
  int c = 0;//遞推次數
  int r = 1,q=0;

  while(!appear[r]){
    appear[r] = ++c; //c先++然後存進appear[r]
    r = r*10;
    q= r/53;
    cout <<q;
    r = r%53;
  }
  cout << "循環節的長度為" << c - appear[r] + 1;
}

//用試除表建立prime table
void prime_table(){
  //200以內
  int prime[200] ={0};
  int c = 0;
  for(int i =2; i <200;i++){
    if(i == 2)
        prime[c++] = i;
    else{
      bool is_i_prime =true;
      for(int j = 0; prime[j];j++){
        if(i%prime[j]==0){
          is_i_prime =false;
          break;
        }
      }
      if(is_i_prime)
        prime[c++]= i;
    }
  }
  for(int i =0;prime[i];i++)
    cout << prime[i] << '\0';
}

//ch5
//GCD for loop
int gcd(int a,int b){
  int t;
  while(b!=0){
    t = a%b;
    a= b;
    b= t;
  }
  return a;
}
//GCD recursive
int gcd(int a, int b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

//integer factorization for loop method
void factorization(int n){
  int c = 0; //質因數個數
  cout << n;

  for(int i =2;i<=n;i++){
    while(n%i==0){
      n/=i;
      if(c++)
        cout << " * ";
      else
        cout << " = ";
      cout << i ;
    }
  }
}
//integer factorization recursive method
void factorization(int n, int i, int c){
  for(;i<=n;i++)
    if(n%i==0){
      if(c) cout << " * ";
      else cout << " = ";
      cout << i;
      return factorization(n/i,i,c+1);//質因數一定從最小開始分解，i會不斷往上加
      //return
    }
}
void factorization(int n){
  cout << n;
  factorization(n,2,0);
}

//10! interative method
int factorial(int n){
  int sum = 1;
  for(int i = 1;i<n;i++)
    sum += sum*i;
  return sum;
}
//10! recursive method
int factorial(int n){
  int sum = 1;
  if(n==1)
    return 1;
  else
    return sum = n * factorial(n-1);
}

//slection sort recursive method
void selection_sort(int array[],int i, int n){
  if(i==n-1) return;

  int min_index = i;
  for(int j = i+1;j<n;j++)
    if(array[j]<array[min_index])
      min_index = j;
  swap(array[i],array[min_index]);
  selection_sort(array,i+1,n);
}
void selection_sort(){
  int arr[5] = {3,6,9,-8,1};
  selection_sort(arr,0,5);
}

//ch6
//binary search for loop
int binary_search(int n){
  int arr[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  int down = 0;
  int up = 15;
  for(int i = down; i <up; i++){
    if(arr[i]==n)
      return i;
    else{
      int mid = (down + up)/2;
      if(n>mid)
        down = mid+1;
      else
        up = mid-1;
    }
  }
}

//ch7
//stairs problem recursive method + recurrence
int table[6];
bool solve[6];

int f(int n){
  if(n==0||n==1)
    return 1;
  if(solve[n])
    return table[n];
  table[n] = f(n-1)+f(n-2);
  solve[n] = true;
  return table[n];
}

void stair_climbing(){
  for(int i=0;i<=5;i++)
    solve[i] = false;
  cout << "爬完五階的踏法有" << f(5) << "種" <<endl;

  int n;
  while(cin>>n && (n>=0&&n<=5))
    cout << "爬完" << n <<"階的踏法有" << f(n) << "種" <<endl;
}
//merge solve and table array
int table[6];
int f(int n){
  if(n==0||n==1)
    return 1;
  if(table[n])
    return table[n];
  return table[n] = f(n-1)+f(n-2);
}
void stair_climbing(){
  for(int i=0; i <=5;i++)
    table[i] = 0;
  cout << "爬完五階的踏法有" << f(5) << "種" <<endl;
}

//stairs problem iterative method + for loop
int table[6];

void dynamic_programming(){
  table[0] = 1;
  table[1] = 1;

  for(int i =2; i<=5; i++)
    table[i] = table[i-1] + table[i-2];
}
//往後補植的方法 比較難想
void dynamic_programming(){
  for(int i=0;i<=5;i++)
    table[i] = 0;
  table[0] = 1;
  table[1] = 1;

  for(int i =0;i<=5;i++){
    if(i+1 <= 5)
      table[i+1] += table[i];
      table[i+2] += table[i];
  }
}

void stairs_climbing(){
  dynamic_programming(){
    cout << "爬完五階的踏法有" << table[n] << "種" <<endl;
  }
}

//7-2 practice
//100 factorial dynamic_programming
int table[101] //藥用big number才存得進去
void dynamic_programming(){
  table[0] = 1;
  table[1] = 1;
  for(int i =2; i <=100;i++)
    table[i] = table[i-1] * i;
}
//C幾取幾
int C(int n, int m){
  int c =1;
  for(int i=1;i<=m;i++){
    c*=(n-i+1);
    c/=i;
  }
  return c;
}
//Pascal's triangle Cn取m recursive method + recurrence
int table[10][10];
bool solve[10][10];

int C(int n, int m){
  if(m==1)
    return table[n][m] = n;
  if(m=n)
    return table[n][m] = 1;

  if(solve[n][m])
    return table[n][m];

  table[n][m] = C(n-1, m) + C(n-1, m-1);
  solve[n][m] = true;
  return table[n][m];
}
void pascal_triangle(){
  for(int i =0;i<10;i++){
    for(int j=0;j<10;j++)
      solve[i][j] = false;
  }
  int N,M;

  while(cin>>N>>M){
    if(!(N>0&&N<10)) break;
    if(!(M>0&&M<10)) break;
    if(!(N>=M)) break;
    cout << N << "人抓" << M << "人" << C(N,M) << "種方法" << endl;
  }
}
//Pascal's triangle Cn取m interative method + for loop
int table[10][10];

void dynamic_programming(){ //一次算完整個表格
  for(int i=0;i<10;i++) //都不取的方式只有一種
    table[i][0] = 1;
  for(int i=0;i<10;i++) //n=m
    table[i][i] = 1;
  for(int i =1;i<10;i++){
    for(int j =1;j<=i;j++)
      if(j!=0 &&j!=i)
        table[i][j] = table[i-1][j-1]+table[i-1][j];
  }
}
void pascal_triangle(){
  dynamic_programming();

  for(int i =0;i<10;i++)
    for(int j =0;j<=i;j++)
      cout << table[i][j]<<'\0';
}

//7-3
//staircase walk 只能往右或往下走
const int X =8,Y=8;
int c[X][Y];

void staircase_walk(){
  for(int i =0;i<X;i++) c[i][0] = 1;
  for(int j =0;j<Y;j++) c[0][j] = 1;

  for(int i =1; i<X;i++){
    for(int j =1;j<Y;j++)
      c[i][j] = c[i-1][j] + c[i][j-1];
  }

  int x,y;
  while(cin>>x>>y){
    if(!(x>=0 && x<=7)) break;
    if(!(y>=0 && y<=7)) break;
    cout << "由(0,0)走到("<<x<<','<<y<<")有"<<c[x][y]<<"種走法" <<endl;
  }
}
//staircase walk 一維陣列 預設走到(7,7) ????答案不一樣
const int X=8,Y=8;
int c[Y];

void staircase_walk(){
  for(int j=0;j<Y;j++) c[0] =1;
  for(int i=1;i<X;i++)
    for(int j=1;j<Y;j++)
      c[j] += c[j-1];
  cout << c[7];
}

//7-4 0/1 knapsack problem
//查詢表
#include <string.h> //for memset
const int N =100;
const int W = 100000;
int cost[N],weight[N]; //物品價格以及重量可能還要自己輸入
int c[N+1][W+1];

//n為物品數量，w為背包負重上限
void knapsack(int n, intw){
  memset(c,0,sizeof(c)); //把byte設成相同直

  //每個物品都試
  for(int i = 0;i<n;i++){
    //每個重量都試
    for(int j =0;j<=w;j++){
      if(j-weight[i]<0)
        c[i+1][j] = c[i][j]; //超過背包負重，只能不放。i往上數 表示數過，
      else
        c[i+1][j] = max(c[i][j],c[i][j-weight[i]]+cost[i]);
    }
  }
  cout << "最高價值為" <<c[n][w];
}
//recursive method 因為不需要所有查詢表的答案
const int N = 100; W =100000;
int cost[N],weight[N];
int c[N+1][W+1];

int knapsack(int n, int w){
  if(w<0) return -le9;
  if(n==0) return 0;
  if(c[n][w]) return c[n][w];

  return c[n][w] = max(knapsack(n-1,w),knapsack(n-1,w-weight[n])+cost);
}

//7-5 Hamilton path
