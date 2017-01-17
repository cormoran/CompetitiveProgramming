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
#include<map>
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

typedef pair<int,int> pii;
bool can_re(pii nc,map<pii,bool> &mp){
  int dx[5]={1,0,-1,1,-1};
  int dy[5]={1,1,1,0,0};
  bool ise[5]={};
  rep(dir,5){
    pii nxy=make_pair(nc.first+dy[dir],nc.second+dx[dir]);
    auto itr=mp.find(nxy);
    if(itr!=mp.end() && (*itr).second>=0)ise[dir]=true;
  }

  if((ise[3]and!ise[0])or(ise[4]and!ise[2])or(!ise[0]&&!ise[1]&&!ise[2])){
    return true;
  }
  
  return false;
}

i64 modpow(i64 x,i64 y){
  i64 ans=1;
  rep(i,y){
    ans=ans*x%1000000009L;
  }
  return ans;
}

int main()
{

  int m;cin>>m;
  vector<pii> cubes(m);
  map<pii,bool> mp;
  rep(i,m){
    int x,y;cin>>x>>y;
    cubes[i]=make_pair(y,x);
    mp[cubes[i]]=i;
  }

  vector<char> canrem(m,0);
  priority_queue<int,vector<int>,greater<int> > que;


  rep(i,m){
    pii nc=cubes[i];
    bool flg=can_re(nc,mp);
    if(flg){
      que.push(i);
      canrem[i]=1;
    }
  }

  int left=m-1;
  i64 ans=0;
  while(!que.empty()){
    int ncn =que.top();que.pop();
    if(canrem[ncn]==0)continue;
    ans+=left*modpow(m,left);
    ans%=1000000009;

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    mp[cubes[ncn]]=-1;
    rep(dir,4){
      int nx=cubes[ncn].second+dx[dir];
      int ny=cubes[ncn].first+dy[dir];
      pii nxy=make_pair(ny,nx);
      bool flg=can_re(nxy,mp);

      if(flg==true and )
      
    }
    
    
  }

  
  return 0;
}
