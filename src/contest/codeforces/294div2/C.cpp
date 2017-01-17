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
  int older,newbie;
  cin>>older>>newbie;

  int cnt=0;
  while(true){
    int *b,*m;
    if(older>=newbie){
      b=&older;m=&newbie;
    }
    else{
      m=&older;b=&newbie;
    }

    if(*b<2)break;
    if(*m<1)break;

    *b-=2;
    *m-=1;

    cnt++;
    
  }

  cout<<cnt<<endl;
  
  return 0;
}
