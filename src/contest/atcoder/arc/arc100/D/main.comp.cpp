#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const ll INFL = 1LL << 62;


class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<ll> A(N); cin >> A;
        vector<ll> acc(N + 1);
        rep(i, N) {
            acc[i + 1] = acc[i] + A[i];
        }
        ll ans = INFL;
        rep(m, N) {
            // [0, m), [m, N)
            if(m - 0 < 2 or N - m < 2) continue;
            ll s1 = acc[m], s2 = acc[N] - s1;

            int lm = lower_bound(begin(acc) + 1, begin(acc) + m + 1, s1 / 2) - begin(acc) - 1;
            int rm = lower_bound(begin(acc) + m + 1, end(acc), s1 + s2 / 2) - begin(acc) - 1;
            assert(0 <= lm and lm <= m);
            assert(m <= rm and rm <= N);
            repeat(i, max(0, lm - 5), min(lm + 5, m)) {
                repeat(j, max(m, rm - 5), min(rm + 5, N)) {
                    // [0, i) [i, m) [m, j) [j, N)
                    if(i - 0 < 1 or m - i < 1 or j - m < 1 or N - j < 1) continue;
                    assert(0 < i and i < m and m < j and j < N);
                    auto v = { acc[i], acc[m] - acc[i], acc[j] - acc[m], acc[N] - acc[j] };
                    set_min(ans, abs(max(v) - min(v)));
                }
            }
        }
        assert(ans < INFL);
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
