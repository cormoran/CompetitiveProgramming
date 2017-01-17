/* Traveling Salesman Problem - 巡回セールスマン問題 メモ化*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

#define V_MAX 15
const int INF=1<<30;

int DP[1<<V_MAX][V_MAX]; //[S][now] : now から U\S を訪れて0に戻る最短コスト
int G[V_MAX][V_MAX];
int V,E;
int rec(int S,int now){
  if( DP[S][now] >= 0 ) return DP[S][now];
  if( S == (1<<V)-1 && now==0 ) return DP[S][now]=0;
  int ret=INF;
  rep(v,V){
    if(( S & (1<<v)) || G[now][v] == INF)continue;
    ret = min( ret , rec(S | 1<<v,v)+G[now][v] );
  }
  return DP[S][now]=ret;
}

int main()
{
  cin>>V>>E;
  rep(i,V)rep(j,V)G[i][j]=INF;
  rep(i,1<<V)rep(j,V)DP[i][j]=-1;
  rep(i,E){
    int s,t,d;
    cin>>s>>t>>d;
    G[s][t]=d;
  }
  int ans=rec(0,0);
  cout<< (ans>=INF ? -1 : ans) <<endl;
  
  return 0;
}
