---
title        : codeforces-336div2-C
date         : 2015-12-24
contests     : codeforces
status        : AC
problemtypes :
              - dp

---

# Chain Reaction

Bより簡単

## 問題概要

数直線上にブザーがn個ある。各座標を$a[i]$とする。$(i=1,2,...,n)$

ブザーiはなり始めると、左側に距離$d[i]$までの範囲のブザーを破壊する。（自身は破壊されない）
ブザーは一番右から順に起動する。

置かれている一番右のブザーよりも右側にdが任意に設定できるブザーを一つおける時、破壊されるブザーの最小個数を答えよ。

<!--more-->

## 解法

$dp[i] :=$ 追加したブザーで、ブザーiまで破壊する場合に残るブザーの最大個数

初期値 $dp[0] = 0$

とすると、座標が昇順になるようにならべたブザーiについて

$j := a[j] < a[i] - d[i]$ を満たす最大の$j (1<=j<i)$

jが存在しない場合は j = 0とする

この時、

$dp[i] = dp[j] + 1$

となる。

答えは min( n - $dp[i]$ ) for i = 1 to n

~~~
//  codeforces-336div2-C  / 2015-12-24
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

bool solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    {
        vector< pair<int,int> > ab(n);
        rep(i,n) cin >> ab[i].first >> ab[i].second;
        sort(all(ab));
        rep(i,n){
            a[i] = ab[i].first;
            b[i] = ab[i].second;
        }
    }
    vector<int> dp(n+1); //残り個数
    dp[0] = 0;
    int ans = 1 << 30;
    rep(i, n){
        int x = a[i] - b[i] - 1; // xまで安全
        if(x < a[0]) dp[i] = 1;
        else {
            int idx = upper_bound(all(a),x) - begin(a) - 1;
            dp[i] = dp[idx] + 1;
        }
        ans = min(ans, n - dp[i]);
    }
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~