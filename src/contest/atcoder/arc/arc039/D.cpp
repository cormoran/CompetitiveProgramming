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
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const int INF=1<<31;


class LCA
{
public:
  vector< vector<int> > parent;//[i][j]：点jの2^i上の親　存在しない場合は-1
  vector<int> depth;
  vector< vector<int> > connection;
  int N;//ノード数
  int log2_N;//log2_Nの端数切り上げ

  LCA(int n){
    N=n;
    log2_N=ceil((double)log(n)/log(2));
    vector<int>temp,temp2;
    temp.resize(N,-1);
    parent.resize(log2_N,temp);
    depth.resize(N,-1);
    connection.resize(N,temp2);//各nodeの接続の数は不明
  }

  //無向グラフになるようにしている
  //node = 0...(N-1)
  void add_edge(int n1,int n2)
  {
    connection[n1].push_back(n2);
    connection[n2].push_back(n1);
  }

  //rootを根(depth=0)にして各nodeの深さを作る
  void makedepth(int root)
  {
    makedepth_dfs(-1,root,0);
  }
private:
  //O(n)
  void makedepth_dfs(int pre,int me,int dep)
  {
    int i;
    parent[0][me]=pre;
    depth[me]=dep;
    for(i=0;i<connection[me].size();i++)
	if(connection[me][i]!=pre)
	  makedepth_dfs(me,connection[me][i],dep+1);
  }
public:
  //O(nlogn)
  void doubling()
  {
    int i,j;
    rep(i,log2_N-1)
      rep(j,N)
      {
	if(parent[i][j]>=0)
	  parent[i+1][j]=parent[i][parent[i][j]];
	else parent[i+1][j]=-1;
      }
  }
  
  int get_LCA(int n1,int n2)
  {
    //n2が深くなるようにする
    if(depth[n1]>depth[n2])
      swap(n1,n2);
    //深さが合うまでn2を登らせる
    for(int i=0;i<log2_N;i++)
      if((depth[n2]-depth[n1]>>i)&1)//ここ謎
	  n2=parent[i][n2];
    //2^i上がって親が同じかチェック
    int lca;
    if(n1==n2)return n1;
    else{
      for(int i=log2_N-1;i>=0;i--)
	if(parent[i][n1]!=parent[i][n2])
	  {
	    n1=parent[i][n1];
	    n2=parent[i][n2];
	  }
      return parent[0][n1];
    }
  }
  
  int get_depth(int node)
  {
    return depth[node];
  }

};


int N,M;
vector< vector<int> > Elist;

vector<int> sum;
vector<bool> visited;
int cnt;
vector<int> Biconnected_Group;

LCA *Group_Tree;







int visit(int id,int prev){
  if(visited[id]){
    if(sum[id]>0)return 0;
    sum[id]--;
    return 1;
  }

  visited[id]=1;
  for(int v : Elist[id]){
    if(v!=prev)
      sum[id]+=visit(v,id);
  }
  Biconnected_Group[id]=cnt;

  if(sum[id]==0)cnt++;
  return sum[id];
}

void Split_Biconnected_Graph(){
  
  sum.clear();
  sum.resize(N,0);
  visited.clear();
  visited.resize(N,0);
  cnt=0;
  Biconnected_Group.clear();
  Biconnected_Group.resize(N,-1);

  visit(0,-1);
  sum.clear();
  sum.shrink_to_fit();
  visited.clear();
  visited.shrink_to_fit();

  Group_Tree=new LCA(cnt);
  rep(i,N){
    for(int v:Elist[i]){
      if(Biconnected_Group[i]!=Biconnected_Group[v]){
        Group_Tree->add_edge(Biconnected_Group[i], Biconnected_Group[v]);
      }
    }
  }
  Elist.clear();
  Elist.shrink_to_fit();
  return;
}

int main()
{
  cin>>N>>M;
  Elist.resize(N);
  rep(i,M){
    int x,y;
    cin>>x>>y;
    x--;y--;
    Elist[x].push_back(y);
    Elist[y].push_back(x);
  }
  
  Split_Biconnected_Graph();

  Group_Tree->makedepth(0);
  Group_Tree->doubling();



  
  int Q;
  cin>>Q;
  rep(i,Q){
    int A,B,C;
    cin>>A>>B>>C;
    A--;B--;C--;
    if(Biconnected_Group[A]==Biconnected_Group[B] or
       Biconnected_Group[B]==Biconnected_Group[C])
      cout<<"OK"<<endl;
    else {
      int GA=Biconnected_Group[A];
      int GB=Biconnected_Group[B];
      int GC=Biconnected_Group[C];
      int distAB=Group_Tree->get_depth(GA) +Group_Tree->get_depth(GB)
                 -2*Group_Tree->get_depth( Group_Tree->get_LCA(GA, GB) );
      int distBC=Group_Tree->get_depth(GB) +Group_Tree->get_depth(GC)
                 -2*Group_Tree->get_depth( Group_Tree->get_LCA(GB, GC) );
      int distAC=Group_Tree->get_depth(GA) +Group_Tree->get_depth(GC)
                 -2*Group_Tree->get_depth( Group_Tree->get_LCA(GA, GC) );
      if(distAC==distAB+distBC)
        cout<<"OK"<<endl;
      else cout<<"NG"<<endl;
    }
  }
  
  
  return 0;
}
