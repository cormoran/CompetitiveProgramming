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

const i32 INF=1<<30;//=10E10


void update(vector<vector<i32> > &G,i32 time,i32 x,i32 y,i32 dx,i32 dy){
  i32 nx=x+dx;
  i32 ny=y+dy;
  if(0<=nx&&nx<G[0].size()&&0<=ny&&ny<G.size()){
    if(G[ny][nx]>=0){
      G[ny][nx]*=time;
      update(G,time,nx,ny,dx,dy);
    }
  }
}

struct State{
  i32 x,y;
  i32 time;
  i32 cost;
  State(i32 x_,i32 y_,i32 time_,i32 cost_):x(x_),y(y_),time(time_),cost(cost_){;}
};
const i32 times[4]={2,3,5,7};
const i32 dx[4]={0,1,0,-1};
const i32 dy[4]={1,0,-1,0};

int main()
{
  i32 T;cin>>T;


  
  
  rep(t,T){
    i32 H,W;cin>>H>>W;
    vector<vector<char> > input(H,vector<char>(W));
    vector<vector<i32> > G(H,vector<i32>(W,11));
    queue<State> que;
    vector< vector<vector<i32> > > dist(H,vector<vector<i32> >(W,vector<i32>(4,INF)));
    
    i32 Gx,Gy;
    rep(i,H)rep(j,W){
      cin>>input[i][j];
      switch(input[i][j]){
      case '^':
      case'v':
      case'>':
      case'<':
      case '#':
	G[i][j]=-1;
      }
    }

    rep(i,H)rep(j,W){
      char c=input[i][j];
      i32 temp=-1;
      
      if(c=='^'){G[i][j]=-1;temp=0;}
      else if(c=='>'){G[i][j]=-1;temp=3;}
      else if(c=='v'){G[i][j]=-1;temp=2;}
      else if(c=='<'){G[i][j]=-1;temp=1;}
      else if(c=='S'){que.push(State(j,i,0,0));}
      else if(c=='G'){Gx=j;Gy=i;}
      else if(c=='#'){G[i][j]=-1;}
      else{;}

      if(temp>=0){
	update(G,times[temp],j,i,0,-1);
	update(G,times[(temp+1)%4],j,i,1,0);
	update(G,times[(temp+2)%4],j,i,0,1);
	update(G,times[(temp+3)%4],j,i,-1,0);
      }
    }
    

    i32 ans=-1;
    while(!que.empty()){
      State now=que.front();que.pop();
      if(now.x==Gx && now.y==Gy){ans=now.cost;break;}
      if(dist[now.y][now.x][now.time]!=INF)continue;
      dist[now.y][now.x][now.time]=now.cost;
      rep(i,4){
	i32 nx=now.x+dx[i];
	i32 ny=now.y+dy[i];
	i32 nt=(now.time+1)%4;
	if(0<=nx&&nx<W&&0<=ny&&ny<H){
	  if(G[ny][nx]>=0 && G[ny][nx]%times[nt]!=0){
	    //printf("x %d y %d t %d\n",nx,ny,nt);
	    que.push(State(nx,ny,nt,now.cost+1));
	  }
	}
      }
    }

      printf("Case #%d: ",t+1);
      if(ans>=0)cout<<ans<<endl;
      else cout<<"impossible"<<endl;

      //rep(i,H){rep(j,W)cout<<G[i][j];cout<<endl;}
    
  }
  
  return 0;
}















