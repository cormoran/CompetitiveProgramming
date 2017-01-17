/*
  --- 
  title : -C.comp.cpp
  date : 2015-10-25
  status : NULL
  ---
  
  # Memo

  
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
    int n;cin>>n;
    vector<char> bits[2];
    bits[0].resize(n);
    bits[1].resize(n);
    int tmp;
    rep(i,n){
        cin>>tmp;
        bits[0][i]=(tmp==0?0:1);
    }
    int t;
    
    
    cout<<t<<endl;
    rep(i,n-1)cout << (int)bits[t%2][i]<<" ";
    cout <<(int)bits[t%2].back()<<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
