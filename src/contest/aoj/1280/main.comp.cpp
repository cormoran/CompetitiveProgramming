//  aoj-1280  / 2015-11-20
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}
const int INF = 1<<30;

class UnionFindTree
{
public:
  int Node_num;
  vector<int> parents;
  vector<int> ranks;

  UnionFindTree(int n):Node_num(n+1)
  {
    n++;//index=1_to_nに対応
    parents.resize(n);
    ranks.resize(n);
    for(int i=0;i<n;i++)
      {
	parents[i]=i;
	ranks[i]=0;
      }
  }

  int get_root(int x)
  {
    if(parents[x]==x)return x;
    else 
      {
	//探索と同時に根につなぎ変える
	return parents[x]=get_root(parents[x]);
      }
  }

  void unite(int x,int y)
  {
    //異なる集合にいたら統合
    if( (x=get_root(x))!=(y=get_root(y)) )
      {
	//木が浅くなるような統合をする
	if(ranks[x]>ranks[y])
	  parents[y]=x;
	else if(ranks[x]<ranks[y])
	  parents[x]=y;
	else
	  {
	    parents[x]=y;
	    ranks[y]++;
	  }
      }
  }

  //xとyが同じ集合にあるか
  bool is_sameset(int x,int y)
  {
    return get_root(x)==get_root(y);
  }

};

struct Edge{
    int a,b;
    int w;
};

struct cmp{
    int w;
    cmp(int w):w(w){}
    
    bool operator ()(const Edge &a,const Edge &b){
        int da = a.w - w;
        int db = b.w - w;
        if(da<0)da = INF;
        if(db<0)db = INF;
        return da < db;
    }
};

bool solve(){
    int n,m;cin>>n>>m;
    if(n==0 and m==0)return false;
    vector<Edge> E(m);
    rep(i,m){
        cin>>E[i].a>>E[i].b>>E[i].w;
    }
    vector<Edge> EE = E;
    int ans = INF;
    for(Edge e : E){
        sort(EE.begin(),EE.end(),cmp(e.w));
        UnionFindTree ut(n);
        int mx = -1;
        int cnt =  1;
        rep(i,EE.size()){
            if(ut.is_sameset(EE[i].a, EE[i].b))continue;
            if(EE[i].w < e.w)goto END;
            ut.unite(EE[i].a,EE[i].b);
            mx = max(mx , EE[i].w - e.w);
            cnt++;
            if(cnt==n)break;
        }
        if(cnt==n){
            ans = min(ans,mx);
        }
        
  END:
        ;
    }
    if(ans == INF)cout<<-1<<endl;
    else cout <<ans<<endl;
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
