#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

struct Edge{
  int64 to;
  int64 cost;
  int64 from;
  Edge(int64 t,int64 c, int64 f=-1):to(t),cost(c),from(f){;}
};

int64 n;
vector< vector<Edge> > G;
vector<int> subt;

int64 count_visit(int64 index,int64 prev){
  subt[index]=1;
  for(auto e : G[index]){
    if(e.to!=prev)
      subt[index]+=count_visit(e.to,index);
  }
  return subt[index];
}

int64 sum_visit(int64 index,int64 prev){
  int64 ret=0;
  for(auto e:G[index]){
    if(e.to!=prev){
      ret+=subt[e.to]*(n-subt[e.to])*e.cost;
      ret+=sum_visit(e.to,index);
    }
  }
  return ret;
}

int main()
{
  cin>>n;
  G.resize(n);
  vector<Edge> edges(n-1,Edge(0,0,0));
  rep(i,n-1){
    int64 a,b,c;cin>>a>>b>>c;
    a--;b--;
    edges[i]=Edge(b,c,a);
    G[a].push_back(Edge(b,c));
    G[b].push_back(Edge(a,c));
  }

  int64 allcost;
  double allcase=n*(n-1)/(2*3);
  subt.resize(n);
  
  count_visit(0,-1);
  allcost=sum_visit(0,-1);

  int64 q;cin>>q;
  rep(i,q){
    int64 r,w;cin>>r>>w;
    r--;
    int64 temp=min(subt[edges[r].from],subt[edges[r].to]);
    allcost+=(w-edges[r].cost)*temp*(n-temp);
    edges[r].cost=w;
    printf("%.10lf\n",(double)allcost*2*3/n/(n-2));
    // allcost/allcase is wrong answer.
  }
  
  return 0;
}













