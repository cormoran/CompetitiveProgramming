+++
draft = true
tags = ["None"]
href = "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2022"
date = "2017-07-08T01:28:29+09:00"
title = "AOJ2022 Princess, a Cryptanalyst お姫様の暗号解読"

+++

以前解いて解説まで書いていたらしいが忘れていた．

<!--more-->

## 解法

全探索で解ける．$O(N! * {|S|}^2)$ くらいで，$10^8$ くらいで本番ならなんとかなりそう．

AOJだと15sとかになったのでゆるふわ高速化が必要だった．

${|S|}^2$ の部分を事前計算しておけば速くなるのだろうなとあとで気づいた．

## 実装

{{<code "main.comp.cpp">}}