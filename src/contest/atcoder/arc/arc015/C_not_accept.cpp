#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>
#include<algorithm>
//#include<>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;
typedef long long ll;
typedef pair<string,int> p_s_i;
 
 
 
int main()
{
  int n;
  map<string,int> node;//<ノード名,番地>
  cin>>n;
  int cnt=0;
  ll graph[400][400]={};//[i][j] : i = j * m
 
  //隣接行列生成
  for(int i=0;i<n;i++){
    string large,small;
    ll m;
    cin >>large>>m>>small;
    if(node.find(large)==node.end())
      node.insert(p_s_i(large,cnt++));
    if(node.find(small)==node.end())
      node.insert(p_s_i(small,cnt++));
    graph[node.find(large)->second][node.find(small)->second]=m;
  }
 
  //ワーシャルフロイド　積ver
  int i,j,k;
  int ans_i,ans_j;
  ll ans_m=0;
  rep(k,cnt)rep(i,cnt)rep(j,cnt){
    graph[i][j]=max(graph[i][j],graph[i][k]*graph[k][j]);
    if(graph[i][j]>ans_m){
      ans_i=i;
      ans_j=j;
      ans_m=graph[i][j];
    }
  }
 
  //答え出力
  map<string,int>::iterator itr=node.begin();
  string ans_is,ans_js;
  rep(i,cnt)
    {
      if(itr->second==ans_i)
	ans_is=itr->first;
      else if(itr->second==ans_j)
	ans_js=itr->first;
      itr++;
    }
  cout<<1<<ans_is<<"="<<ans_m<<ans_js<<endl;
  return 0;
}
