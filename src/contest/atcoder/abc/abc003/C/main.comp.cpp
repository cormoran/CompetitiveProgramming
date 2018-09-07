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
//typedef int64_t i64;typedef int32_t i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> R(n);
  rep(i,n){
    cin>>R[i];
  }
  sort(all(R),greater<int>());
  double rate=0;
  rep(i,k){
    rate=(rate+R[k-i-1])/2.0;
  }
  printf("%.8f\n",rate);
  
  return 0;
}
