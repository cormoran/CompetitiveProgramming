#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
//#include<>
using namespace std;


int main(){
  long N,W;
  long v[101],w[101];
  cin>>N>>W;
  for(long i=0;i<N;i++)cin>>v[i]>>w[i];
  
  long dp[101][10001]={};//dp[i][j] := i番目の品物までのうち重さの総和がW以内で選んだ最大価値
  for(long i=1;i<=N;i++){
    for(long j=0;j<=W;j++)
      //何かを取り返してi番目を入れられるなら試してみる。
      //全部取り出してしまうこともある
      if(j-w[i-1]>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
      //入れる事が出来ないならそのままi-1までの場合を適用。
      else dp[i][j]=dp[i-1][j];
  }
  cout<<dp[N][W]<<endl;
  return 0;
}
