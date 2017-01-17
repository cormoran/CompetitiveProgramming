/*
  Q : Nこの要素を持つ数列 V を T 回繰り返した数列の最大広義増加部分列を求める
      N<=100 T<=10^7 
  A : 狭義単調増加部分列 + Vの要素で重複数の多いもののみ で構成する ...
      
      
 */


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
    ios::sync_with_stdio(false);
    int n,t;cin>>n>>t;
    vector<int> v(n);
    map<int,int> count;
    rep(i,n){
        cin>>v[i];
        count[v[i]]++;
    }

    int max_freq = 0;
    for(auto item : count){
        max_freq = max(item.second,max_freq);
    }
    
    vector<int> lis;// longest increasing sub sequence
    lis.reserve(n*n);
    int ans = 0;
    
    rep(k,n){
        rep(i,n){
            auto pt = upper_bound(all(lis), v[i]);
            if(pt==end(lis))lis.push_back(v[i]);
            else *pt=v[i];
        }
        int seq = t-(k+1);
        ans = max(ans,seq * max_freq + (int)lis.size());
    }

    cout <<ans<<endl;
    
    return 0;
}
