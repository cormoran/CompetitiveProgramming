//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<cstdint>
#include<map>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

int main()
{
  i64 n;cin>>n;
  vector<i64> time(n);
  rep(i,n)cin>>time[i];
  sort(all(time));

  i64 minpenalty=0;
  i64 now=0;
  vector<i64> numcnt;
  i64 val=time[0];
  numcnt.push_back(0);
  rep(i,time.size()){
    if(time[i]!=val){
      numcnt.push_back(1);
      val=time[i];
    }
    else numcnt[numcnt.size()-1]++;
    now+=time[i];
    minpenalty+=now;
  }

  i64 ways=1;

  for(auto i : numcnt){
    for(i64 j=i;j>1;j--){
      ways=ways*j%1000000007;
    }
  }

  cout<<minpenalty<<endl<<ways<<endl;
  
  return 0;
}
