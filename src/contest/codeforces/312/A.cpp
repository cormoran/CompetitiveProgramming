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
typedef pair<int,int> pii;

int main()
{
  int n;
  cin>>n;

  vector<pii> T_p,T_m;
  T_p.reserve(n);
  T_m.reserve(n);
  rep(i,n){
    int x,app;cin>>x>>app;
    if(x>0){
      T_p.push_back(make_pair(x, app));
    }
    else{
      T_m.push_back(make_pair(x,app));
    }
  }
  sort(all(T_p));
  sort(all(T_m));reverse(all(T_m));
  
  int min_num = min(T_p.size(),T_m.size());
  long ans=0;
  rep(i,min_num){
    ans+=T_p[i].second;
    ans+=T_m[i].second;
  }
  if(T_p.size()>min_num)ans+=T_p[min_num].second;
  else if(T_m.size()>min_num)ans+=T_m[min_num].second;

  cout<<ans<<endl;
  
  return 0;
}
