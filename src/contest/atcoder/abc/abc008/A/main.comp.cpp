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


int play(vector<int> &C,vector<int> &Cn,int N){

  vector<int> coin(N,1);
  for(int i=0;i<N;i++){

    
  }
  
}


int main(){

  int N;
  cin>>N;
  vector<int> C(N);
  vector<int> Cn(N
		 );

  int a[10];
  
  
  rep(i,N){
    Cn[i]=i;
  }
  
  rep(i,N)cin>>C[i];

  sort(all(C));


  
  do{

    rep(i,N){
      cout<<C[ Cn[i] ]<<" ";
    }
    cout<<endl;
    
  }while(next_permutation( Cn.begin() , Cn.end() ));

  
  
  
  
  return 0;
}
