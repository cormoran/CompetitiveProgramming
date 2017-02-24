---
title        : codeforces - 338div2 - D
date         : 2016-01-08
contests     : codeforces
draft        : false
status       : NONE
problemtypes :

---

# [Multipliers](http://codeforces.com/contest/615/problem/D)

## 問題概要

自然数nが素因数分解された形で与えられる。

nのすべての約数の総積 mod 1000000000+7 を求めよ。


<!--more-->

## 解法

$nのすべての約数の積 = n^{\frac{nの約数の個数}{2}}$


という定理を使う。

nの約数の個数は、中学校で習った素因数分解を使った方法で求められる

ただ、愚直にやると累乗の部分がオーバーフローするのでうまくやらないといけない。

まt、nが平方数なら累乗部分の分子は奇数になるのであらかじめ平方根を取っておかないといけない。



~~~
//  codeforces - 338div2 - D  / 2016-01-08
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
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

class ModInt{
 public:
  //You can divide if MOD is prime number. 
  static const ll MOD = 1000000007LL;
  
  long long x;
  ModInt(){};
  ModInt(ll x_):x((x_%MOD+MOD)%MOD){};
  static const ModInt pow(const ModInt &n,ll r);
  static const ModInt inverse(const ModInt &n);
  static const ModInt inverse2(const ModInt &n);  
  const ModInt operator +(const ModInt &l)const{return ModInt(x+l.x);}
  const ModInt operator -(const ModInt &l)const{return ModInt(x-l.x);}
  const ModInt operator *(const ModInt &l)const{return ModInt(x*l.x);}
  
  friend std::ostream& operator << (std::ostream& os,ModInt& a){os<<a.x;return os;}
  friend std::istream& operator >> (std::istream& is,ModInt& a){is>>a.x;return is;}
};

const ModInt ModInt::pow(const ModInt &n, ll r){
  if(r==0)return 1;
  ModInt ret=pow(n,r/2);
  ret=ret*ret;
  if(r%2!=0)ret= ret*n;
  return ret;
}

bool solve(){
    int m; cin >> m;
    vector<int> p(m); cin >> p;
    sort(all(p));

    vector<pair<int,int>> primes;
    int tmp = p[0];
    int num = 0;
    bool is_sq = true;
    rep(i,m){
        if(p[i] == tmp) num++;
        else {
            if(num %2 != 0) is_sq = false;
            primes.push_back(make_pair(tmp,num));
            num = 1;
            tmp = p[i];
        }
    }
    if(num %2 != 0) is_sq = false;
    primes.push_back(make_pair(tmp,num));

    
    ModInt x = 1;
    rep(i,primes.size()){
        int r = primes[i].second ;
        if( is_sq ) r /= 2;
        x = x * ModInt::pow(primes[i].first, r);
    }
    ModInt ans = x;
    bool flg = false;
    rep(i, primes.size()){
        int r = primes[i].second + 1;
        if(not is_sq and not flg and r%2 == 0){
            r /= 2;
            flg = true;
        }
        ans = ModInt::pow(ans,r);
    }
    
    cout << ans.x <<endl;
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~