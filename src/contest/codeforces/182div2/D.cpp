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

struct Point{
  i32 x,y;
};

inline i32 Distance(Point &a,Point &b){
  return abs(a.x-b.x)+abs(a.y-b.y);
}

class Path{

  public:
  struct Edge{int to,cost;Edge(int to_,int cost_):to(to_),cost(cost_){;}};


  vector< vector<Edge> > G;//接続リスト

  Path(int n){G.resize(n);}

  void add_arc(int x,int y,int c)
  {
    G[x].push_back(Edge(y,c));
      
  }

  struct state{
    int index;
    int cost;
    state(int i,int c):index(i),cost(c){;}
    bool operator<(const state &r)const{return cost<r.cost;}
    bool operator>(const state &r)const{return cost>r.cost;}
      
  };

  vector<int> dijkstra(int start){
    priority_queue< state ,vector<state>,greater<state> > que;//(sからの距離,インデックス)

    vector<int>norm;
    norm.resize(G.size(),INF);
    que.push(state(start,0));

    while(!que.empty()){
      state now=que.top();que.pop();
      if(norm[now.index]!=INF)continue;
      norm[now.index]=now.cost;

      for(Edge e : G[now.index]){
	que.push(state(e.to,now.cost+e.cost));
	      
      }

          
    }
    return norm;
      
  }

  
};

  
int main()
{
  i32 n,d;cin>>n>>d;
  vector<i32> a(n);
  rep(i,n-2)cin>>a[i+1];
  a[0]=a[n-1]=0;
  vector<Point> station(n);
  rep(i,n){
    cin>>station[i].x>>station[i].y;
  }
  
  Path Graph(n);

  rep(i,n)repeat(j,i+1,n){
    i32 dist=Distance(station[i],station[j]);
    Graph.add_arc(i, j, dist*d-a[j]);
    Graph.add_arc(j, i, dist*d-a[i]);
  }

  vector<i32> ans=Graph.dijkstra(0);

  cout<<ans[n-1]<<endl;
  
  return 0;
}

















