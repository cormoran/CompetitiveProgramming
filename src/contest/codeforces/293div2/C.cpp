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
//#include<>
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
  i64 n,m,k;
  cin>>n>>m>>k;
  vector<int> scr(n+1),app(n+1);
  rep(i,n){
    cin>>scr[i+1];
    app[scr[i+1]]=i+1;
  }

  i64 ans=0;
  rep(i,m){
    i64 b;cin>>b;
    ans+=(app[b]-1)/k+1;
    if(app[b]!=1){
      i64 swappedapp=scr[app[b]-1];
      scr[app[b]-1]=b;
      scr[app[b]]=swappedapp;
      app[b]--;
      app[swappedapp]++;
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
