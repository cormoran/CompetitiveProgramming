+++
title = "グラフ"
date = "2017-04-19T05:34:23+09:00"
[menu.library]
Name = "グラフ"
identifier = "Graph"
parent = ""
+++
<!--more-->

## 基本型

{{<libcode "graph_type.hpp">}}

## ダイクストラ

- $O((E+V)logV)$

{{<libcode "dijkstra.hpp">}}

## ベルマンフォード

- $O(VE)$

{{<libcode "bellmanford.hpp">}}

## ワーシャルフロイド

- $O(V^3)$

{{<libcode "warshall_floyd.hpp">}}

## クラスカル法

- $O(ElogV)$

{{<libcode "kruskal.hpp">}}

## プリム法

- $O(ElogV)$

{{<libcode "prim.hpp">}}

## 橋・関節点（切断点）の列挙

{{<libcode "./bridge_and_articulation.hpp">}}

## 最小共通祖先

{{<libcode "./lowest_common_ancestor.hpp">}}

## 最大流

{{<libcode "./max_flow.hpp">}}

## 最小費用流

{{<libcode "./min_cost_flow.hpp">}}

## 強連結線分分解

### 蟻本

{{<libcode "./strongly_connected_components_ant.hpp">}}

### Tarjan

{{<libcode "./strongly_connected_components_tarjan.hpp">}}

### 閉路検出

{{<libcode "./strongly_connected_components_detect_cycle_ant.hpp">}}

{{<libcode "./strongly_connected_components_detect_cycle_tarjan.hpp">}}

### 2-SAT

{{<libcode "./two_sat.hpp">}}

## 木の直径

{{<libcode "./tree_diameter.hpp">}}


## 木の重心

{{<libcode "./tree_centroid.hpp">}}
