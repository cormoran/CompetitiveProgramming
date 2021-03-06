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

#define N_MAX 100 +10
#define W_MAX 10000 +10
int main()
{
  ios::sync_with_stdio(false);
  int N,W;
  cin >> N >> W;
  vector<int> value(N+1),weight(N+1);
  for(int i=1;i<=N;i++){
    cin >> value[i] >> weight[i];
  }
  int DP[N_MAX][W_MAX]={};
  bool ITEM[N_MAX][W_MAX]={};
  for(int n=1;n<=N;n++){
    rep(w,W+1){
      if(weight[n]<=w){
        if(DP[n][w-weight[n]]+value[n] > DP[n-1][w]){
          DP[n][w] = DP[n][w-weight[n]]+value[n];
          ITEM[n][w] = true;
        }else{
          DP[n][w] = DP[n-1][w];
        }
      }else{
        DP[n][w]=DP[n-1][w];
      }
    }
  }
  cout<<DP[N][W]<<endl;

  //組み合わせ再現
  {
    cout<<"Used Items : index(1toN) , count"<<endl;
    int w=W;
    for(int n=N;n>0;n--){
      int cnt=0;
      while(ITEM[n][w]){
        cnt++;
        w-=weight[n];
      }
      cout<<n<<" "<<cnt<<endl;
    }
  }
  
  return 0;
}

/**
   重複ありの場合 nをk個で
   for(k=0;k< ? ;k++)的にすると O(NW k ) (?) となるが
   上のようにnを1つ加えるかどうかでやったあとの場所から飛んでくるとO(NW)でいける
 */
