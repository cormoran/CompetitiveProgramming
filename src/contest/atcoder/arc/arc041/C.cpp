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
  ll N,L;
  cin>>N>>L;
  vector< pair<ll,char> > G(N);
  rep(n,N){
    cin>>G[n].first>>G[n].second;
  }
  ll ans=0;
  ll idx=0;
  while(idx<N){
    //Rの飛ぶ数
    ll idx_sub=idx;
    while(idx_sub<N && G[idx_sub].second=='R')idx_sub++;
    ll lst_space = (idx_sub==N ? L : G[idx_sub].first-1);
    ll lst_R = idx_sub-1;
    ll R_sum=0;
    //cout<<lst_space<<" "<<lst_R<<endl;
    if(idx<=lst_R){//Rが存在する
      //R : idx to lst_R
      ll R_num=0;
      for(ll i=lst_R;i>=idx;i--){
        R_sum+=lst_space-G[i].first-R_num;
        R_num++;
      }
    }
    idx=idx_sub;
    //Lの飛ぶ数
    ll fst_space = (lst_R<0 ? 1 : G[lst_R].first+1 );
    ll L_sum=0;
    ll L_num=0;
    while(idx<N && G[idx].second=='L'){
      L_sum+=G[idx].first-fst_space - L_num;
      L_num++;
      ++idx;
    }
    ans+=max(L_sum,R_sum);
  }
  cout<<ans<<endl;
  
  return 0;
}
