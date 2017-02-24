---
title        : DDPC2016-Final-C
date         : 2016-02-22T22:00:56+09:00
status       : AC
problemtypes :
- 木DP
- DP

---

# [C - 特別講演「括弧列と塗り分け」](http://discovery2016-final.contest.atcoder.jp/tasks/discovery_2016_final_c)

少なくとも２０点の方針は立ったが実装が間に合わなかった。コンテスト後にちゃんと実装したらなんか満点が取れてしまった。

<!--more-->

## 問題概要

丸括弧のみからなる矛盾ない文字列Sと非負整数Kが与えられる。（矛盾ないの定義は問題文参照）

文字を２色で色分けするとき、任意の対応する開・閉括弧$i,j$について、閉区間$[i,j]$で各色の文字数の差がK以下になるような色分けは何通りあるか。

1,000,000,007で割ったあまりを答えよ。

## 解法

木DPをして、$O(N^3)$に見えて実は$O(N^2)$とかいうのが有名らしいがまだ復習できていない。

自分は再帰で解いた。

$d[i]$ を赤と青の差がiになる塗り方の場合の数とすると、

() は赤だけ、青だけ、赤青x2 の４つの塗り方があり、$d[+-2] = 1, d[0] = 2$

(..)(...) は、左右の括弧を別々に計算して,d1 と d2をたたみ込めば良い。３つ以上の並列も端から順に畳み込んでいけばいい。ここではKによる制約がないので注意。

( (...) )は()と(...)のdをたたみ込む。ここではKの制約があって、$d[i]=0(i<-K,K<i)$となる。

これを順にやっていけば良い。

最初N*2程度の配列をやり取りするようなコードを書いたが、負のインデックスを使うためにいろいろやってどこかにバグを入れたようで、ひとまずmapに逃げたらそのまま満点になってしまった。括弧の組がN/2で、それぞれについて$O(N^2)$のたたみ込みが入るので$O(N^3)$だと思っていたが、$O(N^2)$の部分がmapを使ったことでそれぞれ最小回数で済むようになり、何かの魔法で全体が$O(N^3)$にはならない（これが木DPで計算量が落ちるってやつ？ではない？）ようになったらしい。もうちょっとちゃんと見直して理解します。ちなみに最初は配列で$O(N^3)$して、たたみ込みをFFTにすれば(N^2logN)になって満点になるかな？みたいな気分で解いていた。



~~~

#include<iostream>
#include<string>
#include<cassert>
#include<map>
using namespace std;
 
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
 
 
const int MOD = 1000000007;
 
// ()
map<int,ll> base(int K){
    if(K < 2) return { {0, 2} };
    else return { {0, 2}, {-2, 1}, {2, 1} };
}
 
// ( ... ) ( ... ) など
map<int,ll> merge(map<int,ll> &A, map<int,ll> &&B){
    map<int,ll> d;
    for(auto a : A){
        for(auto b : B){ // 括弧の並列では >K でもOK
            d[a.first + b.first] += a.second * b.second;
            d[a.first + b.first] %= MOD;
        }
    }
    return d;
}
 
// ( ( ... ) ( ... ) ) など
map<int,ll> wrap(map<int,ll> &A, int K){
    map<int,ll> d;
    map<int,ll> B = base(K);
    for(auto a : A){
        for(auto b : B){
            if( abs(a.first + b.first) <= K ){
                d[a.first + b.first] += a.second * b.second;
                d[a.first + b.first] %= MOD;
            }
        }
    }
    return d;
}
 
// S[now] から S[now]に対応する閉じ括弧まで
map<int,ll> calc(const string &S, int &now, int K){
    assert( S[now] == '(' );
    map<int,ll> d = { {0, 1} };
    bool flg = false;
    now++;
    while(S[now] != ')'){
        d = merge(d, calc(S,now, K));
        flg = true;
    }
    now++;
    return flg ? wrap(d, K) : base(K);
}
 
bool solve(){
    string S; cin >> S;
    int K; cin >> K;
    int now = 0;
    ll ans = 1;
    while(now < S.size()){
        map<int,ll> d = calc(S, now, K);
        ll partial = 0;
        for(auto a : d){
            if(abs(a.first) <= K){
                partial = (partial + a.second) % MOD;
            }
        }
        ans = ans * partial % MOD;
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