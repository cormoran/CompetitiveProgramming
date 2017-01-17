---
title        : codeforces-186div2-B
date         : 2015-12-03
contests     : codeforces
status        : AC
problemtypes :
              - none

---

Ilya and Queries

<!--more-->

# 問題概要

s = s1 s2 s3 ... sn

si ∈{'.','#'} とする

上の列に対し、m個のクエリli,riが与えられる。

各クエリに対し、li <= k < ri を満たすkについて、sk = sk+1 となるようなkの総数を答えよ。


# 解法

累積和を取っておいてやるだけ
