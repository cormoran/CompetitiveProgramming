---
title        : codeforces-206div1-C
date         : 2016-04-06
contests     : codeforces
problemtypes :

---

# [Vasya and Beautiful Arrays](http://codeforces.com/contest/354/problem/C)

<!--more-->

## 問題概要

nこの正数からなる配列Aと、正数kが与えられる。

Aの各要素 ai を 0 <= ai - bi <= k を満たす 正数 bk に変えた配列Bを作る。

全要素のGCDができるだけ大きくなるようにBを作るとき、全要素のGCDの最大値を求めよ。

## 解法

下から全部、約数になりうるか試していく。

普通にAの全要素に対してチェックすると解の候補が10^6, 要素数3*10^5 で間に合わないのでチェックを工夫する。

x が解になりうるかどうかは、 [x * m. x * m + k] (m = 1, 2, 3, ...) の区間にAの全要素が入っているかどうかで決まる。

m は x * m <= max(A) までの範囲でいいので、

C[i] : Aの要素のうち、i以下の数の数　をあらかじめ計算しておけば、各 x のチェックは O(max(A) / x) で済む。

x は min(A)以下しかありえないので、計算量は

O(max(A) * (1/2 + 1/3 + ... + 1/min(A))) = O(max(A) * log(min(A))) で、10^6 log 10^6 くらいで通る。

自分は最初エラトステネスの篩みたいにして無駄なものを排除していたけど、別にしなくても通った。

virtual contest 中は全然わからなかったのでとりあえずAの全要素に対してチェックかけるプログラムを書いてTLEした。方向的には合ってたのでもう少し工夫できれば...


~~~

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}


bool check(int cand, vector<int> &C, int k, int n) {
    int num = 0;
    int imax = C.size() - 1;
    k = min(k, cand);
    for(int i = cand; i < (int)C.size(); i += cand) {
        num += C[min(i + k, imax)] - C[i - 1];
    }
    return num >= n;
}

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n); cin >> A;
    int mini = *min_element(all(A));
    int maxi = *max_element(all(A));

    vector<int> C(maxi + 1); // C[i] : i以下の数の数
    rep(i, n) C[A[i]]++;
    rep(i, C.size() - 1) C[i+1] += C[i];
    
    int ans = 1;
    repeat(i, 2, mini + 1) {
        if(check(i, C, k, n)) {
            ans = i;            
        }
    }
    cout << ans << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~