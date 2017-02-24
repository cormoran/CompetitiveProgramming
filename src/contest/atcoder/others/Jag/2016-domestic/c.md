---
title        : atcoder-Jag-2016-domestic-C
date         : 2016-04-24
contests     : atcoder
problemtypes :
- 構文解析

---

# [C - みさわさんの根付き木](http://jag2016-domestic.contest.atcoder.jp/tasks/jag2016secretspring_c)

<!--more-->

## 問題概要

各ノードに値を持つ二つの根付き木がある。

二つを以下のように合成して新しい根付き木を作れ。


1. 新しい木のノードXの値は、２つの各木の、Xに対応する場所のノードの値同士を足したものである

2. ２つの木どちらか一方でも、Xに対応する場所にノードがない場合、新しい木のその場所は空にする


（つまり、２つの木のノードの存在についてANDをとって、ノードの値について和を取るイメージ）


なお、木は (右の木)[値](左の木) という形で与えられ、この形で出力する必要がある

## 解法

簡単なパーサを書く

自分は木を作るパーサ部と木から文字列に変換する部分をそれぞれ書いたが、一緒にやっていくと楽らしい（？）


~~~

#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
 
 
struct Node {
    int n;
    Node *l, *r;
};
 
Node* parse(string A, int &i) {
    assert(A[i] == '(');
    i++;
    if(A[i] == ')') { i++; return NULL; }
    Node *ret = new Node();
    ret->l = parse(A, i);
 
    assert(A[i++] == '[');
    ret->n = atoi(&A[i]);
    while(isdigit(A[i])) i++;
    assert(A[i++] == ']');
    
    ret->r = parse(A, i);
    i++;
    return ret;
}
 
string marge(Node *a, Node *b) {
    if(a == NULL or b == NULL) return "()";
    string ret = "";
    ret  += "(";
    ret += marge(a->l, b->l);
    ret += "[" + to_string(a->n + b->n) + "]";
    ret += marge(a->r, b->r);
    ret += ")";
    return ret;
}
 
bool solve() {
    string a, b; cin >> a >> b;
    int i = 0;
    a = "(" + a + ")";
    b = "(" + b + ")";
    Node * an = parse(a, i);
    i = 0;
    Node * bn = parse(b, i);
    string ans = marge(an, bn);
    cout << ans.substr(1, ans.size() - 2) << endl;
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~