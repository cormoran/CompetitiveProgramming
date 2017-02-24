---
title        : codeforces - 332 - B
date         : 2016-01-07
contests     : codeforces
problemtypes :
- dp

---

# Maximum Absurdity

ちょっと（かなり？）はまった

## 問題概要

長さnの正の整数列が与えられる。a番目,b番目それぞれを左端とする長さk(2k<=n)の連続部分数列を、２つの重複区間がないように選ぶ時、それらの区間の値の総和を最大化するa,bの組を求めよ。ただし a<b、複数解がある場合はpair(a,b)が最小のもの

<!--more-->

## 解法

bを全探索する。aはbより左側にあるので、bより左の区間で、総和が最大であるような長さkの区間を記憶しておけば、それがそのbを選んだ時に全総和を最大化するaになる。


~~~
//  codeforces - 332 - B  / 2016-01-07
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)

bool solve(){
    int n,k; cin >> n >> k;
    vector<ll> sum(n+1),psum(n+1);
    sum[0] = 0;
    rep(i,n){
        ll x; cin >> x;
        sum[i+1] = sum[i] + x;
        psum[i+1] = sum[i+1] - ( i>=k ? sum[i+1-k] : 0);
    }

    ll m = -1;
    int ak = k;
    int ans_a=-1,ans_b=-1;
    repeat(b,k+1,n-k+1 +1){
        ll t = psum[ak] + psum[b+k-1];
        if(t > m){
            ans_a = ak - k + 1;
            ans_b = b;
            m = t;
        }
        if(psum[ak] < psum[b]) ak = b;
    }
    cout << ans_a <<  " " << ans_b << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~