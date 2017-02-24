---
title        : codeforces-206div1-A
date         : 2016-04-06
contests     : codeforces
problemtypes :

---

# [Vasya and Robot](http://codeforces.com/contest/354/problem/A)

<!--more-->

## 問題概要

nこの数からなる配列 w0, w1, ..., wn , 正の整数l, r, Ql, Qrが与えられる。

この配列から以下の２種類の操作により全ての要素を取り除く

1. 一番左の要素(wiとする)を取り除く : コスト wi * l
2. 一番右の要素(〃)を取り除く ： コスト wi * r

ただし、直前に行った操作と同じ操作を行う場合,1ならQl, 2ならQrだけ追加でコストがかかる

必要なコストを最小化せよ。

## 解法

wi を左からとり、wi+1を右からとるとすると、j <= iなるwjは全て左から、k > iなるwkは全て右から取られることになる。

この境界iを決めると、合計コストは事前に累積和を計算しておけばO(1)で求められるので、iを0からnまで全探索すれば良い。


~~~

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)


template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool solve(){
    int n, l, r, ql, qr; cin >> n >> l >> r >> ql >> qr;
    vector<int> W(n); cin >> W;
    vector<ll> lsum(n+1), rsum(n+1);
    rep(i, n) {
        lsum[i+1] = lsum[i] + l * W[i];
        rsum[i+1] = rsum[i] + r * W[n - i - 1];
    }
    ll ans = 1LL << 62;
    rep(i, n + 1) {
        int lnum = i;
        int rnum = n - lnum;
        ll sum = lsum[lnum] + rsum[rnum];
        int seq = abs(lnum - rnum) ;
        sum += max(0LL, (ll)seq - 1) * (lnum >= rnum ? ql : qr);
        ans = min(sum , ans);
    }
    cout << ans << endl;
    return false;
}

~~~