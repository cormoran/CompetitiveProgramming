+++
href = "http://arc071.contest.atcoder.jp/tasks/arc071_b"
date = "2017-04-09T01:37:22+09:00"
title = "ARC071 D - 井井井 / ###"

+++

<!--more-->

最初 すべてマスが $(M - 1 ) * (N - 1)$ 回使われると思い込んでしまった．

いくつかのパターンで具体的に各マスが何回使われるか数えて見てやっと解けた．

愚直に式を書いて変形するのが一番楽だったみたい...

c++で書いたらどこかでオーバーフローしたっぽく，わからないのでpython3で殴った．

## 実装

{{<code "a.py">}}