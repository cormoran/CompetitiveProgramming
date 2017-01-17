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
#include<map>
  using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

#define MAX_N 1010
class maxFlow
{
public:
  int N;//ノード数
  int G[MAX_N][MAX_N];//G[i][j] :=点iからjへの弧の容量
  bool is_visited[MAX_N];

  maxFlow(int n)
  {
    N=n;
    //容量０の完全有向グラフができる
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
	G[i][j]=0;
  }

  //n1->n2のarcを作る
  void add_arc(int n1,int n2,int capacity)
  {
    G[n1][n2]+=capacity;//多重弧は統合
  }

  //ゴールまでの道を探索
  int dfs(int now,int end,int min_capacity)
  {
    if(now==end)return min_capacity;
    if(!is_visited[now])
      {
	is_visited[now]=true;
	for(int i=0;i<N;i++){
	  if(G[now][i]>0){//nowからiへの弧容量の残余があれば進んでみる
	    int ret=dfs(i,end,min(min_capacity,G[now][i]));
	    if(ret>0){//ゴールに達したならその道で確定して残余ネットワークを更新
	      G[now][i]-=ret;
	      G[i][now]+=ret;
	      return ret;
	    }
	  }
	}
	return -2;//ゴールに行ける道がなかった
      }
    else return -1;//すでに訪問済みだった
  }
  
  int get_maxFlow(int start,int end)
  {
    int temp,ans=0;
    //ゴールへの道がなくなるまで残余ネットワークの経路を検索
    while(true){
      for(int i=0;i<N;i++)is_visited[i]=false;
      temp=dfs(start,end,100);
      if(temp>0)ans+=temp;
      else break;
    }
    return ans;
  }
  
};

int gcd(int a,int b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main()
{
  int n,m;

  while(true){
    cin>>m>>n;
    if(m==0&&n==0)break;
    maxFlow G(m+n+2);
    vector<int> b(m);
    vector<int> r(n);
    rep(i,m){
      cin>>b[i];
      G.add_arc(m+n, i, 1);
    }
    rep(i,n){
      cin>>r[i];
      G.add_arc(m+i, m+n+1 , 1);
    }
    
    rep(i,m){
      rep(j,n){
        if(gcd(b[i],r[j])!=1){
          G.add_arc(i, m+j, 1);
        }
      }
    }

    cout<<G.get_maxFlow(m+n, m+n+1)<<endl;
    
  }

  
  return 0;
}
