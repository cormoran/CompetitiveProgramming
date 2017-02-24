---
title        : codeforces-186div2-C
date         : 2015-12-03
contests     : codeforces
status        : AC
problemtypes :

---

# Ilya and Matrix

<!--more-->

## 問題概要

4^n個の正の整数が与えられる。2^n*2^nの行列の要素に各整数を割り当てる時、考えられるbeautyの最大値を答えよ。

ただし2^n*2^n行列のbeautyは以下のように計算する。

1. 行列の要素の最大値をmとする。n=0 ならばbeauty = m とする。
2. n>0 ならば行列を４つの2^n-1次の正方行列に分割し、各行列のbeautyを計算する。beauty = ４つの部分行列のbeautyの和 + m とする。

## 解法

値の大きいものほど多くの回数足されてほしい。そのためには部分行列に分けたときにうまく大きい値が別の行列に分かれるようにすれば良い。そのようにした場合、最大値はn+1回、その次に大きい３つはn回、...と足される回数がわかる。ので、計算するだけ。はじめ、beautyの計算方法が再帰なしでいけそうだし実装してみたいとか思ってたら問題の目的を忘れて本当に実装をはじめ、バグって...ってなってACにちょっと時間がかかった。考えてる最中に問題内容忘れることが多いのでパッと見てわかるようにメモの書き方を考えないといけないと思った。



~~~

bool solve(){
    int n2; cin >>n2;

    vector<int> v(n2);
    cin >> v;
    sort(all(v),greater<int>());
    ll ans = 0;
    rep(i,n2){
        int p = n2 / (i+1);
        ans += v[i] * (ll)(log2(p)/2 + 1);
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