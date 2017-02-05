#include<bits/stdc++.h>
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
  int T,Tcnt=1;
  cin>>T;
  while(Tcnt<=T){
    int Smax;cin>>Smax;
    string shyness_str;cin>>shyness_str;
    vector<int> shyness(Smax+1);
    rep(i,shyness_str.size())shyness[i]=shyness_str[i]-'0';

    int ans=0,sum=0;
    rep(i,Smax+1){
      if(sum<i){
	ans+=i-sum;
	sum=i;
      }
      sum+=shyness[i];
    }

    printf("Case #%d: %d\n",Tcnt,ans);
    
    Tcnt++;
  }
  return 0;
}
