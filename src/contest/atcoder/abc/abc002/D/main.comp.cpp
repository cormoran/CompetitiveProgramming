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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


int main()
{
  int n,m;
  cin>>n>>m;
  bool e[12][12]={};

  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--;y--;
    e[x][y]=e[y][x]=true;
  }
  rep(i,n)e[i][i]=true;
  int ans=0;
  repeat(bit,1,pow(2,n)){
    bool flg=true;
    rep(i,n){
      if(bit &(1<<i)){
        rep(j,n){
          if(bit&(1<<j)){
            if(!e[i][j])flg=false;
          }
        }
      }
    }
    if(flg)ans=max(ans,__builtin_popcount(bit));
  }
  
  cout<<ans<<endl;
  return 0;
}
