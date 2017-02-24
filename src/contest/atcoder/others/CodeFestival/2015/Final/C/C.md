---
title        : CodeFestival-2015-Final-C
date         : 2015-11-17
contests     : atcoder
status       : AC
problemtypes :

---

# C:寿司タワー

<!--more-->

## 問題概要
  a,bからなる文字列を作る、行える操作は以下3つで、3の操作回数を最小化する

+ abを追加
+ baを追加
+ a or bを追加して残りを取っておく、取っておいたのはいつでも追加できる

## 解法
  貪欲的に行えば良いらしい。貪欲??と思いつつもイメージがしづらくて怪しいなとなって、DP方向で書こうとしてしまって一度飛ばした。
  貪欲っぽい問題でよくわからないのは、とりあえず貪欲書いてみてそのあとじっくり反例とか考えるのが良さそうだと毎回思うけどできてない...


~~~
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

const char KOME = '0';
const char NETA = '1';

typedef pair<int,int> state;

bool solve(){
    int N;cin>>N;
    string S;cin>>S;
    int i=0;
    int kome=0,neta=0;
    while(i<(int)S.size()){
        if(i+1<S.size() and S[i]=='0' and S[i+1]=='1')i++;
        else if(i+1<S.size() and S[i]=='1' and S[i+1]=='0')i++;
        else {
            if(S[i]==KOME)neta++;
            else kome++;
        }
        i++;
    }
    int ans = min(kome,neta);
    kome-=ans;neta-=ans;
    cout << ans + kome + neta<<endl;
    
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~