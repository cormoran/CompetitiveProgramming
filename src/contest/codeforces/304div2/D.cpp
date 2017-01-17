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
//#include<cstdint>
using namespace std;

typedef long long int64;typedef int int32;
typedef long long ll;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

vector<int> isprime;
vector<int> primes;
//n以下の素数列挙
void primefactorize(int64 n){
  isprime.resize(n+1,1);
  isprime[0]=isprime[1]=0;
  rep(i,n+1){
    if(isprime[i]==0)continue;
    int64 j=2;
    while(i*j<=n)isprime[i*j++]=0;
    primes.push_back(i);
  }
}

int main()
{
  int n;
  cin>>n;
  primefactorize(sqrt(5000000)+10);
  vector<int> DP(5000001,0);
  DP[0]=0;DP[1]=0;
  rep(i,5000001){
    if(i==0||i==1)continue;
    int nn=i,cnt=0,pos=0;
    int sq=ceil(sqrt(nn));
    while(nn>1 and primes[pos]<=sq){
      while(nn%primes[pos]==0){
        nn/=primes[pos];
        if(nn<=i){
          cnt+=DP[nn]-DP[nn-1];
          nn=1;
        }
        cnt++;
      }
      pos++;
    }
    if(nn!=1){
      cnt++;
    }
    DP[i]=DP[i-1]+cnt;
  }
  
  rep(i,n){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",DP[a]-DP[b]);
  }
  
  return 0;
}
