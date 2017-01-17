---
title        : atcoder-Jag-icpc2015-asia-C
date         : 2015-11-22
contests     : atcoder
status        : AC
problemtypes :
              - none

---



<!--more-->

# 問題概要
  数列Lとy/nの列Dが与えられる。D[i]=nのL[i]は残してD[i]=yであるL[i]を削除する。削除は区間に対して行える。[l,r]に対して削除を行う場合、[l,r]にあるD[i]=nなiのうち最大のL[i]をKとすると、L[j]>Kである全てのL[j]を消せる。
  
# 解法
  D[i]=yとなる最小のL[i]から削除していく。その時、一緒に消せる奴らを一緒に消していけば良い。

