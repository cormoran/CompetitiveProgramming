#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

enum Direction{U,R,D,L,None};

struct state{
  int x,y;
  Direction dir;
  int cost;
  state(int x_,int y_,Direction dir_,int c):x(x_),y(y_),dir(dir_),cost(c){;}
  bool operator>(const state &r)const{
    return cost>r.cost;
  }
};

int main()
{
  int w,h;
  while(true){
    //input
    cin>>w>>h;
    if(!w&&!h)break;
    int s[30][30];
    rep(i,h)rep(j,w)cin>>s[i][j];
    int cost[4];rep(i,4)cin>>cost[i];

    //solve
    int dijk[30][30][4];//[y][x][dir]
    rep(i,h)rep(j,w)rep(k,4)dijk[i][j][k]=INF;
    priority_queue<state,vector<state>,greater<state> > que;
    que.push(state(0,0,R,0));
    
    while(!que.empty()){
      state now =que.top();que.pop();
      if(dijk[now.y][now.x][now.dir]!=INF)continue;
      dijk[now.y][now.x][now.dir]=now.cost;

      Direction afturn;
      if(s[now.y][now.x]==4)
	afturn=None;
      else
	afturn=(Direction)((now.dir+s[now.y][now.x])%4);
      
      if(now.x  >0)que.push(state(now.x-1,now.y,L,now.cost+(afturn==L?0:cost[(L-now.dir+4)%4])));
      if(now.y  >0)que.push(state(now.x,now.y-1,U,now.cost+(afturn==U?0:cost[(U-now.dir+4)%4])));
      if(now.x+1<w)que.push(state(now.x+1,now.y,R,now.cost+(afturn==R?0:cost[(R-now.dir+4)%4])));
      if(now.y+1<h)que.push(state(now.x,now.y+1,D,now.cost+(afturn==D?0:cost[(D-now.dir+4)%4])));
    }
    
    int ans=INF;
    rep(i,4)
      ans=min(ans,dijk[h-1][w-1][i]);
    cout<<ans<<endl;
  }

  
  return 0;
}






