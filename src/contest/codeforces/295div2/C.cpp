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

#define MOD 1000000007L

int main()
{
  int n;cin>>n;
  string s;cin>>s;
  sort(all(s));
  vector<int> cnum(4,0);//A C G T
  char c[4]={'A','C','G','T'};
  rep(i,4){
    cnum[i]=distance(lower_bound(all(s),c[i]),upper_bound(all(s),c[i]));
    //    cout<<cnum[i]<<endl;
  }
  sort(all(cnum));

  int samenum=1;
  rep(i,3)if(cnum[i]==cnum[3])samenum++;

  i64 ans=1;
  rep(i,s.size()){
    ans=(ans*samenum)%MOD;
  }
  cout<<ans<<endl;
  return 0;
}
