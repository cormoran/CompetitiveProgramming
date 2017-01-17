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
#define all(v) begin(v),end(v)

int main()
{
  ll n,k;cin>>n>>k;
  vector<ll> A(n);
  vector<bool> flg(n,true);
  rep(i,n)cin>>A[i];

  vector<ll> ans;
  ans.reserve(n);
  for(ll i=1;i<=n;i++){
    ll d=0;
    for(ll j=1;j<i;j++){
      if(!flg[j-1])continue;
      d+=A[j-1]*(j-1)-(n-i)*A[i-1];
    }
    //cout<<d<<" ";
    if(d<k){
      ans.push_back(i);
      flg[i-1]=false;
    }
    
  }
  //puts("");
  rep(i,ans.size()){
    cout<<ans[i]<<endl;
  }

  return 0;
}
