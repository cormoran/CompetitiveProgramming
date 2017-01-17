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
//#include<>
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

class LCA
{
  public:
  vector< vector<int> > parent;//[i][j]：点jの2^i上の親　存在しない場合は-1
  vector<int> depth;
  vector< vector<int> > connection;
  vector<int> childnum;
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
    childnum.resize(N,0);
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
  int makedepth_dfs(int pre,int me,int dep)
  {
    int i;
    int childs=0;
    parent[0][me]=pre;
    depth[me]=dep;
    for(i=0;i<connection[me].size();i++)
      if(connection[me][i]!=pre)
	childs+=makedepth_dfs(me,connection[me][i],dep+1);
    childnum[me]=childs;
    return childs+1;
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

int main()
{
  int n;cin>>n;
  LCA tree(n);
  rep(i,n-1){
    int x,y;
    cin>>x>>y;
    tree.add_edge(x-1,y-1);
  }

  tree.makedepth(0);
  tree.doubling();


  int q;
  cin>>q;
  rep(i,q){
    int x,y;cin>>x>>y;
    x--;y--;
    int com=tree.get_LCA(x,y);
    int ans=0;
    if(com!=x and com!=y)ans=n-tree.childnum[com];
    else ans=0;
    cout<<ans<<endl;
  }
  
  return 0;
}
