+++
title = "BCU30 D 数直線"
date = "2017-03-11T23:55:00+09:00"
href = "http://bcu30.contest.atcoder.jp/tasks/bcu30_d"
+++

<!--more-->

累積和の気持ちがわかっていない気がする．

## 解法

$X$を左右からなめて，うまく系数倍することで与えられた各点の，他の点からの距離の総和を求めることができてしまう．（紙に書くとわかりやすい）

ある点xでの解がわかっている時，その両側の点の解は，xからみて左右にいくつ最初に与えられた点があるかから計算できる．

off by one に注意．

## 実装

{{<code "main.comp.cpp">}}