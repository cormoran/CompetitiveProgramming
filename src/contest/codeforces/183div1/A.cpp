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
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

int main()
{
  int n;cin>>n;
  if(n%2==0){
    cout<<-1<<endl;
  }
  else{
    vector<int> f(n),s(n),t(n);
    rep(i,n){
      f[i]=i;
      t[i]=(n+(n+1)/2-i)%n;
      s[i]=(t[i]+n-f[i])%n;
    }
    rep(i,n)printf("%d%c",f[i],(i==n-1?'\n':' '));
    rep(i,n)printf("%d%c",s[i],(i==n-1?'\n':' '));
    rep(i,n)printf("%d%c",t[i],(i==n-1?'\n':' '));
  }
  return 0;
}
