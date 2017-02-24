---
title        : codeforces-184div2-B
date         : 2015-11-19
contests     : codeforces
problemtypes :

---

# Continued Fractions

<!--more-->

## 問題概要
　与えられる分数と連分数が等しいかどうか判定する

## 解法
  分数の方を連分数展開して比べる。

　最後の項を 4 などのままにするか 3 + 1/1 まで展開するかの２通りの展開があることに注意

　Pythonのfructionとかを使うと連分数部分を普通の分数に戻していくだけでできる

　自分はよくわからなくなって一度連分数展開してから比べたが、再帰的にやるともっとスッキリできそうだと思った。


~~~
//  codeforces-184div2  / 2015-11-19
#include<iostream>
#include<vector>
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


template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

template<typename T>
void reduce_fraction(T &p,T &q){
    T g = gcd(p,q);
    p /= g; q /= g;
}

vector<ll> ContinuedFractionDecomposition(ll p,ll q){
    vector<ll> ret;
    while(p>1){
        ret.push_back(p/q);
        p = p % q;
        swap(p,q);
    }
    return ret;
}

bool solve(){
    ll p,q;cin>>p>>q;
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];

    reduce_fraction(p, q);
    
    if(n == 1){
        cout << ( q == 1 and p == a[0] ? "YES" : "NO" ) <<endl;
        return 0;
    }

    vector<ll> decomp = ContinuedFractionDecomposition(p, q);
    
    if(decomp.size() == a.size() - 1 and decomp.size() > 0 and decomp.back() > 1 ){
        ll t = decomp.back()-1;
        decomp.pop_back();
        decomp.push_back(t);
        decomp.push_back(1);
    } else if(decomp.size() != a.size()){
        cout <<  "NO" <<endl;
        return false;
    }
    
    cout <<  (decomp == a ? "YES" : "NO") <<endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~