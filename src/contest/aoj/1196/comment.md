+++
href = "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1196&lang=jp"
date = "2017-04-09T14:30:25+09:00"
title = "AOJ1196 Bridge Removal"

+++

<!--more-->

気持ちよく解けた．

## 解説

木Tの葉を取り除いた木をT'とする．

$S := $ T'の辺の重みの総和

$L := $ T'の最長経路長

とすると，

最短道のりは $S * 2 - L$ になる．これに橋を壊すコストを足せば良い．

## 実装

{{<code "main.comp.cpp">}}