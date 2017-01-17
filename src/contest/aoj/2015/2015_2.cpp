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
typedef int int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)
 
 
 
class Binary_Indexed_Tree
{
private:
  vector<ll> bit;
public:
  Binary_Indexed_Tree(ll n)
  {
    bit.resize(n+1,0);
  }
  //index 0 to i ???????????????
  ll sum(ll i)
  {
    ll s=0;
    while(i>0){
      s+=bit[i];
      i-=i& (-i);//i& -i ???i???????°?1bit  <- 2^k?????????
    }
    return s;
  }  
  //index i to j ??????
  ll sum(ll i,ll j)
  {
    return sum(j)-sum(i-1);
  }
  //index i ??? x ?????????
  void add(ll i,ll x){
    while(i<bit.size()){
      bit[i]+=x;
      i+=i& (-i);
    }
  }
};
 
int main()
{
 
  while(true){
    ll N,M;
    cin>>N>>M;
    if(N==0 and M==0)break;
    Binary_Indexed_Tree H(N),W(M);
 
    rep(i,N){
      ll in;cin>>in;
      H.add(i+1, in);
    }
     
    rep(i,M){
      ll in;cin>>in;
      W.add(i+1, in);
    }
 
     
    map<ll,ll> lens_w,lens_h;
    rep(i,N+1){
      rep(j,i){
        ll len=H.sum(j+1, i);
        lens_h[len]++;
      }
    }
    rep(i,M+1){
      rep(j,i){
        lens_w[W.sum(j+1, i)]++;
      }
    }
 
 
 
    ll ans=0;
    for(auto num : lens_h){
      if(num.first==0)continue;
      ans+=num.second*lens_w[num.first];
    }
    cout<<ans<<endl;
  }
   
  return 0;
}
