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
  ll x,y,m;
  cin>>x>>y>>m;
  ll ans=0;

  if(x>=m || y>=m){
    cout<<0<<endl;
    return 0;
  }
  
  if(x<=0 and y<=0){
    cout<<-1<<endl;
    return 0;
  }

  if(x>y)swap(x,y);
  if(x<0){
    ll n=min(floor(m-x/y),ceil(-x/y));
    ans+=n;
    x+=n*y;
  }
  
  while(x<m and y<m){
    if(x<=y)x+=y;
    else y+=x;
    ans++;
  }
  
  cout<<ans<<endl;
  return 0;
}
