#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//=10E10

template<typename Natural>
class UnionFindTree
{
  public:
  Natural Node_num;
  vector<Natural> parents;
  vector<Natural> ranks;
  Natural groupnum;
  UnionFindTree(Natural n):Node_num(n)
  {
    groupnum=n;
    parents.resize(n);
    ranks.resize(n);
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
	groupnum-=1;
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


int main()
{
  i32 N,M;cin>>N>>M;
  UnionFindTree<i32> UF(N);
  rep(i,M){
    int a,b;cin>>a>>b;
    a--;b--;
    UF.unite(a,b);
  }
  cout<<UF.groupnum-1<<endl;;
  return 0;
}
