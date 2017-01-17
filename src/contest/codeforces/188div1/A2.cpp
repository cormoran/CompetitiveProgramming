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

  if(x<m && y<m && x+y<=0 && x+2*y<=0 && 2*x+y<=0){
    cout<<-1<<endl;
    return 0;
  }
  
  while(x<m and y<m){
    if(x<=y)x=x+y;
    else y=x+y;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
