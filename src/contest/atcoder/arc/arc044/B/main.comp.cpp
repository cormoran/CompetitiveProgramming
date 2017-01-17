//  atcoder-arc-044-B  / 2015-12-29
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
ModInt inverse(const ModInt &n){ return pow(n, ModInt::MOD - 2); }
ModInt factorial(const ModInt &n){
    ll ret =1;
    for(ll i=n.x; i>1; i--) ret*=i;
    return ModInt(ret);
}

ostream& operator << (std::ostream& os,const ModInt& a){ os << a.x; return os;}
istream& operator >> (std::istream& is,ModInt& a){ is >> a.x; return is;}

bool solve(){
    int N; cin >> N;
    vector<int> A(N); cin >> A;
    if(A[0] != 0){
        cout << 0 <<endl;
        return false;
    }
    sort( all(A) );
    vector<int> num(N+1);
    rep(i,A.back()+1){
        num[i] = upper_bound( all(A), i) - lower_bound( all(A), i);
    }
    if(num[0] > 1){
        cout << 0 <<endl;
    } else {
        ModInt ans = 1;
        bool flg = true;
        rep(i,A.back()+1){
            if(i==0) continue;
            if(flg == false and num[i] > 0){
                cout << 0 <<endl;
                return false;
            } else if(num[i] == 0) flg = false;
            
            ModInt tmp = pow(ModInt(2), num[i-1]) - ModInt(1);
            tmp = pow(tmp,num[i]);
            tmp *= pow(ModInt(2), (ll)num[i]*(num[i]-1)/2);
            ans *= tmp;
        }
        cout << ans <<endl;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
