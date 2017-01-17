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
#include<map>
using namespace std;
 
typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;
 
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)
 
const i64 INF=1L<<60;//=10E10
 
class Path{
 
    public:
  struct Edge{i64 to,cost;Edge(i64 to_,i64 cost_):to(to_),cost(cost_){;}};
 
 
  vector< vector<i64> > G;//隣接行列
  i64 V_num;
  i64 min_sum=0;

  
  Path(i64 n){G.resize(n,vector<i64>(n,INF));V_num=n;}
 
  void add_arc(i64 x,i64 y,i64 c)
  {
    G[x][y]=c;
    G[y][x]=c;
      
  }

  void update_arc(i64 x,i64 y,i64 c){
    if(G[x][y]<=c)return;
    G[x][y]=c;
    G[y][x]=c;
  }
  
  void  WarshallFloyd(){
    int V=G.size();
 
    min_sum=0;
    rep(k,V)rep(i,V)rep(j,V){
      G[i][j]=min(G[i][j],G[i][k]+G[k][j]);          
    }
    rep(i,G.size()){
      repeat(j,i+1,G.size()){
	min_sum+=G[i][j];
      }
    }
  }

  void update_WarshallFloyd(i64 x,i64 y,i64 c){
    if(G[x][y]<=c)return;
    G[x][y]=c;
    G[y][x]=c;
    min_sum=0;
    rep(i,G.size()){
      rep(j,G.size()){
	G[i][j]=min(G[i][j],min(G[i][x]+G[x][y]+G[y][j],G[i][y]+G[y][x]+G[x][j]));
      }
    }
    rep(i,G.size()){
      repeat(j,i+1,G.size()){
	min_sum+=G[i][j];
      }
    }
    
  }
  
};
 
int main()
{
  int n,m;
  cin>>n>>m;
  Path path(n);
 
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    path.add_arc(a-1,b-1,c);
    path.add_arc(b-1,a-1,c);
  }
 
  int k;
  cin>>k;
  path.WarshallFloyd();
  rep(i,k){
    int x,y,z;
    cin>>x>>y>>z;
    path.update_WarshallFloyd(x-1,y-1,z);
    //path.update_arc(x-1,y-1,z);
    //path.WarshallFloyd();
    cout<<path.min_sum<<endl;
    
  }
  
  return 0;
}
