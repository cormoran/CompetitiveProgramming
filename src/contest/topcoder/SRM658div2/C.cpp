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

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

template<typename Natural>
class UnionFindTree
{
public:
  Natural Node_num;
  vector<Natural> parents;
  vector<Natural> ranks;

  vector<Natural> numberings;
  Natural allgroup;
  
  UnionFindTree(Natural n):Node_num(n)
  {
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
	return parents[x]=get_root(parents[x]);
      }
  }

  void unite(Natural x,Natural y)
  {
    if( (x=get_root(x))!=(y=get_root(y)) )
      {
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

  bool is_sameset(Natural x,Natural y)
  {
    return get_root(x)==get_root(y);
  }


  void numbering(){
    numberings.clear();
    numberings.resize(Node_num,-1);
    allgroup=0;
    rep(i,Node_num){
      int p=get_root(i);
      if(numberings[p]<0){
        numberings[p]=allgroup++;
      }
      numberings[i]=numberings[p];
    }
  }

};

class OddEvenTreeHard{
 public:

  vector <int> getTree(vector <string> x){
    UnionFindTree<int> UT_Even(x.size());
    UnionFindTree<int> UT_EvenOdd(x.size());
    rep(i,x.size()){
      rep(j,x[i].size()){
        if(x[i][j]=='E'){
          UT_Even.unite(i, j);
          UT_EvenOdd.unite(i, j);
        }
        else if(x[i][j]=='O'){
          UT_EvenOdd.unite(i, j);
        }
      }
    }
    UT_Even.numbering();
    UT_EvenOdd.numbering();
    

    
  }

  
}
