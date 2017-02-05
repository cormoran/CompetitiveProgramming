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
  struct UnionFind unionfind(n);
  for(i=0;i<n;i++){
    if(i==0 || unionfind.query(i,0)==false){
      long mincost=100000;
      bool can_alternate=false;
      int mincostnum=501;
      for(j=0;j<n;j++){
	if(map[i][j]<mincost && unionfind.query(i,j)==false){
	  mincost=map[i][j];
	  mincostnum=j;
	  can_alternate=false;
	}
	else if(map[i][j]==mincost)can_alternate=true;
      }
      unionfind.merge(i,mincostnum);
      if(can_alternate==false){
	ans_num++;
	ans_cost+=mincost;
      }
    }
  }
  cout<<ans_num<<" "<<ans_cost<<endl;
  return 0;
}
