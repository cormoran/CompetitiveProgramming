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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main()
{
  int N,COST;cin>>N>>COST;
  vector<int> val(N+1);
  vector<int> cost(N+1);
  rep(i,N)cin>>cost[i+1]>>val[i+1];


  pii DP[10][500*100+1+100]={};
  rep(j,COST+101)DP[0][j].second=1000;
  repeat(i,1,N+1){
    rep(j,COST+101){ 
      if(j-cost[i]>=0 && j-cost[i]<=COST ){
        if(DP[i-1][j].first <= DP[i-1][j-cost[i]].first+val[i] &&
           (j<=COST || DP[i-1][j-cost[i]].second<=cost[i])){
          DP[i][j].first=DP[i-1][j-cost[i]].first+val[i];
          DP[i][j].second=min(DP[i-1][j].second,cost[i]);
        }
      }
      else DP[i][j]=DP[i-1][j];
    }
  }

  int ans=0;
  repeat(i,COST,COST+101){
    ans=max(ans,DP[N][i].first);
  }
  cout<<ans<<endl;
  
  return 0;
}


