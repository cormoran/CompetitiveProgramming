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

typedef long long int64;typedef int i32;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int64 B;

// -> n^r %B
int64 modpow(int64 n,int64 r){
  assert(r>=0);
  if(r==0)return 1;
  int64 halfpow=modpow(n, r/2)%B;
  if(r%2==0)return (halfpow*halfpow)%B;  
  else return ((halfpow*halfpow)%B*n)%B;
}

inline int64 ilog10(int64 n){
  return (int64)log10(n); 
}

inline int64 getDigit10(int64 n){
  if(n==0)return 1;
  return ilog10(n)+1;
}

int main()
{
  
  //input
  int64 N;
  cin>>N;
  vector<int64> a(N),L(N);
  rep(i,N)cin>>a[i]>>L[i];
  cin>>B;

  //solve
  int64 ans=0;
  int64 sumdigit=0;//10^sumdigit 
  rep(i,N){
    sumdigit+=L[i]*getDigit10(a[i]);
  }
  
  rep(i,N){
    sumdigit-=L[i]*getDigit10(a[i]);
    
    vector<int64> doubling( log2(L[i])+1 );
    doubling[0]=a[i]%B;
    repeat(j,1,doubling.size()){
      doubling[j]=doubling[j-1]*( modpow(10, getDigit10(a[i])*pow(2,j-1) ) );
      doubling[j]%=B;
      doubling[j]+=doubling[j-1];
      doubling[j]%=B;
      //printf("doubling[%lld] = %lld\n",j,doubling[j]);
    }

    int64 partans=0;
    int64 pownum=0;
    rep(j,doubling.size()){
      if(L[i]&(1LL<<j)){
	partans+=(doubling[j]*modpow(10,getDigit10(a[i])*pownum))%B;
	partans%=B;
	pownum+= 1LL<<j;
      }
    }
    partans*=modpow(10,sumdigit);
    partans%=B;
    
    ans=(ans+partans)%B;
  }

  cout<<ans<<endl;
  
  return 0;
}
