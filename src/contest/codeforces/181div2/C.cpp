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

ll MOD =1000000000+7;

ll Cabc(ll n,ll a,ll b){
  ll ans=1;
  if(a<b)swap(a,b);
  for(ll i=n;i>a;i--){
    ans*=i;
    if(b>1 &&ans%b==0){
      ans/=b;
      b--;
    }
    ans%=MOD;
  }
  if(b!=1)assert(0);
  //cout<<ans<<endl;
  return ans;
}


inline bool is_greate(int a,int b,ll n){
  while(n){
    if(n%10!=a&&n%10!=b)return 0;
    n/=10;
  }
  return true;
}

int main()
{
  ll a,b,n;cin>>a>>b>>n;
  ll ans=0;
  rep(k,n+1){
    if(is_greate(a, b, a*k+b*(n-k))){
      ans=(ans+Cabc(n, k, n-k))%MOD;
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
