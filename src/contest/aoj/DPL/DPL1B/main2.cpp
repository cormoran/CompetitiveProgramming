/* knapsack Problem ナップサック問題 メモリ節約版*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define W_MAX 10000 +10
int main()
{
  //input
  ios::sync_with_stdio(false);
  int N,W; cin >> N >> W;
  vector<int> value(N+1),weight(N+1);
  for(int i=1;i<=N;i++){
    cin >> value[i] >> weight[i];
  }
  //solve
  int DP[W_MAX]={};
  for(int n=1;n<=N;n++){
    for(int w=W;w-weight[n]>=0;w--){
      DP[w]=max(DP[w],DP[w-weight[n]]+value[n]);
    }
  }
  cout<<DP[W]<<endl;
  
  return 0;
}

/**
   DP[n][w]は DP[n-1][*]しか参照しない && DP[n][w]は DP[n-1][w-k] (k>0)しか参照しない
   よってwを減少方向に回すことで配列を使いまわせる
 */
