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


int H,W;
char MEMO[500][500][2];

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
vector<string> G;

bool is_wall(int wy,int wx,int s){
  if(s==0)return G[wy][wx]=='1';
  else return G[wy][wx]=='0';
}

int dfs(int y,int x,int s){
  if(MEMO[y][x][s]>=0)return MEMO[y][x][s];
  MEMO[y][x][s]=0;
  //各方向
  int flg=0;
  rep(i,4){
    int wny=2*y+1+dy[i];
    int wnx=2*x+1+dx[i];
    
    if(!is_wall(wny, wnx, s)){
      int ny=y+dy[i];
      int nx=x+dx[i];

      if(ny<0 or H<=ny or nx<0 or W<=nx)return MEMO[y][x][s]=1;      
      if( dfs(ny,nx,0) and dfs(ny,nx,1))return MEMO[y][x][s]=1;

      /*
        WA : 
        if( dfs(ny,nx,1) and dfs(ny,nx,0))return MEMO[y][x][s]=1;
        WA :
        if( dfs(ny,nx,s) and dfs(ny,nx,(s+1)%2)return MEMO[y][x][s]=1;
       */
      
    }
  }
  return MEMO[y][x][s]=flg;
}

int main()
{
  int cnt=0;
  while(true){
    cnt++;
    int R,C;
    cin>>H>>W>>R>>C;
    if(cnt==31){
      //fprintf(stderr,"%d %d %d %d\n",H,W,R,C);
    }
    if(!H&&!W&&!R&&!C)break;
    string gomi;
    getline(cin,gomi);
    
    G.resize(2*H+1);
    rep(i,2*H+1){
      getline(cin,G[i]);
      //if(cnt==31)cerr<<G[i]<<endl;
    }

    rep(i,500)rep(j,500)rep(k,2){
      MEMO[i][j][k]=-1;
    }


    cout<< (dfs(R-1,C-1,0)==1 ? "Yes" : "No") <<endl;
    
  }
  
  return 0;
}
