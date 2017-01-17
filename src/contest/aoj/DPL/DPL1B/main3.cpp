/* knapsack Problem ナップサック問題 組み合わせの復元*/
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,j) for(int (i)=0;(i)<(j);(i)++)


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
        if( DP[n-1][w-weight[n]]+value[n] > DP[n-1][w]){
          DP[n][w] = DP[n-1][w-weight[n]]+value[n];
          ITEM[n][w]=true;
        }else{
          DP[n][w] = DP[n-1][w];
          //(ITEM[n][w]=false;)
        }
      }else{
        DP[n][w]=DP[n-1][w];
        //(ITEM[n][w]=false;)
      }
    }
  }
  cout<<"max value " << DP[N][W] << endl;

  //再現
  {
    cout<<"used items (1toN): ";
    int w=W;
    for(int n=N;n>0;n--){
      if(ITEM[n][w]){
        cout<<n<<" ";
        w-=weight[n];
      }
    }
    putchar('\n');
  }
  
  return 0;
}


/**
   DP[n][w] = max( DP[n-1][w] , DP[n-1][w-weight[n]+value[n] )
   なのでテーブルをどっちからきたかでnを使ったかどうかがわかる
   上では斜めからきた場合(nを使う場合)をtrueとしている
 */
