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


vector< vector<double> > C;
double p,q;

double pqCombination(int n,int k){
  if(C[n][k]>=0)return C[n][k];
  else if(n==0)return 1;
  else if(k==0)
    return C[n][k]=p*pqCombination(n-1,0);
  else if(k==n)
    return C[n][k]=q*pqCombination(n-1,n-1);
  else
    return C[n][k]=q*pqCombination(n-1,k-1)+p*pqCombination(n-1,k);
}

int main()
{
  int n;
  int t;
  cin>>n>>p>>t;
  q=1-p;
  C.resize(t+1,vector<double>(t+1,-1));

  double ans=0;
  rep(i,t+1){
    if(t-i<=n)
      ans+=(t-i)*pqCombination(t,i);
    else{
      ans+=n*pqCombination(t,i);
    }
  }
  printf("%.9f\n",ans);
  return 0;
}
