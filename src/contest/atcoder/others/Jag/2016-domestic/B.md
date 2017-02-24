---
title        : atcoder-Jag-2016-domestic-B
date         : 2016-04-24
contests     : atcoder
problemtypes :

---

# [B - 豪邸と宅配便](http://jag2016-domestic.contest.atcoder.jp/tasks/jag2016secretspring_b)

<!--more-->

## 問題概要

Aさんは書斎で勉強している。

書斎から玄関までは片道Mの時間がかかる

今日はN件、a0,a1,...,anの時間に宅配便が来るが、ちょうどその時間にAさんは玄関にいる必要がある。

時刻0から始めて、できるだけ書斎にいるようにした時、時刻Tまでにどれだけの時間書斎にいることができるか。

## 解法

計算していくだけ

時刻 now に 玄関にいるとして、次の宅配が往復後の時間 now + m * 2 より後であればその差の時間だけ書斎に戻れる。

最初と最後の残り時間だけ別に処理すればいい


~~~

#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
 
bool solve(){
    int n, m, t; cin >> n >> m >> t;
    int now = 0;
    int ans = 0;
    { // 最初
        int a; cin >> a;
        ans += a - m;
        now = a;
    }
    
    rep(i, n - 1) {
        int a; cin >> a;
        if(now + m * 2 < a) ans += a - (now + m * 2);
        now = a;
    }
    
    // 最後の残り
    if(t - (m + now) > 0) ans += t - (m + now);
    
    cout << ans << endl;
    return false;
}
 
int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~