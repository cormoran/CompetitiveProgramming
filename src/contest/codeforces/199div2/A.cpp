#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//=10E10

vector<i64> fib;
string cant="I'm too stupid to solve this problem";


i64 makefib(i64 num){
  if(fib[num]>=0)return fib[num];
  fib[num]=makefib(num-1)+makefib(num-2);  
  return fib[num];
}


int main()
{
  fib.resize(101,-1);
  fib[0]=0;
  fib[1]=1;

  i64 n;cin>>n;
  makefib(50);
  i64 here=-1;
  rep(i,50){
    if(fib[i]==n)here=i;
  }
  if(here<0)cerr<<"err";
  else{
    if(here==0){
      printf("%d %d %d\n",0,0,0);
    }
    else if(here==1){
      printf("%d %d %d\n",0,0,1);
    }
    else
      cout<<0<<" "<<fib[here-1]<<" "<<fib[here-2]<<endl;
  }

  return 0;
}

















