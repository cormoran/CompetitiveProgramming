#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;

#define repeat(i,j,k) for(i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(i=(j)-1;i>=k;i--)
#define rep(i,j) for(i=0;i<j;i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E1

int W,N,K;
int A[51],B[51];
int dp[51][10001][51]={};
int rec(int index,int w_,int k_)
{
  int ans=0;
  if(dp[index][w_][k_])return dp[index][w_][k_];
  if(k_>=K || index>=N || w_+A[index]>W)return ans;
  return dp[index][w_][k_]= max(rec(index+1,w_+A[index],k_+1)+B[index],rec(index+1,w_,k_));

}

int main()
{
  cin>>W>>N>>K;
  int i,j,k;
  rep(i,N){
    cin>>A[i]>>B[i];
      
  }
  cout<<rec(0,0,0)<<endl;

  return 0;
  
}
