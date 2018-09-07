
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
 
i64 INF=1<<30;
 
class Path{  
public:
  struct Edge{i64 to,cost;Edge(i64 to_,i64 cost_):to(to_),cost(cost_){;}};
  i64 node_size;
  vector< vector<Edge> > E_list;//接続リスト
  vector< vector<i64> > G;
  Path(i64 node_size_){E_list.resize(node_size_);node_size=node_size_;G.resize(node_size_,vector<i64>(node_size_,INF));}
  void add_arc(i64 x,i64 y,i64 c)
  {
    E_list[x].push_back(Edge(y,c));
    G[x][y]=c;
  }
  void add_edge(i64 x,i64 y,i64 c)
  {
    E_list[x].push_back(Edge(y,c));
    E_list[y].push_back(Edge(x,c));
    G[x][y]=c;G[y][x]=c;
  }
};
 
typedef pair<i64,i64> pii;
 
struct state{
  i64 cost;
  i64 node;
  i64 number;
 
  bool operator<(const state &r)const{return cost>r.cost;}
  bool operator>(const state &r)const{return cost<r.cost;}
};

void WarshallFloyd(Path &G){
  i64 V=G.node_size;
  vector< vector<i64> > &dist=G.G;    
    rep(i,V)dist[i][i]=0;

    rep(k,V)rep(i,V)rep(j,V){
      if(dist[i][k]!=INF && dist[k][j]!=INF)
	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    }
}



 
int main()
{
  int N,M;
  cin>>N>>M;
  
  Path G(N);

  vector<pii> home_e;

  rep(i,M){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b)swap(a,b);
    if(a==1)home_e.push_back(make_pair(b-1, c));
    else G.add_edge(a-1, b-1, c);
  }

  WarshallFloyd(G);
  i64 ans=INF;
  rep(i,home_e.size()){
    rep(j,home_e.size()){
      if(i==j)continue;
      i64 dist=G.G[home_e[i].first][home_e[j].first];
      if(dist>=INF)continue;
      ans=min(ans,dist + home_e[i].second + home_e[j].second);
    }
  }
  if(ans==INF)ans=-1;

  cout<<ans<<endl;
  
  return 0;
}
