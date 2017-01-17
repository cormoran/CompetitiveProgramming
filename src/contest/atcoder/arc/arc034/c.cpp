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

const i64 MOD = 1000000007;
int solve(){
  i64 A,B;cin>>A>>B;

  map<int,int> primes;
  repeat(N,B+1,A+1){
    i64 n=N;
    
    for(i64 i=2;n>1 && i*i<=n;){
      if(n%i==0){
	++primes[i];
	n/=i;
      }
      else i+=1;
    }
    if(n!=1)++primes[n];
  }
  i64 pnum=1;

  for(auto itr : primes){
    pnum=(pnum*(1+itr.second))%MOD;
  }
  
  cout<<pnum<<endl;
  return 0;
}

int main()
{
  solve();
  return 0;
}
