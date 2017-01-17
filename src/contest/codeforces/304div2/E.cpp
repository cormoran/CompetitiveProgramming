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
#include<cstring>
//#include<cstdint>
using namespace std;

typedef long long int64;typedef int int32;
typedef long long ll;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const int INF = 1 <<30;

struct Edge{
  int to,capacity,rev;
  
};

vector<Edge> G[202];//隣接リスト
bool used[202];

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
    fill(used,used+202,false);
    int f=dfs(s,t,INF);
    if(f==0)return flow;
    flow+=f;
  }
  abort();
  
}

int level[202];//sからの距離
int iter[202];//とこまで調べたか

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
  int n,m;cin>>n>>m;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  int sum=0;
  rep(i,n){
    sum+=a[i];
    add_Edge(i, i+n, a[i]);
    add_Edge(2*n, i, a[i]);
    add_Edge(i+n, 2*n+1, b[i]);
  }
  
  rep(i,m){
    int p,q;
    cin>>p>>q;
    p--;q--;
    add_Edge(p,n+q,a[p]);
    add_Edge(q,n+p,a[q]);
  }
  puts("d");
  int ma=max_Flow_Ford_Fulkerson(n*2, n*2+1);
  //int ma=max_flow_Dinic(n*2, n*2+1);
  cout<<"ma "<<ma<<endl;
  cout<<"su "<<sum<<endl;
  if(ma!=sum){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
  
  return 0;
}
