//  codeforces-191div2-C  / 2015-12-17
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

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

class ModInt{
  public:
    static const ll MOD = 1000000007LL; 
    ll x;
    ModInt():x(0){};
    ModInt(ll x_){
        x_%=MOD;
        if(x_<0)x_+=MOD;
        x=x_;
    }
    ModInt& operator += (const ModInt &l){x+=l.x;if(x>=MOD)x-=MOD;return *this;};
    ModInt& operator -= (const ModInt &l){x-=l.x;if(x<0)x+=MOD;return *this;}
    ModInt& operator *= (const ModInt &l){x=x*l.x%MOD;return *this;}
    ModInt operator +(const ModInt &l)const{return ModInt(x+l.x);}
    ModInt operator -(const ModInt &l)const{return ModInt(x-l.x);}
    ModInt operator *(const ModInt &l)const{return ModInt(x*l.x);}

    static ModInt pow(const ModInt &n,ll r){
        if(r==0)return 1;
        ModInt ret=pow(n,r/2);
        ret=ret*ret;
        if(r%2!=0)ret= ret*n;
        return ret;
    }
    static ModInt inverse(const ModInt &n){return pow(n, MOD-2);}

    static ModInt factorial(const ModInt &n){
        ll ret =1;
        for(ll i=n.x;i>1;i--){ret*=i;}
        return ModInt(ret);
    }
    
    friend std::ostream& operator << (std::ostream& os,ModInt& a){os<<a.x;return os;}
    friend std::istream& operator >> (std::istream& is,ModInt& a){is>>a.x;return is;}
};

bool solve(){
    string s; cin >> s;
    ll n = s.size();
    ll k; cin >> k;
    ModInt sum = 0;
    rep(i,s.size()){
        if(s[i] == '0' or s[i] == '5'){
            ll l = i;
            debug("l",l,"n",n,"k",k);
            ModInt tmp = ModInt::pow(2, l);
            ModInt mole = ModInt::pow( ModInt::pow(2, k) , n) - 1;
            ModInt deno = ModInt::pow(2, n) - 1;
            debug("mole",mole.x,"deno",deno.x);
            tmp *= mole;
            tmp *= ModInt::inverse(deno);
            sum += tmp;
            debug("sum",sum.x,"tmp",tmp.x);
        }
    }
    cout << sum.x << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
