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

int main()
{
  i32 n;cin>>n;
  vector<i32> actives,negatives;

  i32 sum=0;
  i32 minn=INF;
  i32 nnum=0;
  rep(i,2*n-1){
    i32 t;cin>>t;
    sum+=abs(t);
    minn=min(minn,abs(t));
    if(t<0)nnum++;
  }
  if(n%2==0 && minn<INF && nnum%2==1)sum-=minn*2;
  
  cout<<sum<<endl;
  return 0;
  
}










