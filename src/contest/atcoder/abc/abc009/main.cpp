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

typedef long long ll;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)

int main()
{
  //input
  int K;
  ll M,i,j,k,l;
  cin>>K>>M;
  unsigned A[K],C[K][K]={},ans=0;
  rep(i,K)cin>>A[i];
  rep(i,K)cin>>C[0][i];
  rep(i,K-1)C[i+1][i]=~(unsigned)0;

  //solve

  //A(K+1)=[行列]A(k)
  //A(k+1)=[行列]^k A(1) 的な感じで
  //A(k+1)=[行列]^2^k A(1) + [行列]^2^m A(1) ... 的な感じで
  int log2m=ceil(log(M)/log(2));
  rep(i,log2m+1){
    if(((M-K)>>i)&1){
      unsigned temp=0;
      rep(j,K)temp^=C[0][j]&A[K-j-1];
      ans^=temp;
      //cout<<"i="<<i<<" ans="<<ans<<endl;
    }
    if(i<log2m){
      //Cを二乗(&と^で)
      unsigned C_[K][K];
      rep(j,K)rep(k,K)
	C_[j][k]=C[j][k];
      rep(j,K)rep(k,K){
	unsigned temp=0;//C[j][k]を求める
	rep(l,K)temp^=C_[j][l]&C_[l][k];
	C[j][k]=temp;
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
