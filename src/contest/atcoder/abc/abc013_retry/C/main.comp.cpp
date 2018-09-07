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
#include<map>
//#include<cstdint>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

int main()
{
  int N,H,A,B,C,D,E;
  cin>>N>>H>>A>>B>>C>>D>>E;

  int K=INF;

  rep(i,N){
    int nK=A*(N*E-H)+(B*C-A*D)*(i+1);
    if(nK>=K){
      if(ceil((double)K/B)==floor((double)K/B))
	K=(double)K/B;
      else
	K=(double)nK/B;
      std::cout << K << std::endl;
      return 0;
    }
    
  }
  
  return 0;
}
