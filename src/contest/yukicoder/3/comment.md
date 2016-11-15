+++
title = "yukicoder No.3 ビットすごろく"
date = "2016-11-14T02:56:08+09:00"
href = "http://yukicoder.me/problems/no/3"
+++


<!--more-->

## 回想

幅優先探索するだけ。

ビット数は最初 __builtin_popcount で求めていたけど、最下位bitを削るやつの方がちょっとだけ速かった（誤差の範囲？）

## 実装

{{<code "main.comp.cpp">}}
