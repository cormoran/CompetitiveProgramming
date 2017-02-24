---
title        : CodeFestival-2015-Final-B
date         : 2015-11-17
contests     : atcoder
status       : "AC"
problemtypes :

---

# ダイスゲーム

<!--more-->

## 問題概要
  サイコロをN回振って出る値の和のうち、期待値最大を求める
## 解法
  確率分布を考えると取りうる値の真ん中になりそうなので、(N+6N)/2 = 3.5N で出る。
  本番ではDPしてoverflowになかなか気づかず、あれれ...ってなった。上に気づくのに30分くらいかかってつらかった。

~~~
#include<iostream>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)

bool solve(){
    ll n;cin>>n;
    int ans=-1;
    if(n==1)ans=1;
    if(n>=2)ans = 7;
    for(int i=2;i<n;i++){
        ans += (i%2 ? 4 : 3);
    }
    cout <<ans<<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~