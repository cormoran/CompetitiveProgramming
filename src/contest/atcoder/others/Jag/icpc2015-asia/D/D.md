---
title        : atcoder-Jag-icpc2015-asia-D
date         : 2015-11-22
contests     : atcoder
status        : NONE
problemtypes :

---

<!--more-->

## 問題概要
  方向の書いたボードが一列に並んでいる。ボードに乗ると指定方向に移動し、そのボードは無効になる（次以降はスルーする）。任意の場所からスタートできる場合、無効にできる最大のボード数を求めよ。
  
## 解法
　$S[i]$から始める場合、$S[i]$より左の'>'の数lと右の'<'の数rのみを見れば良い。$S[i]$の向きによって場合分けがして考えるとlとrの関係で出て行く方向がわかる。

　$S[i]$がどちらか一方の場合のみを考え、逆の場合はSを反転すれば良い。


~~~
//  atcoder-Jag-icpc2015-asia-D  / 2015-11-22
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

int max_sweep(string s){
    int n = s.size();
    vector<int> lsum(n+1),rsum(n+1); // [ , )
    rep(i,n){
        lsum[i+1] = lsum[i] + (s[i]=='<');
        rsum[i+1] = rsum[i] + (s[i]=='>');
    }
    debug("lsum",lsum);
    debug("rsum",rsum);
    int ret = 0;
    rep(i,n){
        if(s[i] == '<'){
            debug("start",i);
            int l = rsum[i]; 
            int r = lsum[n] - lsum[i+1];
            debug("l",l,"r",r);
            if(l <= r){
                //左抜け
                int sweep = lower_bound( begin(lsum)+i+1,end(lsum), l+lsum[i+1] ) - begin(lsum);
                debug("sweep",sweep);
                assert(sweep <= n);
                ret = max(ret, sweep);
            } else {
                //右抜け
                int unsweep = lower_bound( begin(rsum),begin(rsum)+i+1, l-(r+1)+1 ) - begin(rsum) -1;
                debug("unsweep",unsweep);
                assert(unsweep < i+1);
                ret = max(ret,n - unsweep);
            }
        }
    }
    return ret;
}

bool solve(){
    int n; cin >> n;
    string s,t; cin >> s;
    t = s;
    reverse(begin(t),end(t));
    rep(i,t.size()) t[i] = (t[i] == '<' ? '>' : '<');
    cout << max( max_sweep(s) , max_sweep(t)) << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~