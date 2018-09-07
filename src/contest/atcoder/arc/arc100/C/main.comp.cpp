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


class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<ll> A(N); cin >> A;

        auto f = [&] (ll b) {
            b -= 1e9;
            ll sum = 0;
            rep(i, N) sum += abs(A[i] - (b + i + 1));
            return sum;
        };

        ll l = 0, r = 2 * (1e9) + 1;
        while(l + 10 < r) {
            ll m1 = (2 * l + r) / 3;
            ll m2 = (l + r * 2) / 3;
            // cerr << l << " " << r << " " << m1 << " " << m2 << endl;;
            ll v1 = f(m1), v2 = f(m2);
            if(v1 > v2) {
                l = m1;
            } else {
                r = m2;
            }
        }
        ll a = INFL;
        repeat(i, l, r + 1) set_min(a, f(i));
        cout << a << endl;

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
