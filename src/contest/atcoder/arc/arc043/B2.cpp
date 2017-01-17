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
const int MOD = 1000000000+7;
const int N_MAX = 100005;

int range_sum[4][N_MAX]={};

int main()
{
  int N;
  cin>>N;
  vector<int> D(N);
  vector<int> Nxt(N);
  rep(i,N)scanf("%d",&D[i]);
  sort(all(D));
  rep(i,N){
    int d=distance(begin(D),lower_bound(all(D),D[i]*2));
    Nxt[i]=max(i+1,(ll)d);
    range_sum[0][i]=N-i;

  }
  /*
  rep(i,N)cout<<Nxt[i]<<" ";
  puts("");
  rep(i,N)cout<<range_sum[0][i]<<" ";
  puts("");
  */
  rep(i,4)range_sum[i][N]=0;
  
  for(int k=1;k<4;k++){
    for(int i=N-1;i>=0;i--){
      range_sum[k][i]=range_sum[k][i+1]+range_sum[k-1][Nxt[i]];
      range_sum[k][i]%=MOD;
    }
    /*
    rep(i,N)cout<<range_sum[k][i]<<" ";
    puts("");
    */
  }
  cout<<range_sum[3][0]<<endl;
  
  return 0;
}
