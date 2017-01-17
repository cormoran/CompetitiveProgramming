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
#include<ctype.h>
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
  string s,t;
  cin>>s>>t;
  int num[60]={};
  rep(i,t.size()){
    num[t[i]-'A']++;
  }

  int YAY=0,WHPS=0;
  rep(i,s.size()){
    if(num[s[i]-'A']>0){
      YAY++;
      num[s[i]-'A']--;
      s[i]=' ';
    }
  }

  rep(i,s.size()){
    if(s[i]==' ')continue;
    char c;
    if(islower(s[i])==0)
      c=toupper(s[i]);
    else c=tolower(s[i]);
    
    c-='A';
    if(num[c]>0){
      WHPS++;
      num[c]--;
    }
  }

  printf("%d %d\n",YAY,WHPS);
  return 0;
}
