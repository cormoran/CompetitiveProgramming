#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<bitset>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;

#define rep(i,j) for(int i=0;i<j;i++)
#define repeat(i,j,k) for(i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

struct Edge{
  int to;
  int cost;
};
struct State{
  int node;
  int t;
  double time;
  bool operator>(const State &r)const{
    return time>r.time;
  }
};

int n,m,p,a,b;
int t_data[8];
vector<Edge> G[31];

void Dig(){
  priority_queue<State,vector<State>,greater<State> > que;
  bool flg[31][257]={};//[点][残りチケット]
  rep(i,m)rep(j,257)flg[i][j]=false;
  que.push((State){a,0xFF,0});
  
  while(!que.empty()){
    State now=que.top();que.pop();
    if(now.node==b){
      printf("%.4f\n",now.time);
      return;
    }
    if(flg[now.node][now.t])continue;
    flg[now.node][now.t]=true;
    rep(i,G[now.node].size()){
      rep(j,n){
	if(now.t&(1<<j)){
	  que.push((State){G[now.node][i].to,now.t&~(1<<j),now.time+G[now.node][i].cost/(double)t_data[j]});
	}
      }
    }
  }
  cout<<"Impossible"<<endl;
  return;
}

int main()
{

  while(true)
    {
      cin>>n>>m>>p>>a>>b;
      a--;b--;
      if(n==0)break;

      rep(i,n)
	cin>>t_data[i];
      rep(i,p){
	int x,y,z;cin>>x>>y>>z;
	x--;y--;
	G[x].push_back((Edge){y,z});
	G[y].push_back((Edge){x,z});
      }
      Dig();
      rep(i,m)
	G[i].clear();
    }
  return 0;
}
