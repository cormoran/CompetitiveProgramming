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
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

struct T{
  pii t,b;
};

vector<vector<int>> G;

int calc_min(pii t,pii b){
  int tmp=min(G[t.first][t.second],G[t.first][b.first]);
  tmp=min(tmp,G[t.second][b.first]);
  tmp=min(tmp,G[t.second][b.second]);
  return tmp;
}

int main()
{
  int n,m;cin>>n>>m;//r,c
  G.reserve(n);
  rep(r,n){
    G[r].reserve(m);
    rep(c,m){
      scanf("%d",&G[r][c]);
    }
  }

  T DP[1005][1005];
  rep(i,n)DP[i][0]={{0,0},{0,0}};
  rep(i,m)DP[0][i]={{0,0},{0,0}};
  
  rep(r,n){
    rep(c,m){
      T t=DP[r-1][c-1];
      if(calc_min(t.t, t.b)>calc_min(DP[r-1][c-1].t, make_pair(r,c))){
        t={DP[r-1][c-1].t,make_pair(r,c)};
      }
      if(calc_min(t.t, t.b)>calc_min(DP[r-1][c-1].b, make_pair(r,c))){
        t={DP[r-1][c-1].b,make_pair(r,c)};
      }
      DP[r][c]=t;
    }
  }

  cout<<calc_min(DP[n-1][m-1].t,DP[n-1][m-1].b)<<endl;
  
  return 0;
}
