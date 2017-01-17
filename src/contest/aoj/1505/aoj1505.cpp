#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<map>
//#include<>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;
typedef pair<ll,ll> Node;

#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i--)

ll INF=1LL<<62LL;
class Dijkstra
{
public:
  typedef struct Edge{ll to,cost;}Edge;
  vector< vector<Edge> > Graph;//接続リスト

  Dijkstra(ll n)
  {
    vector<Edge> temp;
    Graph.resize(n,temp);
  }

  void add_arc(ll x,ll y,ll c)
  {
    Edge e={y,c};
    Graph[x].push_back(e);
  }

  vector<ll> get_distance(ll s)
  {
    priority_queue< Node ,vector<Node>,greater<Node> > que;//(sからの距離,インデックス)
    vector<ll>ans;
    ll i;
    ans.resize(Graph.size(),INF);
    ans[s]=0;
    que.push(Node(0,s));
    while(!que.empty()){
      Node now=que.top();que.pop();
      ll now_i=now.second;
      //nowへの最小距離でないならスキップ
      if(ans[now_i]<now.first)continue;
      //nowからの辺全てをみる
      rep(i,Graph[now_i].size()){
	Edge e=Graph[now_i][i];
	//nowから行った方が近かったら更新
	if(ans[e.to]>ans[now_i]+e.cost){
	  ans[e.to]=ans[now_i]+e.cost;
	  que.push(Node(ans[e.to],e.to));
	}
      }
    }
    return ans;
  }

};

/*
  親が子の和になる二分木

  最深部は1bit目が1、その上は1bit目0で2bit目が1...
  となる様にインデックス付け
*/
class BIT
{

public:
  vector<ll> bit;

  BIT(ll n)
  {
    bit.resize(n+1,0);
  }
  ll sum(ll i)
  {
    ll s=0;
    while(i>0){
      s+=bit[i];
      i-=i& (-i);//i& -i はiの最小1bit  <- 2^kを引く
    }
    return s;
  }

  void add(ll i,ll x){
    while(i<=bit.size()){
      bit[i]+=x;
      i+=i& (-i);
    }
  }
};

typedef struct Query{
  ll fs,fe;ll id;
  Query(ll fs_,ll fe_,ll id_):fs(fs_),fe(fe_),id(id_){};
  bool operator<(const Query& right)const{
    return fs!=right.fs?fs<right.fs:fe>right.fe; 
  }
}Query;

int main()
{
  ll n,m,i;
  cin>>n>>m;
  Dijkstra G(n);
  ll q_num;
  vector<Query> query;

  //input
  {
    rep(i,m){
      ll a,b,c;
      cin>>a>>b>>c;
      G.add_arc(a,b,c);
      G.add_arc(b,a,c);
    }
    cin>>q_num;
    rep(i,q_num){
      ll fs,fe;
      cin>>fs>>fe;
      query.push_back(Query(fs,fe,i));
    }
  }
  
  vector<ll> d_s=G.get_distance(0),d_e=G.get_distance(n-1);

  //d_eを座標圧縮
  map<ll,ll> zip;
  {
    vector<ll>temp;
    temp.resize(d_e.size(),0);
    
    copy(d_e.begin(),d_e.end(),temp.begin());
    rep(i,query.size())
      temp.push_back(query[i].fe);


    sort(temp.begin(),temp.end(),greater<ll>() );
    temp.erase(unique(temp.begin(),temp.end()),temp.end());

    rep(i,temp.size())
      zip[temp[i]]=i+1;
    rep(i,d_e.size())
      d_e[i]=zip[d_e[i]];
  }

  vector<pll> distance;
  rep(i,n)
    distance.push_back(pll(d_s[i],d_e[i]));
  sort(distance.begin(),distance.end());

  BIT bit(zip.size());
  vector< pll >::iterator itr=distance.begin();
  vector<ll> ans;
  ans.resize(query.size(),0);
  
  sort(query.begin(),query.end());
  rep(i,query.size())
    {
      while(itr!=distance.end() && itr->first<=query[i].fs){
	bit.add(itr++->second,1);
      }
      ans[query[i].id]=bit.sum(zip[query[i].fe]);
    }

  rep(i,ans.size())
    cout<<ans[i]<<endl;
  
  return 0;
}
