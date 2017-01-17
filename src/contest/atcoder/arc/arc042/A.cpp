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
  int N,M;
  cin>>N>>M;
  vector<int> W(M);
  rep(i,M)scanf("%d",&W[i]);
  reverse(all(W));
  vector<bool> flg(N,false);
  rep(i,M){
    if(!flg[W[i]-1]){
      flg[W[i]-1]=true;
      cout<<W[i]<<endl;
    }
  }
  rep(i,N){
    if(!flg[i]){
      cout<<i+1<<endl;
    }
  }
  
  return 0;
}
