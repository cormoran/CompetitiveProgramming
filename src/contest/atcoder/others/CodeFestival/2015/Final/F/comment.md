---
title        : CodeFestival-2015-Final-F
date         : 2015-11-20
contests     : CodeFestival
state        : AC
problemtypes :
              - graph

---

歩くピアニスト

<!--more-->

# 問題概要

1から7までの７つの点を持つサイクルについて、1から始めてiにC[i]回訪れ、1に戻るような経路があるか判定する。

# 解法

一つの辺を通る回数をxとすると、他の辺を通る回数がxの関数で表せる。

サイクルになっているので全部見ていくと各xiの値が決定でき。、各点の次数がわかる。

通るべき点すべてに到達でき、各点の次数が非ゼロの偶数なら求める経路がある。
