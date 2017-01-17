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

int H,W,s;
vector< vector<int> > G;

pii MEMO[32][32][32][32];//<グループ数、予備力>

int ALLSUM[32][32];

pii rec(int y,int x,int h,int w){
  if(MEMO[y][x][h][w].first!=0)return MEMO[y][x][h][w];

  int rect_sum=ALLSUM[y+h-1][x+w-1];
  if(y>0 && x>0)rect_sum+=ALLSUM[y-1][x-1];
  if(y>0)rect_sum-=ALLSUM[y-1][x+w-1];
  if(x>0)rect_sum-=ALLSUM[y+h-1][x-1];
  if(s<ALLSUM[H-1][W-1]-rect_sum)return make_pair(-1,-1);
  
  if(w==1&& h==1){
    return make_pair(1,s-ALLSUM[H-1][W-1]+G[y][x]);
  }
  
  pii ret=make_pair(1,s-ALLSUM[H-1][W-1]+rect_sum);
  rep(i,h-1){
    //i=0 to h-2;
    pii ret1=rec(y,x,i+1,w);
    pii ret2=rec(y+i+1,x,h-(i+1),w);
    pii tmp;
    if(ret1.first==-1 || ret2.first==-1)continue;
    tmp.first=ret1.first+ret2.first;
    tmp.second=min(ret1.second,ret2.second);
    ret=max(ret,tmp);
  }
  rep(i,w-1){
    pii ret1=rec(y,x,h,i+1);
    pii ret2=rec(y,x+i+1,h,w-(i+1));
    pii tmp;
    if(ret1.first==-1 || ret2.first==-1)continue;
    tmp.first=ret1.first+ret2.first;
    tmp.second=min(ret1.second,ret2.second);
    ret=max(ret,tmp);
  }
  return MEMO[y][x][h][w]=ret;
}

int main()
{
  while(true){
    G.clear();
    rep(i,32)rep(j,32)rep(k,32)rep(l,32)MEMO[i][j][k][l]=make_pair(0,0);
    rep(i,32)rep(j,32)ALLSUM[i][j]=0;
    
    cin>>H>>W>>s;
    if(!H and !W and !s)break;
    G.resize(H,vector<int>(W));
    rep(i,H)rep(j,W)scanf("%d",&G[i][j]);

    rep(i,H){
      rep(j,W){
        ALLSUM[i][j]=G[i][j];
        if(j>0)ALLSUM[i][j]+=ALLSUM[i][j-1];
      }
    }
    rep(i,H){
      rep(j,W){
        if(i>0)ALLSUM[i][j]+=ALLSUM[i-1][j];
      }
    }

    
    pii ans=rec(0,0,H,W);
    printf("%d %d\n",ans.first,ans.second);
    
  }
  return 0;
}
