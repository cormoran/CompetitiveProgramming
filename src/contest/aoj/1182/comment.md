+++
title = "AOJ1182 Railway Connection"
date = "2017-04-03T00:51:50+09:00"
href = "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1182&lang=jp"
+++

<!--more-->


ダイクストラで行けそうな気がしてやってしまったけど無理だった．反省．

$N <= 100$なのでワーシャルフロイドできる．会社ごとに距離でワーシャルフロイドした後，完全グラフを合体させてコストでもう一度やるのは面白い気がした．

## 実装

{{<code "main.comp.cpp">}}