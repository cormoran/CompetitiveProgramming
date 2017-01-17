//union find tree
#include<iostream>
#include<vector>
#define rep(i,j) for(int i=0;i<j;i++)
using namespace std;

template<typename Natural>
class UnionFindTree
{
public:
  Natural Node_num;
  vector<Natural> parents;
  vector<Natural> ranks;

  UnionFindTree(Natural n):Node_num(n+1)
  {
    n++;//index=1_to_nに対応
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

};

int main(){
  int N,Q;
  cin>>N>>Q;
  UnionFindTree<int> UF(N);

  rep(i,Q){
    int P,A,B;
    cin>>P>>A>>B;
    if(P==0){
      UF.unite(A, B);
    }
    if(P==1){
      cout<< (UF.is_sameset(A,B) ? "Yes" : "No") << endl;
    }
  }

  return 0;
}
