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
#include<set>
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
  int Q;cin>>Q;
  vector< set<int> > V(ceil(sqrt(200000)));

  rep(i,Q){
    int t,x;cin>>t>>x;
    if(t==1){
      V[x/V.size()].insert(x);
    }
    else if(t==2){
      int cnt=0,i=0;
      for(;cnt<x;i++)cnt+=V[i].size();
      --i;
      cnt-=V[i].size();
      auto itr=V[i].begin();
      advance(itr,x-cnt-1);
      V[i].erase(itr);
      cout<<*itr<<endl;
    }
  }
  
  return 0;
}
