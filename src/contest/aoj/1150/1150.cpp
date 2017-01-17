#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;


typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

typedef vector< vector<i32> > Mat;
typedef pair<i32,i32> pii;


const i32 INF=1<<30;//=10E10
const i32 dx[9]={1,1,1,1,1,2,2,2,3};
const i32 dy[9]={2,1,0,-1,-2,1,0,-1,0};


int W,H;
vector< vector<i32> > G;
vector<int> sx,sy,gx,gy;

struct state{
  int y,x;
  int cost;
  bool foot;
  state(int y_,int x_ ,int c,bool f):y(y_),x(x_),cost(c),foot(f){;}
  bool operator<(const state &r)const{return cost<r.cost;}
  bool operator>(const state &r)const{return cost>r.cost;}  
};


vector< vector<i32> > dist[2];

void dijkstra(){
  priority_queue< state ,vector<state>,greater<state> > que;

  rep(i,2)dist[i].resize(H,vector<i32>(W,INF));

  rep(i,sx.size()){
    que.push(state(sy[i],sx[i],0,true));
    que.push(state(sy[i],sx[i],0,false));
  }

  while(!que.empty()){
    state now=que.top();que.pop();
    if(dist[now.foot][now.y][now.x]<INF)continue;
    dist[now.foot][now.y][now.x]=now.cost;

    rep(i,9){
      i32 nx=now.x + dx[i]*(now.foot? 1:-1);
      i32 ny=now.y+dy[i];
      if(0<=nx && nx<W && 0<=ny && ny<H){
	if(G[ny][nx]<INF)
	  que.push(state(ny,nx,now.cost+G[ny][nx],!now.foot));
      }
    }   
  }
  
}


int main()
{
  while(1){
    G.clear();
    dist[0].clear();
    dist[1].clear();
    sx.clear();
    sy.clear();
    gy.clear();
    gx.clear();
    
  cin>>W>>H;
  if(W==0)break;
  G.resize(H,vector<int>(W,INF));
  
  rep(y,H)rep(x,W){
    char s;
    cin>>s;
    if(s=='S'){
      sx.push_back(x);
      sy.push_back(y);
      G[y][x]=0;
    }
    else if(s=='T'){
      gx.push_back(x);
      gy.push_back(y);
      G[y][x]=0;
    }
    else if(s=='X')G[y][x]=INF;
    else G[y][x]=s-'0';
  }
  
  dijkstra();

  int ans=INF;
  
  rep(i,gx.size()){
    ans=min(ans,dist[0][gy[i]][gx[i]]);
    ans=min(ans,dist[1][gy[i]][gx[i]]);
  }
  
  cout<<(ans>=INF ? -1 : ans)<<endl;

  } 
  return 0;
}
