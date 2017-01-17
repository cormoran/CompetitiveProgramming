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
typedef pair<int,int> pii;

double dist_pl(pii l1,pii l0,int px,int py){
  int dx=l1.first-l0.first;
  int dy=l1.second-l0.second;
  int c=dx*l0.second-dy*l0.first;
  return (double)abs(dx*py-dy*px-c)/sqrt(dx*dx+dy*dy);
}

int main()
{
  int x,y;cin>>x>>y;
  int N;cin>>N;
  vector<pii> P(N);//x,y
  rep(i,N)cin>>P[i].first>>P[i].second;
  double ans=1<<30;
  rep(i,N){
    ans=min(ans,dist_pl(P[i], P[(i+1)%N], x, y));
  }
  printf("%.10f\n",ans);
  return 0;
}
