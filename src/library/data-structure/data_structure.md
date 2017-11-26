+++
title = "データ構造"
date = "2017-02-13T02:46:09+09:00"
[menu.library]
Name = "データ構造"
identifier = "DataStructure"
parent = ""
+++

<!--more-->

## UnionFind

- 集合の結合:  O(A(n))
- 要素が同じ集合か判定: O(A(n)) A(n)はアッカーマン関数の逆関数

結合はさぼっているので...

{{<libcode "union_find.hpp">}}

## Binary Indexed Tree

- ある点への加算: $O(logN)$
- 区間の和: $O(logN)$
- **1-based index であることに注意**

最深部は1bit目が1、その上は1bit目0で2bit目が1...となるようにインデックス付けする



{{<libcode "./binary_indexed_tree.hpp">}}

## Segment Tree

インデックスに関するメモ

~~~
担当区間
  [            1-8            ]
  [    1-4    ]   [    5-8    ]
  [1-2]   [3-4]   [5-6]   [7-8]
  1   2   3   4   5   6   7   8

1-based-index
           1
      2          3
   4    5     6     7
  8 9 10 11 12 13 14 15
  o o  o  o  o  o  o  o

  親 = 子/2
  実データ格納場所 n to 2n-1

0-based-index
           0
      1          2
    3   4     5     6
   7 8 9 10 11 12 13 14
   o o o  o  o  o  o  o

  親 = (子-1)/2
  実データ格納場所 n-1 to 2n-2
~~~

### 1. RMQ型 （点更新・区間クエリ）

- １点の更新: $O(logN)$
- 区間[a, b)へのクエリ: $O(logN)$

- BITはこれの区間を[0, b)に制限したもの．
- 演算に逆元がある場合は，BITでもこれと同等のことができる（RSQなど)

{{<libcode "./segtree1.hpp">}}

### 2. 遅延伝搬型　（区間更新，点クエリ）

{{<libcode "./segtree2.hpp">}}

### 3. 融合　（区間更新，区間クエリ）

{{<libcode "./segtree3.hpp">}}

### いい感じのデバッグ表示

{{<libcode "./segtree_debug.hpp">}}

### 一般化されていない実装

{{<libcode "./range_sum_query.hpp">}}