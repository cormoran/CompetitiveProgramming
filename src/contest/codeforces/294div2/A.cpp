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
#include<cstdint>
#include<map>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;
typedef int64_t int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

int main()
{
  string s[8];
  rep(i,8){
    cin>>s[i];
  }

  map<char,int> po;
  po['q']=9;
  po['r']=5;
  po['b']=3;
  po['n']=3;
  po['p']=1;
  po['k']=0;
  po['Q']=-9;
  po['R']=-5;
  po['B']=-3;
  po['N']=-3;
  po['P']=-1;
  po['K']=0;

  int sum=0;
  rep(i,8)rep(j,8){
    sum+=po[s[i][j]];
  }

  if(sum==0)
    cout<<"Draw"<<endl;
  else if(sum>0)
    cout<<"Black"<<endl;
  else
    cout<<"White"<<endl;
  
  return 0;
}













