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
  vector<i32> score(26);
  rep(i,26)cin>>score[i];
  string s;cin>>s;

  vector< map<i64,i64> > ssum(26);

  i64 ans=0;
  i64 asum=0;
  rep(i,s.size()){
    int si=s[i]-'a';
    ans+=ssum[si][asum];
    asum+=score[si];
    ssum[si][asum]++;
  }
  
  cout<<ans<<endl;
  return 0;
}
