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

vector< vector<int> > G;
vector< bool > visited;

//retrun true if cycle was found.
bool dfs(int pre,int now){
  if(visited[now])return true;
  visited[now]=true;
  bool flg=false;
  for(auto i : G[now]){
    if(i!=pre){
      if(dfs(now,i))return true;
    }
  }
  return false;
}

int main()
{
  int N,M;
  cin>>N>>M;
  G.resize(N);
  visited.resize(N,0);
  
  rep(i,M){
    int p1,p2;cin>>p1>>p2;
    p1--;
    p2--;
    G[p1].push_back(p2);
    G[p2].push_back(p1);
  }
  int ans=0;
  rep(i,N){
    if(!visited[i]){
      if(!dfs(-1,i))ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
