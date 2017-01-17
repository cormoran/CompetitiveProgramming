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

const i64 MOD= 1000000007L;

i64 Combination(int n,int k){
  i64 c=1,m=1;
  for(;k>0;k--){
    c=c*(n--)%MOD;
    m=m*k%MOD;
  }
  return c/m;
}

int main()
{
  i32 n;cin>>n;
  i32 num[4]={};
  rep(i,n){
    i32 a;cin>>a;
    num[a]+=1;
  }
  i64 ans=0;

  if(num[3]>0)ans=1;
  for(i32 i=num[3];i>2;i--)ans=ans*i%MOD;
  if(num[3]>=4)ans=ans*(num[3]-2)%MOD;
  
  if(num[2]>0){
    repeat_eq(i,1,num[2])
      ans=ans*(2*num[3]+i)%MOD;
    ans/=2;
  }
  if(num[1]>0){
    repeat_eq(i,1,num[1])
      ans=ans*i%MOD;
  }
  cout<<ans<<endl;
  return 0;
}
