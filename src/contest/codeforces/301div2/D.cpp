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

typedef pair<double,double> pdd;

pair<double,double> DP[101][101][101]={}; //r&s

pair<double,double> rec(int r,int s,int p){
  if(DP[r][s][p].first>=0)return DP[r][s][p];
  
  pdd ret=make_pair(0,0);
  int deno=(r+s+p)*(r+s+p-1)/2;
  
  if(r>0)deno-=r*(r-1)/2;
  if(s>0)deno-=s*(s-1)/2;
  if(p>0)deno-=p*(p-1)/2;

  
  //r&p
  pdd tmp;
  if(r>0){
  tmp=rec(r-1,s,p);
  ret.first+=tmp.first*p*r/deno;
  ret.second+=tmp.second*p*r/deno;
  }
  //r&s
  if(s>0){
  tmp=rec(r,s-1,p);
  ret.first+=tmp.first*s*r/deno;
  ret.second+=tmp.second*s*r/deno;
  }
  //s&p
  if(p>0){
  tmp=rec(r,s,p-1);
  ret.first+=tmp.first*p*s/deno;
  ret.second+=tmp.second*p*s/deno;
  }
  return DP[r][s][p]=ret;
}



int main()
{
  int r,s,p;
  cin>>r>>s>>p;
  rep(i,101)rep(j,101)rep(k,101)DP[i][j][k]=make_pair(-1,-1);
  rep(i,101){
    DP[0][0][i]=make_pair(0,0);
    DP[i][0][0]=make_pair(1,0);
    DP[0][i][0]=make_pair(0,1);
  }


  pdd ans=rec(r,s,p);

  printf("%.10f %.10f %.10f\n",ans.first,ans.second,1-ans.first-ans.second);
  
  return 0;
}
