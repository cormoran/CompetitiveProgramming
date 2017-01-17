//  atcoder - abc034 - C  / 2016-03-12
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

typedef long long ll;
class ModInt{
  public:
    static const ll MOD = 1000000007LL; 
    ll x;
    ModInt():x(0){};
    ModInt(ll x){
        while(x < 0) x += MOD;
        x %= MOD;
        this->x = x;
    }
    ModInt& operator += (const ModInt &l){ x += l.x; if( x >= MOD) x -= MOD; return *this; }
    ModInt& operator *= (const ModInt &l){ x = (x * l.x) % MOD; return *this; }
    ModInt operator +(const ModInt &l) const { return ModInt( x + l.x); }
    ModInt operator -(const ModInt &l) const { return ModInt( x - l.x); }
    ModInt operator *(const ModInt &l) const { return ModInt( x * l.x); }
};

// @warning rの部分はmodとってはいけない
ModInt pow(const ModInt &n, ll r){
    if(r == 0) return ModInt(1);
    ModInt ret = pow(n, r / 2);
    ret *= ret;
    if(r % 2 != 0) ret = ret * n;
    return ret;
}

// @waring nはMODと互いに素
ModInt inverse(const ModInt &n){
    return pow(n, ModInt::MOD - 2);
}

ll nCk(ll n,ll k){
    vector<ModInt> fact(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = fact[i-1] * i;
    }
    return (fact[n] * inverse(fact[k] * fact[n-k])).x;
}

bool solve(){
    int W, H; cin >> W >> H;
    cout << nCk(W + H - 2, W - 1) << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
