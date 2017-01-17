/*
  file : /D.comp.cpp
  date : 2015-10-22
  status :
  {
  
  }
  memo :
  {
  
  }
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()


void dfs(vector<int> &parent,const vector<vector<int>> &Edges, int now,int pre){
    parent[now] = pre;
    for(int nxt : Edges[now]){
        if(nxt != pre){
            dfs(parent, Edges, nxt, now);
        }
    }
}

bool search_up(vector<int> &parent,vector<bool> &status,int now){
    if(now<0)return false;
    if(status[now])return true;
    return search_up(parent, status, parent[now]);
}

bool empty_up(vector<int> &parent,vector<bool> &status,vector<vector<int>> &Edges,int now,int pre){
    if(now<0)return false;
    bool flg = empty_up(parent, status,Edges, parent[now],now);
    if(status[now]||flg){
        for(int child : Edges[now]){
            if(child != pre && child != parent[now]){
                status[child]=true;
            }
        }
        status[now]=false;
        flg =true;
    }

    return flg;
}

bool solve(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<vector<int>> Edges(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        Edges[a].push_back(b);
        Edges[b].push_back(a);
    }
    vector<int> parent(n);
    dfs(parent,Edges,0,-1);
    vector<bool> status(n,false);
    int q;cin>>q;
    rep(i,q){
        int a,b;
        cin>>a>>b;
        b--;
        if(a==1)status[b]=true;
        else if(a==2)empty_up(parent, status,Edges ,b,b);
        else if(a==3){
            cout << (search_up(parent, status, b) ? 1 : 0)<<endl;
        }
    }
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
