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
#include<unordered_map>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

const int INF = 1<<30;

struct Circle{
  int x,y,r,c;
};


bool is_intersect(const Circle &c1,const Circle &c2){
  int dist2=pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2);
  if(dist2>=pow(c1.r+c2.r,2))return false;
  return true;
}

int n;
vector<Circle> C;
vector< vector<bool> > is_I;

unordered_map<unsigned int,int> MEMO;


int rec(unsigned int bits){
  if(MEMO.find(bits)!=MEMO.end())return MEMO[bits];
  
  int ret=INF;
  vector<int> tops[4];
  rep(i,n){
    if(bits & (1<<i)){
      rep(j,i){
        if(bits & (1<<j)){
          if(is_I[i][j])goto BREAK;
        }
      }
      tops[C[i].c-1].push_back(i);
   BREAK:;
    }
  }

  rep(i,4){
    rep(j,tops[i].size()){
      rep(k,j){
        ret = min(ret,rec(bits & ~((1<<tops[i][j]) | (1<<tops[i][k]))));
      }
    }
  }

  if(ret==INF){
    ret=__builtin_popcount(bits);
  }
  return MEMO[bits]=ret;
}

int main()
{
  while(true){
    C.clear();
    is_I.clear();
    MEMO.clear();
    
    cin>>n;
    if(n==0)break;
    C.resize(n);
    is_I.resize(n,vector<bool>(n,false));
    
    rep(i,n){
      int x,y,r,c;
      cin>>x>>y>>r>>c;
      C[i]=(Circle){x,y,r,c};
    }
    rep(i,n){
      rep(j,n){
        is_I[i][j]=is_intersect(C[i], C[j]);
      }
    }
    unsigned int bits=0;
    rep(i,n)bits|=1<<i;
    cout<<n-rec(bits)<<endl;
  }
  return 0;
}
