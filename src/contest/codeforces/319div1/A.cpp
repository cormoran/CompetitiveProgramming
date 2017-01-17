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

vector<int> isprime;

void primefactorize(ll n){
  isprime.resize(n+1,1);
  isprime[0]=isprime[1]=0;
  rep(i,n+1){
    if(isprime[i]==0)continue;
    ll j=2;
    while(i*j<=n)isprime[i*j++]=0;   
  } 
}

int main()
{
  int n;
  cin>>n;
  primefactorize(n);
  vector<int> ans;
  ans.reserve(1001);
  rep(i,n+1){
    if(isprime[i]){
      int a=i,aa=i;
      while(a<=n){
        ans.push_back(a);
        a*=aa;
      }
    }
  }
  cout<<ans.size()<<endl;
  if(ans.size()>0){
    rep(i,(int)ans.size()-1){
      cout<<ans[i]<<" ";
    }
    cout<<ans.back()<<endl;
  }
  
  return 0;
}
