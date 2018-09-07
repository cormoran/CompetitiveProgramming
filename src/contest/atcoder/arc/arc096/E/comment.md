---
title: "ARC 096 E - Everything on It"
date: "2018-04-23T22:30:00+09:00"
href: "https://beta.atcoder.jp/contests/arc096/tasks/arc096_c"
tags:
    - None
draft: true    
---

<!--more-->

## 解法

[editorial](https://img.atcoder.jp/arc096/editorial.pdf)の補足

$$A=\sum_{i=0}^{N}(-1)^i {}_nC_i ways(i)$$

これは普通の包除原理

答え　=（すべての組み合わせの数）- (トッピング i の乗ったラーメンが１杯以下の組み合わせの数) * $N$ + (トッピング i の乗ったラーメンが１杯以下　かつ　トッピング j の乗ったラーメンが１杯以下) * ${}_NC_2$ + ...

交換可能というのは，(トッピング i の乗ったラーメンが１杯以下の組み合わせの数) は i = 1,...,N どれでも同じということ

$ways2(i, j)$ は  $ways(i)$ を，”トッピング 1,...i の少なくとも一つが乗ったラーメン数”で分けて計算したもの

$ways2(i, j)$ = 

## 実装

{{<code "main.comp.cpp">}}

