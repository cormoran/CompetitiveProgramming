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
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10


int n,m;
typedef pair<int,int> pii;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int dotnum(vector< vector<char> > &G,int y,int x){
  int cnt=0;

  if(!(x>=0 and x<m and y>=0 and y<n and G[y][x]=='.'))return cnt;
  
  rep(i,4){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx>=0 and nx<m and ny>=0 and ny<n and G[ny][nx]=='.'){
      cnt++;
    }
  }
  return cnt;
}

int main()
{
  cin>>n>>m;
  vector< vector<char> > G(n,vector<char>(m));
  int dots=0;
  rep(i,n){
    char c[2010];
    scanf("%s",c);
    rep(j,m){
      G[i][j]=c[j];
      if(c[j]=='.')++dots;
    }
  }


  char sym[4][2]={ {'v','^'},{'<','>'},{'^','v'},{'>','<'} };


  queue< pii > q;
  
  rep(y,n){
    rep(x,m){
      if(G[y][x]!='.')continue;
      int cnt=dotnum(G, y, x);
      if(cnt==1){
	q.push(make_pair(y,x));
      }
      if(cnt==0)goto NU;
    }
  }

  while(!q.empty()){
    int y=q.front().first;
    int x=q.front().second;
    q.pop();
    rep(i,4){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx>=0 and nx<m and ny>=0 and ny<n and G[ny][nx]=='.'){
	G[y][x]=sym[i][0];
	G[ny][nx]=sym[i][1];
	dots-=2;
	rep(j,4){
	  int nnx=nx+dx[j];
	  int nny=ny+dy[j];
	  if(dotnum(G,nny,nnx)==1)q.push(make_pair(nny,nnx));
	}
      }
    }
  }
  if(dots>0)goto NU;
  

  rep(i,n){
    rep(j,m){
      printf("%c",G[i][j]);
    }
    printf("\n");
  }
  
  return 0;

NU:
  cout<<"Not unique"<<endl;
  
}
