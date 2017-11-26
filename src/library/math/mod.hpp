#pragma once

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
    ModInt& operator -= (const ModInt &l){ x -= l.x; if( x < 0 ) x += MOD; return *this; }
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

ModInt factorial(const ModInt &n){
    ll ret =1;
    for(ll i=n.x; i>1; i--){
        ret*=i;
    }
    return ModInt(ret);
}

ostream& operator << (std::ostream& os,const ModInt& a){ os << a.x; return os;}
istream& operator >> (std::istream& is,ModInt& a){ is >> a.x; return is;}
