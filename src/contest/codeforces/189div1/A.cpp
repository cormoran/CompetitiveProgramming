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
#include<bitset>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

const ll MOD =1000000000+7;

ll ModPow(ll a,ll n){
  if(n==0)return 1;
  if(n%2==1)return a*ModPow(a, n-1)%MOD;
  ll t=ModPow(a, n/2);
  return t*t%MOD;
}


//2^(2^b)
ll MEMO[101]={};
ll ModPow2(int b){
  if(b==0)return 2;
  if(MEMO[b])return MEMO[b];
  ll t=ModPow2(b-1);
  return MEMO[b]=t*t%MOD;
}

int main()
{

  
  

  string x;
  cin>>x;
  ll ans=0;
  reverse(all(x));


  
  rep(i,x.size()){
    if(x[i]=='1'){
      //ans+=pow(2,i)
      //ll t=ModPow(2, i);
      ll t= ModPow(2,2*i)%MOD* ModPow(2,x.size()-(i+1))%MOD;
      //cout<<t<<endl;
      ans=ans+t;
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
