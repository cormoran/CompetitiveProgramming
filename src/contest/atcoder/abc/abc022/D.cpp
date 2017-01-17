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

const i32 INF=1<<30;//10E10

int main()
{

  int N;
  cin>>N;

  double sumDist[2]={};
  double avgX[2]={},avgY[2]={};
  rep(k,2){
    vector<int> Px(N),Py(N);

    rep(i,N){
      cin>>Px[i]>>Py[i];
      avgX[k]+=Px[i];
      avgY[k]+=Py[i];
    }
    avgX[k]/=N;
    avgY[k]/=N;
    rep(i,N){
      double dx=Px[i]-avgX[k];
      double dy=Py[i]-avgY[k];
      sumDist[k]+=dx*dx+dy*dy;
    }
  }

  if(sumDist[0]<sumDist[1])swap(sumDist[0],sumDist[1]);
  printf("%.9f\n",sqrt(sumDist[0]/sumDist[1]));
  
  return 0;
}
