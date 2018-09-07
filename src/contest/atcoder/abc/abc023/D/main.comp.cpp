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

vector< pair<i64,i64> > d;

bool check(i64 h){
  vector<i64> V(d.size(),0);
  rep(i,(int)d.size()){
    i64 tmp=h-d[i].first;
    if(tmp<0)return false;
    tmp/=(double)d[i].second;
    if(tmp>=d.size())tmp=d.size()-1;
    V[tmp]++;
  }
  int sum=0;
  rep(i,(int)d.size()){
    sum+=V[i];
    if(sum>i+1)return false;
  }
  return true;
}

int main()
{
  int N;
  cin>>N;
  d.resize(N);
  rep(i,N){
    int h,s;cin>>h>>s;
    d[i]=make_pair(h,s);
  }

  i64 r=1000000000000000LL;
  i64 l=0;

  while(l<r-1){
    i64 m=(r+l)/2;
    if(check(m))r=m;
    else l=m;
  }
  cout<<r<<endl;
  
  return 0;
}
