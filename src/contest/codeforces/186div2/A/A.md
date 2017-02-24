---
title        : codeforces-186div2-A
date         : 2015-12-03
contests     : codeforces
status        : AC
problemtypes :

---

# Ilya and Bank Account

<!--more-->

## 問題概要

（負の数を含む）整数nが与えられる。
n = (-) nk nk-1 ...n^l... n2 n1 n0 （それぞれは、nの10^lの桁の数値）とする。
以下の３つの数のうち、最大のものを出力する

- n
- n0 を削除した n' = nk nk-1 ...n^l... n2 n1
- (n1が存在する場合) n1 を削除した n''= nk nk-1 ...n^l... n2 n0

## 解法

やるだけ

~~~

bool solve(){
    string s,t,u; cin>> s;
    t = s;
    u = s;

    if(s.size() == 1){
        cout << max(0,stoi(s)) << endl;;
    } else {
        if(t[t.size()-1] != '-') t.erase(t.size()-1,1);
        if(u.size() >=2 and u[u.size()-2] != '-') u.erase(u.size()-2,1);
    }
    if( t == "-" ) t = "0";
    if( u == "-" ) u = "0";
    
    cout << max( stoi(s), max(stoi(t),stoi(u))) <<endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~