---
title        : CodeFestival-2015-Final-B
date         : 2015-11-17
contests     : codefestival
status       : "AC"
problemtypes :
- none
---

ダイスゲーム

<!--more-->

# 問題概要
  サイコロをN回振って出る値の和のうち、期待値最大を求める
# 解法
  確率分布を考えると取りうる値の真ん中になりそうなので、(N+6N)/2 = 3.5N で出る。
  本番ではDPしてoverflowになかなか気づかず、あれれ...ってなった。上に気づくのに30分くらいかかってつらかった。