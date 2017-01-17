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

#define rep(i,j) for(int i=0;i<j;i++)
#define repeat(i,j,k) for(int i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int i=(j),i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10


class SCC_Divide
{
  int V;
  vector< vector<int> > G;
  vector< vector<int> > rG;
  vector< int > vs;
  vector<bool> used;
  vector<int> cmp;
public:
  SCC_Divide(int n)
  {
    V=n;
    G.resize(n);
    rG.resize(n);
    used.resize(n);
    cmp.resize(n);
  }

  void add_arc(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  void dfs(int v){
    used[v]=true;
    rep(i,(int)G[v].size())
      if(!used[G[v][i]])
	dfs(G[v][i]);
    vs.push_back(v);
  }
  void rdfs(int v, int k){
    used[v]=true;
    cmp[v]=k;
    rep(i,(int)rG.size())
      if(!used[rG[v][i]])
	rdfs(rG[v][i],k);
  }
  //トポロジカル順序を返す
  vector<int> SCC(){
    fill(all(used),false);
    vs.clear();
    rep(v,V)
      if(!used[v])
	dfs(v);
    fill(all(used),false);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
      if(!used[vs[i]])rdfs(vs[i],k++);
    return cmp;
  }
};

int main()
{
  int n,m,k;cin>>n>>m>>k;
  char chars[301];
  rep(i,n)cin>>chars[i];
  SCC_Divide SCC(n);
  rep(i,m){
    int a,b;cin>>a>>b;
    SCC.add_arc(a,b);
  }
  vector<int> ans=SCC.SCC();
  rep(i,ans.size())cout<<ans[i]<<" ";
  return 0;
}

