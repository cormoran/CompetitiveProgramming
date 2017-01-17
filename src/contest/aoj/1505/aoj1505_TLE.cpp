//TLE
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

typedef pair<int,int> pii;
typedef pair<int,int> Node;
typedef long long ll;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i--)

int INF=1<<30;
class Dijkstra
{
public:
  typedef struct Edge{int to,cost;}Edge;
  vector< vector<Edge> > Graph;//接続リスト

  Dijkstra(int n)
  {
    vector<Edge> temp;
    Graph.resize(n,temp);
  }

  void add_arc(int x,int y,int c)
  {
    Edge e={y,c};
    Graph[x].push_back(e);
  }

  vector<int> get_distance(int s)
  {
    priority_queue< Node ,vector<Node>,greater<Node> > que;//(sからの距離,インデックス)
    vector<int>ans;
    int i;
    ans.resize(Graph.size(),INF);
    ans[s]=0;
    que.push(Node(0,s));
    while(!que.empty()){
      Node now=que.top();que.pop();
      int now_i=now.second;
      //nowへの最小距離でないならスキップ
      if(ans[now_i]<now.first)continue;
      //nowからの辺全てをみる
      rep(i,Graph[now_i].size()){
	Edge e=Graph[now_i][i];
	//nowから行った方が近かったら更新
	if(ans[e.to]>ans[now_i]+e.cost){
	  ans[e.to]=ans[now_i]+e.cost;
	  que.push(Node(ans[e.to],e.to));
	}
      }
    }
    return ans;
  }

};

bool comp_second_greater(const pii& a,const pii& b)
{
  if(a.second!=b.second)
    return a.second>b.second;
  else
    return a.first>b.first;
}

int solve(vector<pii> distance,int fs,int fe)
{
  vector<pii>::iterator fs_ok,fe_ok;
  fs_ok=upper_bound(distance.begin(),distance.end(),pii(fs,INF));
  if(fs_ok==distance.begin())return 0;
  sort(distance.begin(),fs_ok,comp_second_greater);
  fe_ok=upper_bound(distance.begin(),fs_ok,pii(-1,fe),comp_second_greater);
  return (int)(fe_ok-distance.begin());
}

int main()
{
  int n,m;
  cin>>n>>m;
  Dijkstra map(n);
  int i;
  rep(i,m)
    {
      int a,b,c;
      cin>>a>>b>>c;
      map.add_arc(a,b,c);
      map.add_arc(b,a,c);
    }
  
  vector<int> start_to=map.get_distance(0),end_to=map.get_distance(n-1);
  vector<pii> distance;
  rep(i,n)
      distance.push_back(pii(start_to[i],end_to[i]));

  sort(distance.begin(),distance.end());

  int q;
  cin>>q;

  rep(i,q)
    {
      int fs,fe;
      cin>>fs>>fe;
      cout<<solve(distance,fs,fe)<<endl;
    }
  
  return 0;
}
