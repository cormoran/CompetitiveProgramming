+++
title = "2017 Hackatari Codeathon B 2Trees"
date = "2017-03-14T23:38:03+09:00"
href = "http://codeforces.com/problemset/gymProblem/101257/B"
+++

<!--more-->

RCO年度末なんとか競プロ会@indeedにて．

## 問題概要

葉の数が同じ木が２つ与えられる．


- Each leaf in the first tree is merged into exactly one leaf from the second tree.
- Each leaf in the second tree is merged into exactly one leaf from the first tree.


となるように葉同士を繋ぐ時，つないだ後の木の彩色数を最小にせよ．

## 解法

まず，それぞれの木は，木なので２彩色可能．よって，葉同士を適当に繋げてその葉の色を第３色にすれば必ず３彩色可能．

２彩色可能なのはどのような場合か考える．

それぞれの木を２色に色分けして，各色について，葉の数を求める．

２つの木で，各色ごとの葉の数が一致していれば，それらをつなげることで，つないだ後に生じる閉路は全て偶数長になるので，２部グラフになって２彩色可能．


## 実装
見返すとそんなに長くないけど，けっこうつらい．

{{<code "main.comp.cpp">}}