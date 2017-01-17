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
  int N;
  cin>>N;
  string S,T;
  cin>>S>>T;
  int ans=0;
  rep(i,N){
    int a=S[i]-'0';
    int b=T[i]-'0';
    
    ans+=min((a-b+10)%10,(b-a+10)%10);

    
  }

  cout<<ans<<endl;
  
  return 0;
}
