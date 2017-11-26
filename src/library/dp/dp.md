+++
title = "動的計画法"
date = "2017-07-14T00:00:00+09:00"
[menu.library]
Name = "動的計画法"
identifier = "DynamicPrograming"
parent = ""
+++

典型的動的計画法のカンニングペーパー
<!--more-->

## 金額を作る問題

コイン $C_0,C_1,...,C_m$ で金額$N$を作る最小枚数を求めよ

~~~

DP[i][j] := $C_i$まで使って金額$j$を作るときの最小枚数
DP[i][j] = INF
DP[i][0] = 0
i++, j++
DP[i][j] = min(DP[i][j], DP[i-1][j-C[i]] + 1)

~~~

## ナップサック問題

合計容量$W$以下で総価値を最大化するように集めよ．重複はなし．

~~~

DP[i][j] := i番目まで使って，容量jで作れる最大価値
i++, j++
DP[i][j] = max(DP[i][j], DP[i - 1][j - W[i]] + C[i])

~~~

合計容量$W$以下で総価値を最大化するように集めよ．重複OK．

~~~
DP[i][j] := i番目まで使って，容量jで作れる最大価値
i++, j++
DP[i][j] = max(DP[i][j], DP[i][j - W[i]] + C[i])
                         -----
~~~

組み合わせの再現: 更新するときに覚えておく

~~~
重複ありの例
W[i]を使ったときに ITEM[n][w] = true; とする
while(ITEM[n][w]) {
    cnt++;
    w-=weight[n];
}
cnt が ITEM n を使った数
~~~

## 最長増加部分列 Longest Increasing Subsequence

~~~cpp
vector<int> v;
rep(i,n) {
    int a;
    cin>>a;
    auto itr=lower_bound(all(v), a);
    if(itr==v.end())v.push_back(a);
    else *itr=a;
}
v.size() is LIS
~~~

## 編集距離

文字列 s1 を s2 に変換する最短手順

可能な操作は　１文字の挿入・削除，任意の二点の置換

~~~cpp
 string s1,s2;
  cin>>s1>>s2;
  int m=s1.size();
  int n=s2.size();
  vector<vector<int>> DP(m+1,vector<int>(n+1));
  rep(i,n+1)DP[0][i]=i;
  rep(i,m+1)DP[i][0]=i;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      //s1[i]を削除 or s2[j]に挿入 の場合
      DP[i][j]=min( DP[i-1][j]+1 , DP[i][j-1]+1 );
      //置換してs1[i-1]とs2[j-1]を合わせる場合
      DP[i][j]=min( DP[i][j] , DP[i-1][j-1] + (s1[i-1]==s2[j-1]?0:1) ); //注意:i,j=1toなのでs1,s2のindexは-1する
    }
  }
  cout<<DP[m][n]<<endl;
~~~

## 巡回セールスマン問題

~~~cpp
int DP[1<<V_MAX][V_MAX]; //[S][now] : now から U\S を訪れて0に戻る最短コスト
int G[V_MAX][V_MAX]; // 隣接リスト
int V,E;
int rec(int S,int now){
  if( DP[S][now] >= 0 ) return DP[S][now];
  if( S == (1<<V)-1 && now==0 ) return DP[S][now]=0;
  int ret=INF;
  rep(v,V){
    if(( S & (1<<v)) || G[now][v] == INF)continue;
    ret = min( ret , rec(S | 1<<v,v)+G[now][v] );
  }
  return DP[S][now]=ret;
}
~~~

## 回文

~~~cpp
// dp[i][j] (i < j) := s[i]...s[j] から作れる最小回文の長さ
rrep(i, N) {
    repeat(j, i, N) {
        if(i == j) {
            dp[i][j] = 1;
        } else {
            if(S[i] == S[j]) dp[i][j] = (i + 1 == j ? 0 : dp[i + 1][j - 1]);
            dp[i][j] = min({ dp[i][j], dp[i + 1][j], dp[i][j - 1] });
            dp[i][j] += 2;
        }
    }
}
~~~

~~~
// dp2[i][j] (i < j) := s[i]..s[j] から作れる最小回文の組み合わせ数
void add_limited(ll &a, const ll &b) { a = a + b > INFL ? INFL : a + b; }
vector<vector<ll>> dp2(N, vector<ll>(N, 0));
rrep(i, N) {
    repeat(j, i, N) {
        if(i == j) {
            dp2[i][j] = 1;
        } else {
            if(S[i] == S[j]) {
                add_limited(dp2[i][j], (i + 1 == j ? 1 : dp2[i + 1][j - 1]));
            } else {
                ll mini = min({dp[i + 1][j], dp[i][j - 1] });
                if(dp[i + 1][j] == mini) add_limited(dp2[i][j], dp2[i + 1][j]);
                if(dp[i][j - 1] == mini) add_limited(dp2[i][j], dp2[i][j - 1]);
            }
        }
    }
}
~~~