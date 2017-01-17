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
  int h,w;
  cin>>h>>w;
  vector< string > P(h);
  rep(i,h)cin>>P[i];
  int ans=0;
  rep(i,h-1){
    rep(j,w-1){
      bool face[4]={};
      char f[4]={'f','a','c','e'};
      rep(k,2){
        rep(l,2){
          rep(m,4){
            if(P[i+k][j+l]==f[m])face[m]=true;
          }
        }
      }
      bool flg=true;
      rep(m,4)flg&=face[m];
      if(flg)ans++;
    }
  }

  cout<<ans<<endl;
  return 0;
}
