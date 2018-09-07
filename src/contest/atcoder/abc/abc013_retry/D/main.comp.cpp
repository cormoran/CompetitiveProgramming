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

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10




int main()
{
  int N,M,D;
  cin>>N>>M>>D;
  vector<int> A(M);
  rep(i,M)cin>>A[i];

  vector<int> F(N);
  rep(i,N)F[i]=i+1;

  rep(i,M){
    //A[i]=1toN
    swap(F[A[M-i-1]-1],F[A[M-i-1]]);
  }

  vector<int> ansF(N);
  //列について
    rep(i,N){
      //繰り返し
      int tmp=i+1;
      rep(j,N){
	tmp=F[tmp-1];

	if(j==D-1){
	  ansF[i]=tmp;
	  break;
	}
	
	if(tmp==i+1){
	  int do_cnt=D%(j+1);
	  ansF[i]=i+1;
	  rep(k,do_cnt){
	    ansF[i]=F[ansF[i]-1];
	  }
	  break;
	}
      
      }
    }

  
  rep(i,N){
    printf("%d\n",ansF[i]);
  }

  
  return 0;
}
