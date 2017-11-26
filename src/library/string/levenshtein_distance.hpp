/*
  文字列どうしのレーベンシュタイン距離を求める
  ref : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=jp
 */

#pragma once

int Levenshtein_Distance(std::string s1,std::string s2){
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
      DP[i][j]=min( DP[i][j] , DP[i-1][j-1] + (s1[i-1]==s2[j-1]?0:1) );
      //注意 : i,j=1toなのでs1,s2のindexは-1する
    }
  }
  return DP[n][m];
}
