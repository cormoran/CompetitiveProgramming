---
title        : codeforces - 338div2 - D
date         : 2016-01-08
contests     : 338div2
draft        : true
status       : NONE
problemtypes :
              - none

---

[Multipliers](http://codeforces.com/contest/615/problem/D)

# 問題概要

自然数nが素因数分解された形で与えられる。

nのすべての約数の総積 mod 1000000000+7 を求めよ。


<!--more-->

# 解法
\(
nのすべての約数の積 = n^{\frac{nの約数の個数}{2}}
\)

という定理を使う。

nの約数の個数は、中学校で習った素因数分解を使った方法で求められる

ただ、愚直にやると累乗の部分がオーバーフローするのでうまくやらないといけない。

まt、nが平方数なら累乗部分の分子は奇数になるのであらかじめ平方根を取っておかないといけない。

