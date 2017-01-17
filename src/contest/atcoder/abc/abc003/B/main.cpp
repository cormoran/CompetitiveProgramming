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
//typedef int64_t i64;typedef int32_t i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10
char ok[]={'a','t','c','o','d','e','r','@'};

bool canrep(char c){
  rep(i,8){
    if(c==ok[i])return true;
  }
  return false;
}

int main()
{
  string s,t;
  cin>>s>>t;
  rep(i,s.size()){
    if((s[i]=='@' and canrep(t[i]))||(t[i]=='@' and canrep(s[i]))||s[i]==t[i]);
    else {
      cout<<"You will lose"<<endl;
      return 0;
    }
  }
  cout<<"You can win"<<endl;
  return 0;
}
