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
#include<unordered_map>
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
  i32 n;cin>>n;
  vector<int> fst(n),snd(n-1),thd(n-2);

  rep(i,n)cin>>fst[i];
  rep(i,n-1)cin>>snd[i];
  rep(i,n-2)cin>>thd[i];

  sort(all(fst));
  sort(all(snd));
  sort(all(thd));
  /*
  rep(i,n)cout<<fst[i]<<" ";
  puts("\n");
  rep(i,n-1)cout<<snd[i]<<" ";
  puts("\n");
  rep(i,n-2)cout<<thd[i]<<" ";
  puts("\n");
  */
  int ans2;
  bool flg=false;
  rep(i,n-2){
    if(snd[i]!=thd[i]){
      flg=true;
      ans2=snd[i];
      break;
    }
  }
  if(!flg)ans2=snd[snd.size()-1];

  int ans1;
  flg=false;
  rep(i,n-1){
    if(snd[i]!=fst[i]){
      flg=true;
      ans1=fst[i];
      break;
    }
  }
  if(!flg)ans1=fst[fst.size()-1];
    
  cout<<ans1<<endl<<ans2<<endl;
  
  return 0;
}










