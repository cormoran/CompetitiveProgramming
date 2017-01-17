---
title        : codeforces-184div2-B
date         : 2015-11-19
contests     : codeforces
status        : AC
problemtypes :
              - gcd

---

Continued Fractions

<!--more-->

# 問題概要
　与えられる分数と連分数が等しいかどうか判定する

# 解法
  分数の方を連分数展開して比べる。

　最後の項を 4 などのままにするか 3 + 1/1 まで展開するかの２通りの展開があることに注意

　Pythonのfructionとかを使うと連分数部分を普通の分数に戻していくだけでできる

　自分はよくわからなくなって一度連分数展開してから比べたが、再帰的にやるともっとスッキリできそうだと思った。

