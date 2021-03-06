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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()
const int INF=1<<30;
typedef vector<vector<int>> EdgeList;

//
// 重心で木を分割することを繰り返す
//

EdgeList E;
vector<int> subtree_size;
vector<bool> used;

int calc_subtree_size(int now,int pre){
  int sum=1;
  for(int nxt : E[now]){
    if(nxt==pre || used[nxt])continue;  //used[nxt] : 親の木に入らないように
    sum+=calc_subtree_size(nxt, now);
  }
  return subtree_size[now]=sum;
}

pii search_centroid(int now,int pre,int total){ //total : 部分木のノード数
  pii ret = {INF,-1};
  int max_sub=total-subtree_size[now];
  for(int nxt : E[now]){
    if(nxt==pre || used[nxt])continue;
    ret = min(ret,search_centroid(nxt, now,total));
    max_sub=max(max_sub,subtree_size[nxt]);
  }
  return min(ret,make_pair(max_sub, now));
}

//rootを含む部分木の重心を見つけてそこで木を分割するdfs
bool dfs(int root,char c,vector<char> &ans){
  if(c>'Z')return false;
  bool ret = true;
  int total = calc_subtree_size(root, -1);
  int centroid = search_centroid(root, -1,total).second;
  ans[centroid]=c;
  used[centroid]=true;
  for(int nxt : E[centroid]){
    if(used[nxt])continue;
    ret&=dfs(nxt, c+1, ans);
  }
  return ret;
}



void init(int N){
  E.resize(N);
  used.resize(N,false);
  subtree_size.resize(N);
}

void input(int N){
  rep(i,N-1){
    int a,b;
    cin>>a>>b;
    a--,b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
}

int main()
{
  int N;
  cin>>N;
  init (N);
  input(N);
  
  vector<char>ans(N);
  if( dfs(0, 'A', ans) ==false){
    cout << "Impossible!" << endl;
  }
  else{
    rep(i,N-1){
      cout<<ans[i]<<" ";
    }
    cout<<ans.back()<<endl;
  }
  return 0;
}
