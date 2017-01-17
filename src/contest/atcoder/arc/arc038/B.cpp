
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
//typedef int64_t i64;typedef int32_t i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int H,W;
vector<string> G;

int dx[]={1,1,0};
int dy[]={0,1,1};

//先手必勝を仮定する if fst turn=false

int  DP[101][101][2];

bool rec(int y,int x,bool turn){
  if(DP[y][x][turn]>=0)return DP[y][x][turn];
  bool flg = turn;

  rep(i,3){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<W and ny<H and G[ny][nx]=='.'){
      if(!turn){
	//先行ターン
	flg|=rec(ny,nx,!turn);
      }
      else{
	//後攻ターン
	flg&=rec(ny,nx,!turn);
      }
    }
    else {
      if(!turn)flg|=turn;
      else flg&=turn;
    }
  }
  return DP[y][x][turn]=flg;
}

int main()
{
  cin>>H>>W;
  G.resize(H);
  rep(i,H)cin>>G[i];
  rep(i,H)rep(j,W)rep(k,2)DP[i][j][k]=-1;
  cout<<(rec(0,0,false)==true ? "First":"Second")<<endl;
  
  return 0;
}
