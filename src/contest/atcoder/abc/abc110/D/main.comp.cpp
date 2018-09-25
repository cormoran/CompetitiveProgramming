#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

class ModInt {
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
    static map<ll, ll> cache;
    if(cache.count(n.x)) return cache[n.x];
    auto res = pow(n, ModInt::MOD - 2);
    cache[n.x] = res.x;
    return res;
}

ModInt factorial(const ModInt &n){
    static map<ll, ll> cache;
    if(cache.count(n.x)) return cache[n.x];
    ModInt ret = 1;
    for(ll i = n.x; i>1; i--){
        ret *= i;
    }
    cache[n.x] = ret.x;
    return ret;
}

vector<int> generate_primes(int N) {
    vector<int> primes;
    vector<int> is_prime(N, true);
    repeat(i, 2, N) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i * 2; j < N; j += i) is_prime[j] = false;
        }
    }
    return primes;
}

map<int, int> prime_factorization(int N) {
    map<int, int> res;
    auto primes = generate_primes(sqrt(N) + 10);
    for(int p : primes) {
        while(N % p == 0) {
            res[p] += 1;
            N /= p;
        }
    }
    if(N > 1) res[N] = 1;
    return res;
}

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;

        auto factors = prime_factorization(M);

        ModInt ans = 1;
        vector<int> bs;
        for(auto p : factors) {
            int b = p.second;
            ans *= factorial(b + N - 1) * inverse(factorial(b) * factorial(N - 1));
        }
        cout << ans.x << endl;
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
