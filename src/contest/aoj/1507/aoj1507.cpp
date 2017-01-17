#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;

#define repeat(i,j,k) for(int i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int i=(j)-1;i>=k;i--)
#define rep(i,j) repeat(int i,0,j)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

const int MAX_N 1000;


class UnionFindTree
{
public:
  Natural Node_num;
  Natural parents[MAX_N];
  Natural ranks[MAX_N];

  UnionFindTree(Natural n):Node_num(n+1)
  {
    n++;//index=1_to_nに対応？

    for(Natural i=0;i<n;i++)
      {
	parents[i]=i;
	ranks[i]=0;
      }
  }
  
  Natural get_root(Natural x)
  {
    if(parents[x]==x)return x;
    else 
      {
	//探索と同時に根につなぎ変える
	return parents[x]=get_root(parents[x]);
      }
  }

  void unite(Natural x,Natural y)
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
  bool is_sameset(Natural x,Natural y)
  {
    return get_root(x)==get_root(y);
  }

};

typedef struct Edge
{
  int from,to, cost;
  Edge(int from_,int to_,int cost_):from(from_)to(to_),cost(cost_){};
  operator <(const Edge right)const
  {
    return right.cost<cost;
  }
}Edge;

int main()
{
  int n;cin>>n;
  vector<Edge> connects[200000];
  rep(i,n)
    {
      int a,b,c;
      cin>>a>>b>>c;
      connects[a].push_back(Edge(a,b,c));
      connects[b].push_back(Edge(b,a,c));
    }
  UnionFindTree UF(n);
  
  

  return 0;
}
