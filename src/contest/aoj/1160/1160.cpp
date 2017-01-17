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
#include<cassert>
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

vector< vector<i32> > M;
i32 w,h;

void dfs(int y,int x,int id){
  int dx[]={1,0,-1,0,1,-1,1,-1};
  int dy[]={0,1,0,-1,1,1,-1,-1};
  M[y][x]=id;
  rep(i,8){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(0<=nx && nx<w and 0<=ny && ny<h){
	if(M[ny][nx]==1)dfs(ny,nx,id);
      }
  }
}

int main()
{
  while(true){
  
    cin>>w>>h;
    if(!w and !h)break;
    M.clear();
    M.resize(h,vector<i32>(w));
    rep(i,h){
      rep(j,w){
	cin>>M[i][j];
      }
    }
    
    int ans=0;
    rep(i,h)rep(j,w){
      if(M[i][j]==1){
	dfs(i,j,ans++ +2);
      }
    }
    
    cout<<ans<<endl;
  }
  
  return 0;
}
