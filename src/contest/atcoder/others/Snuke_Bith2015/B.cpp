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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


int main()
{
  int k;
  string s;
  cin>>k>>s;
  typedef pair<int,int> pii;
  vector<pii> cost;
  cost.reserve(s.size());

  int cnt=0;
  rep(i,s.size()){
    if(cnt==k)break;
    if(s[i]=='s'){
      if(i<s.size()-1 && s[i+1]-s[i]<0){
        s[i]='0';
        cnt++;
      }
    }
  }

  for(int i=s.size()-1;i>=0;i--){
    if(cnt==k)break;
    if(s[i]=='s'){
        s[i]='0';
        cnt++;
    }
  }

  rep(i,s.size()){
    if(s[i]!='0')putchar(s[i]);
  }
  puts("");
  return 0;
}
