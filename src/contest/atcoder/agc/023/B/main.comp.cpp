#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
using ull = unsigned long long;
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
/*
  s := s1 s2 ... sn

  hash[1_to_i] := s1*b^(i-1) + s2*b^(i-2) + ... + si*b^0

  hash[1_to_j] := s1*b^(j-1) + s2*b^(j-2) + ... + si*b^(j-i) + ... + sj*b^0


  hash[(i+1)_to_j] = hash[1_to_j] - hash[1_to_i]*b^(j-i)

                   = s(i+1)*b^(j-i-1) + ... + sj*b^0
*/

typedef unsigned long long ull;
const ull HASH_BASE = 100000007;
// build O(N), query O(1)
// MOD は over-flow で代用している
array<ull, 1000> pow_base;
function<ull(int, int)> build_rolling_hash(const string &s) {
    int n = s.size();
    vector<ull> hash(n + 1);
    pow_base[0] = 1;
    rep(i, n) {
        hash[i + 1] = hash[i] * HASH_BASE + s[i];
        pow_base[i + 1] = pow_base[i] * HASH_BASE;
    }
    return [=] (int l, int r) {
        return hash[r] - hash[l] * pow_base[r - l];
    };
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<string> S(N); cin >> S;
        vector<function<ull(int, int)>> hash_r(3 * N), hash_c(3 * N);

        rep(i, 3 * N) {
            {
                int r = i;
                string s;
                s.reserve(3 * N);
                rep(j, 3 * N) s.push_back(S[(r + j) % N][j % N]);
                hash_r[i] = build_rolling_hash(s);
            }
            {
                int c = i;
                string s;
                s.reserve(3 * N);
                rep(j, 3 * N) s.push_back(S[j % N][(c + j) % N]);
                hash_c[i] = build_rolling_hash(s);
            }
        }
        ll ans = 0;
        rep(r, N) {
            rep(c, N) {
                bool ok = true;
                rep(i, N) {
                    ok &= hash_r[r - c + N + i](c, c + N) == hash_c[c - r + N + i](r, r + N);
                }
                ans += ok;
            }
        }
        cout << ans << endl;
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
