---
title        : codeforces - 338div2 - B
date         : 2016-01-08
contests     : 338div2
draft        : false
status       : AC
problemtypes :
              - dp

---

[B. Longtail Hedgehog](http://codeforces.com/contest/615/problem/B)

# 問題概要

1,2,3,...とノードがラベリングされたグラフが与えられる。

V := 道を構成するノード数 * 終点(道の中で番号最大のノード)の次数

とする。番号が単調増加する道のみを見るとき、Vの最大値を求めよ。


<!--more-->

# 解法

番号順にノードを並べ、

\(
dp[i] = 番号iが終点になる道の長さの最大値
\)

とすると、

\(
dp[i] = max { dp[j] + 1 | j : iに隣接する,j<iを満たすすべての点 }
\)

でdpが求まる。

dp[i]を求めつつ、同時に
\(
ans = max(ans, dp[i] * iの次数)
\)

としていけば良い。

