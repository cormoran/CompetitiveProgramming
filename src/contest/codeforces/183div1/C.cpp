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

const int N_max=1010000;

int main()
{
  int n,k;cin>>n>>k;
  vector<int> A(n);
  rep(i,n){
    cin>>A[i];
  }
  sort(all(A));
  vector<int> diff(N_max,0);
  vector<int> dsum(N_max,0);
  rep(i,n){
    for(int j=i+1;j<n;j++){
      diff[abs(A[i]-A[j])]++;
    }
  }

  rep(i,N_max){
    if(i==0)continue;
    for(int j=i;j<N_max;j+=i){
      dsum[i]+=diff[j];
    }
  }
  
  int mod = n-k-1;
  if(mod<=0)mod=1;
  const int reducible[5]={0,1,3,6,10};
  vector<int > used(N_max,-1);
  mod--;
  while(true){
    mod++;
    if(dsum[mod]>reducible[k]){
      continue; 
    }

    int cnt=0;

    rep(i,n){
      if(used[A[i]%mod]==mod){
        cnt++;
        if(cnt>k)break;
      }
      else{
        used[A[i]%mod]=mod;
      }
    }
    if(cnt<=k){
      cout<<mod<<endl;
      return 0;
    }
  }
  
  return 0;
}
