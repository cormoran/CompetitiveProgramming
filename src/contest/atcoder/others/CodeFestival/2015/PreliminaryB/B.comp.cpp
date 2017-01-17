/*
  --- 
  title : -B.comp.cpp
  date : 2015-10-25
  status : AC
  ---
  
  # Memo
  連想配列を使う
  
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


bool solve(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    rep(i,n){
        int a;cin>>a;
        mp[a]++;
    }

    int ans =-1;
    int mx = 0;
    bool same=false;
    for(auto p : mp){
        if(p.second == mx){
            same=true;
        }else if(p.second >mx){
            same = false;
            ans = p.first;
            mx = p.second;
        }
    }
    if(same==true || mx <= n/2){
        cout << "?" <<endl;
    } else {
        cout <<ans <<endl;
    }
    
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
