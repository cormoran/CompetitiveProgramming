+++
title = "yukicoder No.199 星を描こう"
date = "2016-11-15T23:51:38+09:00"
href = "http://yukicoder.me/problems/433"
+++

<!--more-->

## 概要

５つの点が与えられるので、星型かどうか判定する問題

## 解法

まず始点a を選ぶ。点bを選んだ時$\overrightarrow{ab}$に対して、残り３点の位置関係を求めると、星型なら、３点全てが同じ側に来るようなbが２つ、１点と２点に別れるようなbが２つあるはず。これを全てのaについて調べた。

通ったけど、これで十分条件なのかは知らない。

凸五角形になってるか判定が良さそう。凸包作って...ってくらいまではパッと考えてたけど、色々考えてるうちに忘れた。

## 実装

{{<code "main.comp.cpp">}}
