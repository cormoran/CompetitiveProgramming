---
title        : codeforces - 332 - C
date         : 2016-01-07
contests     : codeforces
draft        : true
status       : NONE
problemtypes :
              - none

---


# 問題概要

<!--more-->

# 解法



# ソースコード
~~~
//  codeforces - 332 - C  / 2016-01-07
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

struct order{
    int idx,a,b;
};

bool cmp1(const order &a,const order &b){
    return (a.a != b.a ? a.a > b.a : a.b < b.b);
}

bool cmp2(const order &a,const order &b){
    return (a.b != b.b ? a.b < b.b : a.a < b.a);
}

bool solve(){
    int n,p,k; cin >> n >> p >> k;
    vector<order> ab(n);
    rep(i,n){
        cin >> ab[i].a >> ab[i].b;
        ab[i].idx = i+1;
    }
    sort(all(ab),cmp1);
    sort(&ab[p-k],&ab[n-(p-k)-1],cmp2);
    
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~