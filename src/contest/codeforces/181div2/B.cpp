//#include<bits/stdc++.h>
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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


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



int main()
{
  int N,M;cin>>N>>M;

  UnionFindTree ut(N);
  vector<bool> flg2(N+1,false);
  rep(i,M){
    int a,b;
    cin>>a>>b;
    ut.unite(a, b);
    flg2[a]=flg2[b]=true;
  }
  

  vector<bool> flg(N+1,false);
  vector<vector<int>> ans;
  ans.reserve(N/3);
  rep(i,N+1){
    if(i==0 || ut.is_sameset(0, i))continue;
    vector<int> s;
    rep(j,N+1){
      if(j==0)continue;
      if(ut.is_sameset(i, j)){
        s.push_back(j);
      }
    }
    if(s.size()>1){
      if(s.size()==2){
        rep(k,N+1){
          if(k==0)continue;
          if(k==s[0]||k==s[1])continue;
          if(!flg2[k]){
            ut.unite(i, k);
            s.push_back(k);
            flg2[k]=true;
            break;
          }
        }
      }
      if(s.size()!=3){
        cout<<-1<<endl;
        return 0;
      }
      rep(k,3)flg[s[k]]=true;
      ans.push_back(s);
      ut.unite(0, i);
    }
  }

  vector<int> tmp;
  rep(i,N+1){
    if(i==0)continue;
    if(!flg[i]){
      tmp.push_back(i);
      if(tmp.size()==3){
        ans.push_back(tmp);
        tmp.clear();
      }
    }
  }
  if(tmp.size()!=0 || ans.size()!=N/3){
    cout<<-1<<endl;
    return 0;
  }

  rep(i,ans.size()){
    rep(j,3){
      cout<<ans[i][j]<<(j==2 ? "\n":" ");
    }
  }
  
  
  return 0;
}
