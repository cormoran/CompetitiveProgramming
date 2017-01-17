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


int main()
{
  int n;cin>>n;
  string s;cin>>s;
  bool flg[26]={};

  rep(i,s.size()){
    if(islower(s[i])){
      flg[s[i]-'a']=true;
    }
    else{
      flg[s[i]-'A']=true;
    }
  }

  bool ans=true;
  rep(i,26){
    if(flg[i]==false)ans=false;
  }

  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
