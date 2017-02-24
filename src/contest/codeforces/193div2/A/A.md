---
title        : codeforces - 332 - A
date         : 2016-01-07
contests     : codeforces
problemtypes :

---

# Down the Hatch!

問題文がつらい

## 問題概要

n(>=4)人が輪になってゲームをする。

　各ターンにつき１人が行動Aまたは行動Bを行う。順番はAくんから始め、時計回りに交代していく。
今,iくんのターンである時、iくんの直前3人のとった行動が同じで、かつiくんがその３人と同じ行動をとれば、iくんはジュースを飲める。（直前に行動をとった人が３人未満の場合は飲めない。）

　１回のゲームでの各人の行動が時系列順に与えられるので、Aくんが最適な行動していた時にジュースを飲めるはずだった回数を答えよ。（Aくんの行動が変わってもその後の他の人の行動は変わらないとする）

<!--more-->

## 解法

Aくんの直前３人の行動を見ていけば良い


~~~
//  codeforces - 332 - A  / 2016-01-07
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

bool solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep(i,s.size()){
        if(i >= 3 and  i % n == 0){
            if(s[i-1] == s[i-2] and s[i-2] == s[i-3]){
                ans++;
            }
        }
    }
    cout << ans <<endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~