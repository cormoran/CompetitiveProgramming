#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string.h>
#include<cmath>
//#include<>
using namespace std;
  typedef long W;
typedef long long ll;
typedef pair<int,int> Pii;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)
  enum { INF = 9999999999 };
struct Dijkstra {


  struct Edge {
    int from, to;
    W cost;
    Edge(int from, int to, W cost) :
      from(from), to(to), cost(cost) {}
  };
  vector< vector<Edge> > G;
  int V;
  Dijkstra(int V) : V(V) {
    G.resize(V, vector<Edge>());
  }
    void addEdge(int from, int to, W cost) {
    G[from].push_back(Edge(from, to, cost));
  }
  /* 引数に始点sをとり, 各頂点への最短経路を返す. */
  vector<W> solve(int s) {
    vector<W> D(V, INF);
    bool used[V]; 
    memset(used, 0, sizeof(used));
    used[s] = true;
    D[s] = 0;
    priority_queue<S> PQ;
    PQ.push(S(s, 0));
    while (!PQ.empty()) {
      S cur = PQ.top(); PQ.pop();
      for (int i = 0; i < G[cur.v].size(); i++) {
	Edge& e = G[cur.v][i];
	if (D[e.to] > D[cur.v] + e.cost) {
	  D[e.to] = D[cur.v] + e.cost;
	  PQ.push(S(e.to, D[e.to]));
	}
      }
    }
    return D;
  }
  struct S {
    int v;
    W cost;
    S(int v, W cost) : v(v), cost(cost) {}
    bool operator<(const S& s) const {
      return cost > s.cost;
    }
  };
};


int main()
{
  
  //input
  int n,s,t;
  long m;
  cin>>n>>m>>s>>t;
  s--;
  t--;
  
  Dijkstra MAP(n);
  int i,j,k;
  rep(i,m)
    {
      long x,y,d;
      scanf("%ld,%ld%ld",&x,&y,&d);
      x--;y--;
      MAP.addEdge(x,y,d);
      MAP.addEdge(y,x,d);
    }
  rep(i,n)MAP.addEdge(i,i,0);

 //solve
  vector<W> S=MAP.solve(s),T=MAP.solve(t);
  rep(i,n)
    {
      if(S[i]==T[i]&&S[i]<INF)
	{
	  cout<<i+1<<endl;
	  return 0;
	}
    }
  cout<<-1<<endl;
  return 0;
}
