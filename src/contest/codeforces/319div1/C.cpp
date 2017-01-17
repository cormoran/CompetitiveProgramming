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
#define all(v) v.begin(),v.end()

struct P{
  int x,y;
  int num;
};



bool comp_x(const P &P1,const P &P2){
  return P1.x<=P2.x;
}
bool comp_y(const P &P1,const P &P2){
  return P1.y<=P2.y;
}

void split(vector<P> &points,int l,int r,int dep){
  //cout<<l<<" "<<r<<endl;
  if(l+1>=r)return;
  if(dep%2)sort(begin(points)+l,begin(points)+r,comp_x);
  else sort(begin(points)+l,begin(points)+r,comp_y);
  split(points,l,(l+r)/2,dep+1);
  split(points,(l+r)/2+1,r,dep+1);
};

int main()
{
  int n;
  cin>>n;
  vector<P> V(n);
  rep(i,n){
    scanf("%d%d",&V[i].x,&V[i].y);
    V[i].num=i+1;
  }

  rep(i,2){
    split(V,n/2*i,n/2*i-1,0);
  }
  
  rep(i,(int)V.size()-1){
    cout<<V[i].num<<" ";
  }
  cout<<V.back().num<<endl;
  return 0;
}
