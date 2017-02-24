---
title        : atcoder-CodeFestival-2015-Thanks-A
date         : 2015-12-05
contests     : atcoder
status        : AC
problemtypes :

---
 
# A.金庫

<!--more-->

## 問題概要

  -100 ... 0 ... 100 の数列上で、0 -> A -> B -> 0 のように移動する。最短経路で移動した場合の道のりは？ 

## 解法

やるだけ


~~~
//  atcoder-CodeFestival-2015-Thanks-A  / 2015-12-05
#include<iostream>
using namespace std;
bool solve(){
    int n,m; cin >> n >> m;
    int ans = 0;
    ans += abs(n - 0);
    ans += abs(m - n);
    ans += abs(0 - m);
    cout << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~