---
title        : atcoder-Jag-2016-domestic-A
date         : 2016-04-24
contests     : atcoder
problemtypes :

---

# [A - 阿吽の呼吸](http://jag2016-domestic.contest.atcoder.jp/tasks/jag2016secretspring_a)

<!--more-->


## 問題概要

Aさんは"A"という

Bさんはそれに対し"Un"と返事する

"A" or "Un" が n個与えられる。Bさんが正しく返事していれば"YES"、さもなくば"NO"を出力せよ。

ただし、返事が遅れることは許されており、Aさんが2回"A"と言った後にBさんが2回"Un"を言うような場合等は正しく返事しているものとする。
    
## 解法

上から見ていって、どの場所でも、それより上の"Un"の数が"A"の数を超えていない かつ 最終的に"A" と "Un" の数が同じ、かどうか調べるだけ。


~~~

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
int main(){
    int n; cin >> n;
    int a = 0, b = 0;
    bool flg = true;
    rep(i, n) {
        string s; cin >> s;
        if(s == "A") a++;
        else if(s == "Un") b++;
        if(a < b) flg = false;
    }
    cout << (flg and a == b ? "YES" : "NO") << endl;
    
    return 0;
}

~~~