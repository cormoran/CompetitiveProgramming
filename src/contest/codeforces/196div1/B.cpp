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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

const int INF =1<<30;

int n,m,d;
vector<int> p;
vector<vector<int>> E;

//nowから深さdepまでのノード数
int get_num(int now,int parent,int dep){
  if(dep<0)return 0;
  int ret =0;
  for(int nxt : E[now]){
    if(nxt!=parent){
      ret += get_num(nxt, now, dep-1);
    }
  }
  return ret;
}


pair<int,int> rec(int now,int parent,int dep){
  pair<int,int> ret = {INF,0};
  int min_node=-1;
  for(int nxt : E[now]){
    if(nxt!=parent){
      pair<int,int> r = rec(nxt, now, dep+1);
      if(ret.first<0 and r.first < 0)return {-INF,0};
      if(ret.first + r .first <0)return {-INF,0};
      if(ret.first>r.first){
        ret = r;
        min_node=nxt;
      }
    }
  }

  if(ret.first==0){
    ret.second=get_num(min_node, now, d)+1;
  }else if(parent<0){
    for(int nxt : E[now]){
      if(nxt!=min_node){
        ret.first+=get_num(nxt, now, ret.first -1);
      }
      ret.first+=get_num(min_node, now, d);
    }
  }
  ret.first--;
  return ret;
}

int main()
{

  cin>>n>>m>>d;
  p.resize(m);
  rep(i,m){
    cin>>p[i];
    p[i]--;
  }
  E.resize(n);
  rep(i,n){
    int a,b;
    cin>>a>>b;
    a--,b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  cout<< rec(0, -1, 0).second<<endl;
  
  return 0;
}
