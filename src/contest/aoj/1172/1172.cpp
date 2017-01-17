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

vector<int> isprime;

//n以下の素数列挙
void primefactorize(i64 n){
  isprime.resize(n+1,1);
  isprime[0]=isprime[1]=0;
  rep(i,n+1){
    if(isprime[i]==0)continue;
    i64 j=2;
    while(i*j<=n)isprime[i*j++]=0;
  }
}

int main()
{
  primefactorize(123456*2+1);
  repeat(i,1,isprime.size())isprime[i]+=isprime[i-1];

  while(true){
    i64 n;
    cin>>n;
    if(n==0)break;
    cout<<isprime[2*n]-isprime[n]<<endl;
  }
  
  return 0;
}
