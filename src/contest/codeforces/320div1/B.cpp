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
typedef unsigned long long ull;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(ll)(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
  cin.sync_with_stdio(false);
  ll n,k,x;
  cin>>n>>k>>x;
  vector<int> v(n);
  rep(i,n)cin>>v[i];
  sort(all(v));
  reverse(all(v));
  ll m =v[0];
  v[0]=0;
  rep(i,k)m*=x;
  ll ans=0;
  ans|=m;
  rep(i,n)ans|=v[i];
  cout<<ans<<endl;
  return 0;
}
