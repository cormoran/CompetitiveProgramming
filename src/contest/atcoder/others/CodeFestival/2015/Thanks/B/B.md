---
title        : atcoder-CodeFestival-2015-Thanks-B
date         : 2015-12-05
contests     : atcoder
status        : AC
problemtypes :

---

# 袋とボール

<!--more-->

書くだけ


## ソースコード

~~~

bool solve(){
    vector<int> A(2),B(2);
    int c;
    cin >> A >> B >> c;
    vector<int> ans;
    rep(i,2){
        if(A[i] == c) ans.insert(ans.end(),all(B));
        if(B[i] == c) ans.insert(ans.end(),all(A));
    }
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    cout << ans.size() <<endl;
    rep(i,ans.size()) cout << ans[i] <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~