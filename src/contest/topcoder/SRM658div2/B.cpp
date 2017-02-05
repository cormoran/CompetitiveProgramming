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

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

class MutaliskEasy{
public:

  bool is_end(vector<int> &v){
    for(int i : v){
      if(i>0)return false;
    }
    return true;
  }

  int DP[61][61][61]={};
  int rec(int a,int b,int c){
    if(a<0)a=0;
    if(b<0)b=0;
    if(c<0)c=0;
    if(DP[a][b][c]>0)return DP[a][b][c];
    if(a==0 and b==0 and c==0) return 0;
    int ans=1<<30;
    ans=min(ans,rec(a-9,b-3,c-1));
    ans=min(ans,rec(a-9,b-1,c-3));
    ans=min(ans,rec(a-3,b-9,c-1));
    ans=min(ans,rec(a-3,b-1,c-9));
    ans=min(ans,rec(a-1,b-9,c-3));
    ans=min(ans,rec(a-1,b-3,c-9));
    return DP[a][b][c]=ans+1;
  }
  
  int minimalAttacks(vector <int> x){
    while(x.size()<3)x.push_back(0);
    return rec(x[0],x[1],x[2]);
  }
  
  
};
