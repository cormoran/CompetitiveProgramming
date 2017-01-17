#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class ModInt{
  public:
    static const ll MOD = 1000 * 1000 * 1000 + 9;
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

ostream& operator << (std::ostream& os,const ModInt& a){ os << a.x; return os;}
istream& operator >> (std::istream& is,ModInt& a){ is >> a.x; return is;}


// ラグランジュ補間
//  点群(xi, yi) i = 0 ... n + 1 から
//  n次関数f(x) の値を求める
//  O(n^2)
template<class T>
ModInt lagrange_interpolation(vector<T> xs, vector<T> ys, ModInt x) {
    ModInt ret = 0;
    rep(i, ys.size()) {
        ModInt prod = 1;
        rep(j, ys.size()) if(j != i) {
            prod *= (x - xs[j]) * inverse(xs[i] - xs[j]);
        }
        ret += prod * ys[i];
    }
    return ret;
}


const vector<int> coins = {1, 5, 10, 50, 100, 500};

class Solver {
  public:
    bool solve() {
        vector<vector<ModInt>> dp(6, vector<ModInt>(3001));
        rep(i, 3001) dp[0][i] = 1;
        repeat(i, 1, 6) {
            rep(j, 3001) {
                for(int k = 0; k * coins[i] <= j; k++)
                    dp[i][j] += dp[i - 1][j - coins[i] * k];
            }
        }

        int T; cin >> T;
        while(T--) {
            ll M; cin >> M;

            ModInt ans = 0;

            vector<ModInt> xs, ys;
            rep(i, 6) xs.push_back(i);
            rep(i, 6) ys.push_back(dp[5][i * 500 + M % 500]);
            
            cout << lagrange_interpolation(xs, ys, M / 500) << endl;
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;    
    s.solve();
    return 0;
}
