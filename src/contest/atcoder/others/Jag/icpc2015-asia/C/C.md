---
title        : atcoder-Jag-icpc2015-asia-C
date         : 2015-11-22
contests     : atcoder
problemtypes :

---

<!--more-->

## 問題概要
  数列Lとy/nの列Dが与えられる。$D[i]=n$の$L[i]$は残して$D[i]=y$である$L[i]$を削除する。削除は区間に対して行える。$[l,r]$に対して削除を行う場合、$[l,r]$にある$D[i]=n$なiのうち最大の$L[i]$をKとすると、$L[j]>K$である全ての$L[j]$を消せる。
  
## 解法
  $D[i]=y$となる最小の$L[i]$から削除していく。その時、一緒に消せる奴らを一緒に消していけば良い。



~~~
//  atcoder-Jag-icpc2015-asia-C  / 2015-11-22
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

const int INF = 1 << 30;
vector<string> D;
vector<int> L;

bool solve(){
    int N; cin >> N;
    D.resize(N);
    L.resize(N);
    int left = 0;
    rep(i,N){
        cin >> D[i] >> L[i];
        if(D[i] == "y")left++;
    }
    int ans = 0;
    while(left){
        //最小を探す
        int min_len = INF,min_idx = -1;
        rep(i,N){
            if(D[i]=="y" and min_len > L[i]){
                min_len = L[i];
                min_idx = i;
            }
        }
        ans++;
        for(int i = min_idx;i>=0;i--){
            if(D[i]=="n" and L[i]>=min_len) break;
            if(D[i]=="y"){
                D[i]="";
                left--;
            }
        }
        for(int i = min_idx;i<N;i++){
            if(D[i]=="n" and L[i]>=min_len) break;
            if(D[i]=="y"){
                D[i]="";
                left--;
            }
        }
    }
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~