---
title        : codeforces-336div2-D
date         : 2015-12-24
contests     : codeforces
status       : AC
problemtypes :
              - dp

---

Zuma

今回は割とすぐに見えた。Bより簡単。

# 問題概要

数列が与えられる。
回文になっている連続部分列１つを１度の操作で削除できる時、数列を空にするのに必要な最小操作数を求めよ。

<!--more-->

# 解法

DPする。

数列を{ a[i] for i = 0 to n }として、

DP[i][j] :=  a[i]からa[j]まで削除するのに必要な最小操作数

とすると、

DP[i][j] = min( DP[i][k] + DP[k+1][j]  (for k = i to j-1) ,
                1                      (if a[i]==a[j] and i+1==j)
		DP[i+1][j-1]           (if a[i]==a[j] and i+1!=j)
		)

となる。

初期値DP[i][i] = 1 として、

for j = 0 to n , for i = n to 0 という形で更新していけば良い。

