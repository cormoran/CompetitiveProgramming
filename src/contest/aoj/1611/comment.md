+++
title = "AOJ1611 Daruma Otoshi"
tags = ["dp"]
href = "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp"
date = "2017-04-03T08:46:55+09:00"

+++

<!--more-->

昨年国内予選で解いた問題．復習．

$DP[i][j] := $ 区間$[i, j]$がたたき出せるかどうか

を求める．

$i \lt k \le j$ なるkについて，

$[i+1, k-1]$がたたき出せて，かつ$[k+1, j]$がたたき出せて，$i$, $k$が同時にたたき出せるなら$[i, j]$がたたき出せる．

最後に最大個数を求める部分は，$i$までを使った時いくつたたき出せるかを順に求めるDP．

## 実装

{{<code "main.comp.cpp">}}