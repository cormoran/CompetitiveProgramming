#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;i++)

struct UnionFind {
  int* parent;
  int N;
  UnionFind(int N) : N(N) {
    parent = new int[N];
    fill(parent, parent + N, -1);
  }
  ~UnionFind() {
    delete[] parent;
  }
  int root(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = root(parent[x]);
  }
  bool query(int x, int y) {
    return root(x) == root(y);
  }
  void merge(int x, int y) {
    x = root(x); 
    y = root(y);
    if (x != y) {
      parent[x] = y;
    }
  }
};

int main()
{
  //入力
  long n,m;
  cin>>n>>m;


  long map[501][501];
  long i,j,k;
  rep(i,n)rep(j,n)
    map[i][j]=100000;

  rep(i,m){
    long s,d,c;
    cin>>s>>d>>c;
    map[s-1][d-1]=c;
    map[d-1][s-1]=c;
  }
  long long ans_cost=0;
  long ans_num=0;
  long mincosts_from_tree[n];
  rep(i,n)mincosts_from_tree[i]=map[0][i];
  int nxt_num,nxt_cst=100000;
  while(true){
    rep(i,n)
      if(mincosts_from_tree[i]>0 && mincosts_from_tree[i]<nxt_cst)
	{
	  nxt_num=i;
	  nxt_cst=mincosts_from_tree[i];
	}
      else if(mincost_f
    //島i を木に追加
    mincosts_from_tree[i]=-1;
    
  struct UnionFind unionfind(n);


  cout<<ans_num<<" "<<ans_cost<<endl;
  return 0;
}
