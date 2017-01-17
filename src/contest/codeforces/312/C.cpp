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

int MAX_DATA=-1;

void insert_pow2(map<int,pii> &M,int data,int cost){
  if(data>MAX_DATA ||data<=0)return;
  auto *p = &M[data];
  p->first++;
  p->second+=cost;
  insert_pow2(M, data*2, cost+1);
}
void insert_only(map<int,pii> &M,int data,int cost){
  if(data>MAX_DATA ||data<=0)return;
  auto *p = &M[data];
  p->first++;
  p->second+=cost;
}

int main()
{
  int n;cin>>n;
  vector<int> input(n);
  rep(i,n){
    cin>>input[i];
    MAX_DATA=max(MAX_DATA,input[i]);
  }
  map<int,pii> M;
  rep(i,n){
    int t=input[i],cost=0;
    insert_pow2(M, t, cost);
    while(t>0){
      cost++;
      if(t%2==1)insert_pow2(M, t/2, cost);
      else insert_only(M, t/2, cost);
      t/=2;
    }
  }
  int ans=1<<30;
  for(auto p : M){
    if(p.second.first==n)ans=min(ans,p.second.second);
  }
  cout<<ans<<endl;
  
  return 0;
}
