---
title        : codeforces - 338div2 - C
date         : 2016-01-08
contests     : 338div2
draft        : false
status       : AC
problemtypes :
              - trietree

---

[Running Track](http://codeforces.com/contest/615/problem/C)

TLE,MLEしまくった。

# 問題概要

文字列s、tが与えられる。

sの連続部分列かその反転のみを使ってtを作るとき、必要なパーツの数とそのパーツを求めよ。

<!--more-->

# 解法

トライ木を使って貪欲的にマッチングさせていく。

s、sの反転のすべての連続部分列をトライ木に登録する。ノードには連続部分列の始まり、終わりのindexを格納しておく。

tを先頭から見てトライ木をたどっていく。進めるノードがなくなったらそこを区切りとする。

木の根に戻って、tの区切った次の文字からこれを繰り返していけば良い。

shared_ptr使ったり、ノードに子の配列をもたせたりしたらMLEなどして大変だった。（どこかにバグがあったかもしれないが）

