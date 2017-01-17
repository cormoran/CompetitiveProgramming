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
  int n,c;
  cin>>n>>c;
  vector<int> a(n);
  rep(i,n)cin>>a[i];

  int ans=1<<30;
  
  for(int i=1;i<=10;i++){
    for(int j=1;j<=10;j++){
      if(i==j)continue;
      int tmp=0;
      rep(k,n){
	if(a[k]!=(k%2 ? i:j)){
	  tmp++;
	}
      }
      ans=min(ans,tmp*c);
    }
  }
  cout<<ans<<endl;
  
  
  return 0;
}
