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
  i32 n,m;cin>>n>>m;
  i32 one=0;
  i32 mione=0;
  rep(i,n){
    i32 a;cin>>a;
    if(a==1)one++;
    else mione++;
  }
  
  rep(i,m){
    i32 r,l;
    cin>>l>>r;
    i32 rng=r-l+1;
    if(rng%2==1)cout<<0<<endl;
    else if(one>=rng/2 && mione>=rng/2)cout<<1<<endl;
    else cout<<0<<endl;
  }
  return 0;
}
