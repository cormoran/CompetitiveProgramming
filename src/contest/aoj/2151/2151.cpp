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

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

class Path{  
public:
  struct Edge{int to,cost,dist;Edge(int to_,int cost_,int d):to(to_),cost(cost_),dist(d){;}};

  int node_size;
  vector< vector<Edge> > E_list;//接続リスト

  
  Path(int node_size_){E_list.resize(node_size_);node_size=node_size_;}
  
  void add_arc(int x,int y,int c,int d)
  {
    E_list[x].push_back(Edge(y,c,d));
  }
  void add_edge(int x,int y,int c,int d)
  {
    E_list[x].push_back(Edge(y,c,d));
    E_list[y].push_back(Edge(x,c,d));
  }
};

struct djk_state{
  int index;
  int cost;
  int money;
  djk_state(int i,int c,int m):index(i),cost(c),money(m){;}
  bool operator<(const djk_state &r)const{return cost<r.cost;}
  bool operator>(const djk_state &r)const{return cost>r.cost;}
};


int dijkstra(Path &Graph,int N,int M,int L){
  priority_queue< djk_state ,vector<djk_state>,greater<djk_state> > que;
  vector<int> ans;
  bool visited[101][101]={};//[money][index]
  
  que.push(djk_state(0,0,L));
    
  while(!que.empty()){
    djk_state now=que.top();que.pop();    

    //printf("index %d money %d\n",now.index,now.money);

    if(visited[now.money][now.index])continue;
    visited[now.money][now.index]=true;
    if(now.index==N-1){
      ans.push_back(now.cost);
      continue;
    }
    
    for(Path::Edge e : Graph.E_list[now.index]){
      if(now.money-e.dist>=0)
	que.push(djk_state(e.to,now.cost,now.money-e.dist));
      que.push(djk_state(e.to,now.cost+e.cost,now.money));
    }
    
  }
  int answer=INF;
  rep(i,ans.size())answer=min(answer,ans[i]);
  return answer;
}




int main()
{
  while(1){
    int N,M,L;
    cin>>N>>M>>L;
    if(N==0)break;
    Path G(N);
    rep(i,M){
      int a,b,d,e;
      cin>>a>>b>>d>>e;
      G.add_edge(a-1,b-1,e,d);
    }
    cout<<dijkstra(G,N,M,L)<<endl;
  }
  return 0;
}
