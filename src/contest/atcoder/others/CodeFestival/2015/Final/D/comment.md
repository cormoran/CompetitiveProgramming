---
title        : CodeFestival-2015-Final-D
date         : 2015-11-17
contests     : codefestival
status       : AC
problemtypes :
- RMQ
---

足ゲームII

<!--more-->

# 問題概要
  N個の仕事がある。それぞれは時刻[si,ti)に行われる。N-1個以上の仕事をこなすのに必要な最小人数を求める
  
# 解法
  とりあえず+1,-1するやつで各時間での仕事の重複数を求める。その上にRMQを構築して、仕事iをしない時の最大重複数を全部求めればいい。
  時間の最大値をTとして、O(TlogT)

