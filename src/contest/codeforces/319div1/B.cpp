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

vector<bool> visited;
vector<vector<int>> E;
bool visit(int now,int pre){
  visited[now]=true;
  for(int nxt : E[now]){
    if(nxt==pre)continue;
    if(visited[nxt])return true;
    if(visit(nxt, now)==true)return true;
  }
  return false;
}

int main()
{
  int n;cin>>n;
  E.resize(n);
  rep(i,n){
    int k;cin>>k;k--;
    E[k].push_back(i);
    E[i].push_back(k);
  }
  visited.resize(n,false);
  if(visit(0,-1)==true){
    cout<<"NO"<<endl;
    puts("1");
    return 0;
  }
  rep(i,n){
    if(!visited[i]){
      cout<<"NO"<<endl;
      puts("2");
      return 0;
    }
  }
  {
    cout<<"YES"<<endl;
    rep(i,n){
      for(int p : E[i]){
        if(i<p)printf("%d %d\n",(int)i+1,p+1);
      }
    }
  }
  
  return 0;
}
