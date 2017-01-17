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
  int n,m;cin>>n>>m;
  int red=0;
  while(n<m){
    n*=2;
    red++;
  }
  int blue=0;
  while(n>m){
    n-=1;
    blue++;
  }
  int outside=0;
  int subs=0;
  while(red>0 and blue>0){
    red--;
    outside+=blue%2;
    blue/=2;
    subs++;
  }
  cout<<red+blue+subs+outside<<endl;
  
  
  return 0;
}
