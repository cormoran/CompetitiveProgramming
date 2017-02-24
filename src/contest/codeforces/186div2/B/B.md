---
title        : codeforces-186div2-B
date         : 2015-12-03
contests     : codeforces
problemtypes :

---

# Ilya and Queries

<!--more-->

## 問題概要

s = s1 s2 s3 ... sn

si ∈{'.','#'} とする

上の列に対し、m個のクエリli,riが与えられる。

各クエリに対し、li <= k < ri を満たすkについて、sk = sk+1 となるようなkの総数を答えよ。


## 解法

累積和を取っておいてやるだけ


~~~

bool solve(){
    string s; cin >> s;
    int n = s.size();
    s += " ";
    vector<int> sum(n+1); // [ )
    sum[0] = 0;
    rep(i,n){
        sum[i+1] = sum[i] + (s[i] == s[i+1]);
    }
    debug(sum);

    int m; cin >> m;
    rep(i,m){
        int l,r; cin >> l >> r;
        cout << sum[r-1] - sum[l-1] <<endl;
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