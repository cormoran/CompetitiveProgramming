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
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()
typedef pair<int,int> pii;
const int INF=1<<30;//=10E10

//Node 0 to n-1でも1 to nでもOKなはず
template<typename Natural>
class UnionFindTree
{
  public:
  Natural Node_num;
  vector<Natural> parents;
  vector<Natural> ranks;

  UnionFindTree(Natural n):Node_num(n)
  {
    //n++;//index=1_to_nに対応
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

  vector< vector<Natural> > group(){
    vector< vector<Natural> > ans;
    vector<int> used(Node_num,-1);
    rep(i,Node_num){
      Natural i_root=get_root(i);
      if(used[i_root]==-1){
	vector<Natural> v;
	v.push_back(i);
	ans.push_back(v);
	used[i_root]=ans.size()-1;
      }
      else
	ans[used[i_root]].push_back(i);
    }
    return ans;
  } 

  
};

int main()
{
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n)cin>>p[i];
  UnionFindTree<int> uf(n);
  rep(i,n)rep(j,n){
    char c;cin>>c;
    if(c=='1')
      uf.unite(i,j);
  }
  
  vector< vector<int> > group=uf.group();

  /*
  rep(i,group.size()){
    rep(j,group[i].size())
      cout<<group[i][j]+1<<" ";
    cout<<endl;
  }
  */
  
  vector<int> ans(n);
  
  rep(i,group.size()){
    
    vector<int> oneg;
    sort(all(group[i]));
    rep(j,group[i].size()){
      oneg.push_back(p[group[i][j]]);
    }
    sort(all(oneg));
    
    rep(j,group[i].size()){
      ans[group[i][j]]=oneg[j];
    }
      
  }

  rep(i,n-1)cout<<ans[i]<<" ";
  cout<<ans[n-1]<<endl;
  
  return 0;
}
