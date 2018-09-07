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


int main()
{
  int N,M;
  cin>>N>>M;
  vector< string > G(N);
  vector< vector<int> > Ans(N);
  rep(n,N){
    Ans[n].resize(M,0);
    cin>>G[n];
  }

  const int dx[]={1,0,-1,0};
  const int dy[]={0,1,0,-1};
  
  rep(y,N){
    if(y==0||y==N-1)continue;
    rep(x,M){
      if(x==0||x==M-1)continue;
      int min_v=10;
      rep(dir,4){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        min_v=min(min_v,G[ny][nx]-'0');
      }
      rep(dir,4){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        G[ny][nx]-=min_v;
      }
      Ans[y][x]+=min_v;
    }
  }

  rep(y,N){
    rep(x,M){
      printf("%d",Ans[y][x]);
    }
    putchar('\n');
  }
  
  return 0;
}
