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
/*
struct state{
  int t;
  int x,y;
  bool operator<(const state &other)const
  {
    return t<other.t;
  }
  }*/

int main()
{
  int n,t;
  cin>>n>>t;
  vector<int> X(t),Y(t);
  rep(i,t)cin>>X[i]>>Y[i];
  map<pii,int> MEMO;

  priority_queue<pair<int,pii>> que;
  if(n>=4)que.push(make_pair(0,make_pair(0,0)));
  MEMO[make_pair(0,0)]=n;
  const int dx[4]={0,1,0,-1};
  const int dy[4]={-1,0,1,0};
  while(!que.empty()){
    pair<int,pii> s = que.top();que.pop();
    int mv=MEMO[s.second]/4;
    MEMO[s.second]-=mv*4;
    
    rep(dir,4){
      int nx=s.second.first+dx[dir];
      int ny=s.second.second+dy[dir];
      int t=MEMO[make_pair(nx,ny)]+mv;
      MEMO[make_pair(nx,ny)]=t;
      if(t>=4)que.push(make_pair(s.first+1,make_pair(nx,ny)));
    }
  }


  #define XX 10
  char *str[]={"\033[31m0\033[39m",
               "\033[32m1\033[39m",
               "\033[33m2\033[39m",
               "\033[34m3\033[39m"};
  for(int i=0;i<=XX;i++){

    for(int j=0;j<=XX;j++){
      cout << str[MEMO[make_pair(i,j)]] << " ";
    }
    puts("");

  }
  

  return 0;


  
  rep(i,t){
    cout<<MEMO[make_pair(X[i],Y[i])]<<endl;
  }
  
  return 0;
}
