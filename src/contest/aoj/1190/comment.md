+++
date = "2017-06-26T21:21:58+09:00"
title = "AOJ1190 Anchored Balloon"
tags = ["None"]
href = "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1190&lang=jp"

+++

ふうせんをとばそう．

<!--more-->

## 解法

一番高く上がった位置では，少なくとも一つのロープがぴったり張っているはず．また，３次元なので，３点からの距離が決まれば点が一つに定まって，４つ目のロープはあってもなくても良い．

なので，１つのロープがぴったり張る場合，２つのロープがぴったり張る場合，３つのロープがぴったり張る場合の３通りを調べれば良い．

実装はつらかった．

一番高く上がる位置のx-y平面での候補点が決められるようで，各点で高さを２分探索するのが賢いようだった...

## 実装

{{<code "main.comp.cpp">}}