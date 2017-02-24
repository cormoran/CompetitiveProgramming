---
title        : codeforces-336div2-D
date         : 2015-12-24
contests     : codeforces
status       : AC
problemtypes :
              - dp

---

# Zuma

今回は割とすぐに見えた。Bより簡単。

## 問題概要

数列が与えられる。
回文になっている連続部分列１つを１度の操作で削除できる時、数列を空にするのに必要な最小操作数を求めよ。

<!--more-->

## 解法

DPする。

数列を${ a[i] for i = 0 to n }$として、

$DP[i][j] :=  a[i]からa[j]まで削除するのに必要な最小操作数$

とすると、

$DP[i][j]$ = min(

$DP[i][k] + DP[k+1][j]$  (for k = i to j-1) ,

1 (if $a[i]==a[j]$ and $i+1==j$),

$DP[i+1][j-1]$ (if $a[i]==a[j]$ and $i+1!=j$)		

)

となる。

初期値$DP[i][i]$ = 1 として、

for j = 0 to n , for i = n to 0 という形で更新していけば良い。



~~~
//  codeforces-336div2-D  / 2015-12-24
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
const int INF = 1<<29;
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


bool solve(){
    int n; cin >> n;
    vector<int> C(n); cin >> C;
    vector< vector<int> > DP(n,vector<int>(n,INF));
    rep(i,n) DP[i][i] = 1;

    for(int a = n-1; a >= 0; a--){
        repeat(b,a+1,n){
            repeat(i,a,b){
                DP[a][b] = min(DP[a][b], DP[a][i] + DP[i+1][b]);
            }
            if( C[a] == C[b] ){
                DP[a][b] = ( a+1 == b ? 1 :
                             min(DP[a][b], DP[a+1][b-1])
                             );
            }
        }
    }

     rep(i,n){
         debug(DP[i]);
     }
    
    cout << DP[0][n-1] << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~