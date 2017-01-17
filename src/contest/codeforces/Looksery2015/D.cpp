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
  vector<vector<int> > P(h,vector<int>(w));
  rep(i,h){
    string s;cin>>s;
    rep(j,w)P[i][j]=( s[j]=='W'?1:-1);
  }
  vector<vector<int> > S(h,vector<int>(w,0));
  int ans=0;
  for(int i=h-1;i>=0;i--){
    for(int j=w-1;j>=0;j--){
      if(S[i][j]!=0 and i>0)S[i-1][j]+=S[i][j];
      if(j<w-1)S[i][j]+=S[i][j+1];
      if(S[i][j]!=P[i][j]){
        int diff=P[i][j]-S[i][j];
        S[i][j]+=diff;
        if(i>0)S[i-1][j]+=diff;
        
        ans++;
        //cout<<i<<" "<<j<<" "<<diff<<" "<<S[i][j]<<endl;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
