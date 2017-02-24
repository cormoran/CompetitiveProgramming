---
title        : yukicoder-No186 典型DP(1)
date         : 2016-02-29T01:23:55+09:00
contests     : yukicoder
problemtypes :
- DP
- 木DP
- 典型
---

# [No.196 典型DP (1)](http://yukicoder.me/problems/234)

DDPC2016 Final C の類題

<!--more-->

[参考 : http://mayokoex.hatenablog.com/entry/2016/02/20/210128](http://mayokoex.hatenablog.com/entry/2016/02/20/210128)

## 問題概要

簡潔なので[本文参照](http://yukicoder.me/problems/234)

## 解法

木DPをして、O(N^3)に見えて実はO(N^2)というやつ。典型らしい。

$ dp[i][k] := $ノードiを根とする部分木でk個を黒く塗る塗り方の総数

とすると

$ dp[i] = dp[a] \ast dp[b] \ast ... \ast dp[c] $ ただし、a,b,...,cはiの子

と部分解の畳み込みで求められる。

計算量をf(N)とすると、長さX,Yの配列の畳み込みは$O(XY)$なので、

$ \begin{eqnarray}
	O(f(X+Y)) &=& O(f(X)) + O(f(Y)) + O(XY) \\\\
	          &=& O(X^2 + Y^2 + 2XY) \\\\
		  &=& O((X+Y)^2) \\\\
	     f(N) &=& O(N^2)		  
\end{eqnarray} $

（だと思う。）


~~~

#include<iostream>
#include<vector>
#include<cassert>
#include<string>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

using EdgeList = vector<vector<int>>;
const ll MOD = 1000000007;
EdgeList E;
int K;

#define maxIndex(x) (x.size() -1)

vector<ll> convolution(const vector<ll> &A, const vector<ll> &B){
    int max_value = maxIndex(A) + maxIndex(B);
    vector<ll> ret( min(K, max_value) + 1 );
    rep(i, A.size()){
        rep(j, B.size()){
            if(i + j <= K){
                ret[i+j] += A[i] * B[j];
                ret[i+j] %= MOD;
            }
        }
    }
    return ret;
}

vector<ll> dfs(int now, int pre){
    vector<ll> ret = {1};
    for(int nxt : E[now]){
        if(nxt != pre){
            ret = convolution(ret, dfs(nxt, now));
        }
    }
    if(maxIndex(ret) < K) ret.push_back(1);
    return ret;
}

bool solve(){
    int N; cin >> N >> K;
    E.resize(N);
    rep(i,N-1){
        int a, b; cin >> a >> b; 
        E[a].push_back(b);
        E[b].push_back(a);
    }
    vector<ll> ans = dfs(0, -1);
    cout << ( maxIndex(ans) >= K ? ans[K] : 0 )<< endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~