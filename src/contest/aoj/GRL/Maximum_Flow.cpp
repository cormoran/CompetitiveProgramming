//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<queue>
using namespace std;
typedef long long int64;typedef int int32;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const int64 INF = 1LL <<60;

//蟻本流　隣接リスト方式の最大流量 Ford-Fulkerson's Algorothm

//蟻本ヒント
//複数のsource ,sinkがあるとき : それらにつながる新たな点s,tを作って流す
//頂点にも容量がある : 頂点を二点に分割して辺の容量に落とす
//最小流量の制約がある : P193参照

//グラフの変形時の更新 : 再び残余ネットワークのフロー増加道を探すことで更新できる

//二部マッチング : cap=1でフローを流すと考える

struct Edge{
  int to,capacity,rev;
};

vector<Edge> G[100];//隣接リスト
bool used[100];

void add_Edge(int from,int to,int capacity){
  G[from].push_back((Edge){to,capacity,G[to].size()});
  G[to].push_back((Edge){from,capacity,G[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  used[v]=true;

  for(auto e : G[v]){
    if(!used[e.to] and e.capacity>0){
      int d=dfs(e.to,t,min(f,e.capacity));
      if(d>0){
	e.capacity-=d;
	G[e.to][e.rev].capacity+=d;
	return d;
      }
    }
  }
  return 0;
}

//O(F|E|) :F is max flow
int max_Flow_Ford_Fulkerson(int s,int t){
  int flow=0;
  while(true){
    fill(used,used+100,false);
    int f=dfs(s,t,INF);
    if(f==0)return flow;
    flow+=f;
  }
  abort();
}

int level[100];//sからの距離
int iter[100];//とこまで調べたか

//sからの最短距離を出す : 距離はすべて1なのでbfsでいい
void BFS(int s){
  memset(level,-1,sizeof(level));
  queue<int> que;

  level[s]=0;
  while(!que.empty()){
    int v=que.front();que.pop();
    for(auto e : G[v]){
      if(e.capacity>0 and level[e.to]<0){
	level[e.to]=level[v]+1;
	que.push(e.to);
      }
    }
  }
}

int DFS(int v,int t,int f){
  if(v==t)return f;
  for(int &i=iter[v];i<G[v].size();i++){
    Edge &e=G[v][i];
    if(e.capacity>0 and level[v]<level[e.to]){
      int d=DFS(e.to,t,min(f,e.capacity));
      if(d>0){
	e.capacity-=d;
	G[e.to][e.rev].capacity+=d;
	return d;
      }
    }
  }
  return 0;
}

//O(|E||V|^2)
int max_flow_Dinic(int s,int t){
  int flow=0;
  while(true){
    BFS(s);
    if(level[t]<0)return flow;
    memset(iter,0,sizeof(iter));
    int f;
    while((f=dfs(s,t,INF))>0)flow+=f;
  }
  abort();
}


int main()
{
  
  return 0;
}
