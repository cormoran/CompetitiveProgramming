---
title        : DDPC2016-Final-A
date         : 2016-02-22T21:00:56+09:00
contests     : atcoder
problemtypes :

---

# [DISCO presents ディスカバリーチャンネルプログラミングコンテスト 2016 Ⅱ](http://discovery2016-final.contest.atcoder.jp/tasks/discovery_2016_final_a)

適当に読んで適当に投げたせいで変に時間がかかったのは秘密。

<!--more-->

## 問題概要

DDPCにはN人が参加している。

コンテストの順位順に座席番号が与えられるので、座席番号順に各人の獲得賞金を出力せよ。

（賞金はリンク参照）
  
## 解法

やるだけだけど、mapを使うと楽かもしれないと思ってmapを使った。

が、vectorで0に初期化された配列を作っておけば同じことなので、そっちの方がまだ良い気がする。

~~~

#include<iostream>
#include<vector>
#include<map>
using namespace std;
 
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

bool solve(){
    int n; cin >> n;
    map<int,int> m;
    int points[] = {100000, 50000, 30000, 20000, 10000};
    rep(i,n){
        int id; cin >> id;
        if(i < 5)m[id] = points[i];
    }
    rep(i,n){
        cout << m[i+1] <<endl;
    }
    return false;
}
 
int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~