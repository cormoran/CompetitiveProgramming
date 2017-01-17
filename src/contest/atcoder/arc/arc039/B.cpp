#include<bits/stdc++.h>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10
const int MOD=1000000007;

int Memo[601][501]={};

int Combination(int n,int k){
  if(Memo[n][k]>0)return Memo[n][k];
  if(k==0||k==n)
    return 1;
  else
    return Memo[n][k]=(Combination(n-1,k-1)+Combination(n-1,k))%MOD;
}


int main()
{
  int N,K;
  cin>>N>>K;

  if(K<N){
    cout<<Combination(N+K-1, K)<<endl;
    return 0;
  }
  
  int a=K%N;

  cout<<Combination(N, a)<<endl;
  
  
  return 0;
}
