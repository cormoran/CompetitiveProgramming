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

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<bool>> B(n,vector<bool>(n,false));
  rep(i,m){
    int x,y;
    cin>>x>>y;
    B[x-1][y-1]=true;
  }
  int ans=0;
  rep(i,n){
    if(i==0||i==n-1)continue;
    bool flg[2]={};
    rep(j,n){
      flg[0]|=B[i][j];
      flg[1]|=B[j][i];
    }

    if(n%2==1 && i==n/2){
      if(!flg[0])ans++;
      else if(!flg[1])ans++;
    }else{
      if(!flg[0])ans++;
      if(!flg[1])ans++;
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
