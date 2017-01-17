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
  int n;cin>>n;
  vector<int> ncnt(10,0);
  rep(i,n){
    char c;cin>>c;
    ncnt[c-'0']++;
  }
  ncnt[0]=ncnt[1]=0;

  rep(i,ncnt[9]){
    ncnt[7]+=1;
    ncnt[3]+=2;
    ncnt[2]+=1;
  }
  ncnt[9]=0;

  rep(i,ncnt[8]){
    ncnt[7]+=1;
    ncnt[2]+=3;
  }
  ncnt[8]=0;

  rep(i,ncnt[6]){
    ncnt[5]+=1;
    ncnt[3]+=1;
  }
  ncnt[6]=0;

  rep(i,ncnt[4]){
    ncnt[3]+=1;
    ncnt[2]+=2;
  }
  ncnt[4]=0;
  
  
  rep(i,9){
    rep(j,ncnt[9-i]){
	cout<<9-i;
      }
  }
  cout<<endl;
  
  return 0;
}
