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

struct State{
  int r,c,t;
};

int main()
{
  int R,C;
  cin>>R>>C;
  vector<string> G(R);
  int sr,sc;
  rep(r,R){
    cin>>G[r];
    rep(c,C){
      if(G[r][c]=='E'){
        sr=r;sc=c;
      }
    }
  }

  //printf("sr,sc : %d %d\n",sr,sc);
  bool visited[1001][1001]={};
  visited[sr][sc]=true;
  queue<State> que;
  que.push({sr,sc,0});
  const int dx[4]={0,1,0,-1};
  const int dy[4]={-1,0,1,0};
  ll ans=0;
  int last_time=1<<30;
  while(!que.empty()){
    int nowr=que.front().r;
    int nowc=que.front().c;
    int nowt=que.front().t;
    que.pop();
    if(nowt>last_time)break;
    if(isdigit(G[nowr][nowc])){
      ans+=G[nowr][nowc]-'0';
      //printf("r,c,pt : %d %d %d\n",nowr,nowc,G[nowr][nowc]-'0');
    }
    if(G[nowr][nowc]=='S')last_time=nowt;
    rep(dir,4){
      int nr=nowr+dy[dir];
      int nc=nowc+dx[dir];
      if(nr<0 || nr>=R || nc<0 ||nc>=C)continue;
      if(!visited[nr][nc] && G[nr][nc]!='T'){
        visited[nr][nc]=true;
        que.push({nr,nc,nowt+1});
      }
    }
  }

  cout<<ans<<endl;
  
  return 0;
}
