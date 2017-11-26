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
    ll sum(ll x) {
        return x * (x + 1) / 2;
    }
    bool solve() {
        ll D, L, N; cin >> D >> L >> N;
        vector<ll> G(N); cin >> G;
        G.push_back(0);
        G.push_back(D);
        sort(all(G));
        D *= 2;
        L *= 2;
        rep(i, G.size()) G[i] *= 2;

        ll all_num = 0;
        ll push = 0;
        rep(i, G.size() - 1) {
            ll x = G[i], y = G[i + 1];
            if(y - x <= L) {
                all_num += y - x + 1;
                continue;
            }
            ll k = (x + L + y) / 2;
            ll a = k - (x + L);
            if(a > 0) a--;
            all_num += a;
            push += sum(a);
            ll b = y - k;
            all_num += b;
            push += sum(b);
        }
        double ans = push;
        ans = ans / D / 2;
        printf("%.10lf\n", ans);
        return 0;
    }
};

int main() {
    Solver s;
    s.solve();
    return 0;
}
