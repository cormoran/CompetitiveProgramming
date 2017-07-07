+++
tags = ["None"]
href = "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1612&lang=jp"
date = "2017-06-26T21:14:30+09:00"
title = "AOJ1612 3D Printing"

+++

幾何要素少なめな幾何

<!--more-->

## 解法

直線と円のケースだけ考えれば良い．

1. 重なる立方体同士をグルーピング，グラフを作る

2. 各グループについて，すべてのK個の連結の表面積を計算する

重なりによる表面積の減少分は，２つの立方体で互いの内部にある点を見つけて，それらからなる直方体の表面積を計算すれば良い．

## 実装

{{<code "main.comp.cpp">}}