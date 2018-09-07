#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

vector<int> gen_primes(int upper) {
    vector<char> is_prime(upper, true);
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < upper; i++) {
        if(not is_prime[i]) continue;
        for(int j = i * 2; j < upper; j += i) is_prime[j] = false;
    }
    vector<int> res;
    rep(i, is_prime.size()) if(is_prime[i]) res.push_back(i);
    return res;
}

class Solver {
  public:
    bool solve() {
        const ll upper = 1e9 + 1;
        vector<int> primes = gen_primes(100000);
        int pi = 0;

        int l = 0, r = 1;
        rep(i, 100) {
            rep(r_, 10) {
                ll prod = 1;
                rep(j, 20) {
                    if(prod * primes[j])
                }
            }

            ll a_ = primes[pi++];
            ll b_ = primes[pi++];
            ll a = 1, b = 1;
            while(true) {
                if(a * b * a_ < upper) a *= a_;
                if(a * b * b_ < upper) b *= b_;
            }
            cout << a * b << endl;
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
