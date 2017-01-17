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
  int N;
  cin>>N;
  if(N%400==0){
    cout<<"YES"<<endl;
    return 0;
  }
  if(N%100==0){
    cout<<"NO"<<endl;
    return 0;
  }
  if(N%4==0){
    cout<<"YES"<<endl;
    return 0;
  }
  cout<<"NO"<<endl;
  
  return 0;
}
