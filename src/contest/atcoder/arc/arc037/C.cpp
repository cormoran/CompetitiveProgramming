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

int main()
{

  
  i64 N,K;
  cin>>N>>K;
  vector<i64> a(N),b(N);
  rep(i,N)cin>>a[i];
  rep(i,N)cin>>b[i];

  vector<i64> V(N*N);
  int cnt=0;
  sort(all(a));
  sort(all(b));
  rep(i,N){rep(j,N){
    V[cnt++]=a[i]*b[j];
    std::cout << V[cnt-1] << " ";
  }
    puts("");
  }

  
  sort(all(V));
  cout<<V[K-1]<<endl;
  return 0;
}
