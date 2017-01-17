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

int f(i64 n){
  int ret=0;
  while(n){
    ret+=n%10;
    n/=10;
  }
  return ret;
}

int solve(){
  i64 n;
  cin>>n;
  vector<i64> ans;
  for(i64 i=n-165;i<=n;i++){
    if(f(i)+i==n)ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i]<<endl;
  }
  return 0;
}

int main()
{
  solve();
  return 0;
}
