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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

#define RECT 100

int main()
{
  int n,t;
  cin>>n>>t;
  vector<int> X(t),Y(t);
  rep(i,t)cin>>X[i]>>Y[i];

  vector< vector<int>> MEMO(RECT,vector<int>(RECT,0));
  //map<pii,int> MEMO;

  priority_queue<pair<int,pii>> que;
  if(n>=4)que.push(make_pair(0,make_pair(0,0)));
  MEMO[0][0]=n;
  const int dx[4]={0,1,0,-1};
  const int dy[4]={-1,0,1,0};

  while(!que.empty()){
    pair<int,pii> s = que.top();que.pop();
    int x=s.second.first;
    int y=s.second.second;
    int mv=MEMO[x][y]/4;
    MEMO[x][y]-=mv*4;
    rep(dir,4){
      int nx=x+dx[dir];
      int ny=y+dy[dir];
      assert(nx<RECT && ny<RECT);
      
      if(nx<0 || ny<0)continue;
      if(ny>nx)continue;
      
      int t=mv;
      if(x==1 && nx==0)t*=2;
      else if(y==1 && ny==0)t*=2;
      
      if(ny==nx && abs(y-x)==1 )t*=2;
      t+=MEMO[nx][ny];
      MEMO[nx][ny]=t;
      if(t>=4)que.push(make_pair(s.first+1,make_pair(nx,ny)));
    }
  }


  rep(i,t){
    Y[i]=abs(Y[i]);
    X[i]=abs(X[i]);

    if(X[i]>=RECT ||Y[i]>=RECT){
      cout<<0<<endl;
      continue;
    }
    
    if(Y[i] > X[i])swap(X[i],Y[i]);
    cout<<MEMO[X[i]][Y[i]]<<endl;    
  }




  /*
      
#define XX 10
  char *str[]={"\033[31m0\033[39m",
               "\033[32m1\033[39m",
               "\033[33m2\033[39m",
               "\033[34m3\033[39m"};
  for(int i=0;i<=XX;i++){

    for(int j=0;j<=XX;j++){
      int ii=i,jj=j;
      //if(ii<jj)swap(ii,jj);
      cout << str[MEMO[make_pair(ii,jj)]] << " ";
    }
    puts("");

  }
  */
  return 0;
}
