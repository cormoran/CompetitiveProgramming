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

vector<uint8_t> sieve_of_eratosthenes(int n) {
    vector<uint8_t> ret(n + 1, 1);
    ret[0] = ret[1] = 0;
    repeat(i, 2, n + 1) {
        if(ret[i]) {
            for(int j = i * i; j < ret.size(); j += i) ret[j] = 0;
        }
    }
    return ret;
}
tuple<vector<uint8_t>, vector<int>> prime_production(int k, int n) { // [k, n]
    auto is_p = sieve_of_eratosthenes(n);
    vector<int> ret;
    repeat(i,k, n + 1) if(is_p[i]) ret.push_back(i);
    return make_tuple(is_p, ret);
}

class Solver {
  public:
    bool solve() {
        int N, X, Y; scanf("%d%d%d", &N, &X, &Y);        
        vector<int> A(N); rep(i, N) scanf("%d", &A[i]);
        
        vector<int> primes;
        vector<uint8_t> is_prime;
        tie(is_prime, primes) = prime_production(2, sqrt(*max_element(all(A))) + 1);

        map<int, int> cnt;
        rep(i, N) {
            int a = A[i];

            for(int p : primes) {
                int c = 0;
                while(a % p == 0) {
                    a /= p;
                    c++;
                }
                if(c > 0) cnt[p] ++;
                if(a == 1) break;
            }
            if(a > 1) cnt[a]++;
        }
        // for(pii p : cnt) debug(p);

        vector<pii> used_primes;
        for(auto p : cnt) {
            used_primes.push_back(pii(p.second, p.first));
        }
        sort(all(used_primes));
        reverse(all(used_primes));

        vector<int> expected_primes;
        expected_primes.push_back(2);
        rep(i, min<int>(100, used_primes.size())) expected_primes.push_back(used_primes[i].second);

        ll ans = (ll)X * N;
        //debug(expected_primes);
        for(int p : expected_primes) {
            ll tmp = 0;
            rep(i, N) {
                ll ub = (ll)(A[i] / p + (A[i] % p != 0)) * (ll)p;
                ll d1 = (ll)(ub - A[i]) * Y;
                ll d2 = X;
                tmp += min(d1, d2);
            }
            set_min(ans, tmp);
        }
        cout << ans << endl;
        return 0;
    }
};

int main() {
    Solver s;
    s.solve();
    return 0;
}
