#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//=10E10

struct Edge{int to,cost;Edge(int to_,int cost_):to(to_),cost(cost_){;}};

class Path{

  public:



  vector< vector<Edge> > G;//接続リスト

  Path(int n){G.resize(n);}

  void add_arc(int x,int y,int c)
  {
    G[x].push_back(Edge(y,c));
      
  }

  struct state{
    int index;
    int cost;
    int d;
    state(int i,int c,int d_):index(i),cost(c),d(d_){;}
    bool operator<(const state &r)const{return d==r.d ? cost<r.cost : d<r.d;}
    bool operator>(const state &r)const{return d==r.d ? cost>r.cost : d>r.d;}
      
  };

  vector< pair<i32,i32> > dijkstra(int start){
    priority_queue< state ,vector<state>,greater<state> > que;//(sからの距離,インデックス)

    vector< pair<i32,i32> >norm;
    norm.resize(G.size(),make_pair(INF,INF));
    que.push(state(start,0,0));

    while(!que.empty()){
      state now=que.top();que.pop();
      if(norm[now.index].first!=INF)continue;
      norm[now.index].second=now.cost;
      norm[now.index].first=now.d;

      for(Edge e : G[now.index]){
	que.push(state(e.to,now.cost+e.cost,now.d+1));
      }
    }
    return norm;
      
  }

  
};


int main()
{
  i32 n,m;
  cin>>n>>m;
  Path P(n);
  rep(i,m){
    i32 x,y,z;cin>>x>>y>>z;
    x--;y--;
    if(z==1)z=0;
    else
      z=1;
    P.add_arc(x,y,z);
  }
  vector<pair<i32,i32> > dijk=P.dijkstra(n-1);

  vector<pair<i32,i32> > ans1;
  
  i32 now=n;
  while(now>0){
    i32 nxt=-1;
    i32 prev=n;
    --now;
    i32 nxtd=INF;
    Edge *pe=0;
    for(auto e : P.G[now]){
      if(e.to!=prev && nxtd>dijk[e.to].first){
	nxt=e.to;
	nxtd=dijk[e.to].first;
	pe=&e;
      }
    }
    if(pe!=0)
      if(pe->cost==1)ans1.push_back(make_pair(now+1,nxt+1));
  }

  vector<pair<i32,i32> > ans0;
  
  rep(i,n){
    for(auto e : P.G[i]){
      if(e.cost==0){
	ans0.push_back(make_pair(i+1,e.to));
      }
    }
    
  }

  cout<<ans1.size()+ans0.size()<<endl;
  rep(i,ans1.size())printf("%d %d %d\n",ans1[i].first,ans1[i].second,1);
  rep(i,ans0.size())printf("%d %d %d\n",ans0[i].first,ans0[i].second,0);
  
  return 0;
}










