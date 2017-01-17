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

vector< string> G;
int w,h;
int sr,sc;
int er,ec;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


int main()
{
  cin>>h>>w;
  G.resize(h);
  rep(i,h)cin>>G[i];
  cin>>sr>>sc;
  cin>>er>>ec;

  sr--;sc--;er--;ec--;

  queue< pair<int,int> > que;

  que.push(make_pair(sr,sc));
  bool flg=(G[er][ec]=='X' ? true : false);
  
  while(!que.empty()){

    /*
    rep(i,h){
      rep(j,w){
	cout<<G[i][j]<<" ";
      }
      puts("");
    }
    puts("");
    */
    
    int y=que.front().first;
    int x=que.front().second;
    que.pop();
    
    rep(i,4){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(0<=nx and nx<w and 0<=ny and ny<h){
	if(!flg){
	  if(ny==er and nx==ec){
	    flg=true;
	    while(!que.empty())que.pop();
	    que.push(make_pair(ny,nx));
	    G[ny][nx]='V';
	    continue;
	  }
	  if(G[ny][nx]=='.'){
	    que.push(make_pair(ny,nx));
	    G[ny][nx]='V';
	  }
	}
	else{
	  if(G[ny][nx]=='.'||(G[ny][nx]=='V' and G[y][x]!='V')){
	    que.push(make_pair(ny,nx));
	    G[ny][nx]='W'; 
	  }
	  if(ny==er and nx==ec){
	    cout<<"YES"<<endl;
	    return 0;
	  }
	}
	

      }
    }
  }

  cout<<"NO"<<endl;


  
  return 0;
}
