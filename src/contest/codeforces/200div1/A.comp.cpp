/*
  file : /A.comp.cpp
  date : 2015-10-22
  status :
  {
  
  }
  memo :
  {
  連分数展開する
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



bool solve(){
    ll a,b;
    cin>>a>>b;
    ll ans =0;
    while(a>1){
        ll w = a/b;
        ans += w;
        a = a % b;
        swap(a,b);
        //cout << w <<endl;
    };
    ans += b;
    cout <<ans <<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
