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
    ll dfs(ll left, ll base, ll i) {
        //cerr << left << " : " << base << " : " << i << endl;
        if(base == 1) return left;
        ll p = i == 0 ? 0 : pow(base, i);
        ll res = INFL;
        set_min(res, dfs(left, base == 9 ? 6 : 1, 0));
        if(left >= p) {
            set_min(res, dfs(left, base, i + 1));
            for(ll j = 1; p * j <= left; j++) {
                set_min(res, dfs(left - p * j, base == 9 ? 6 : 1, 0) + j);
                set_min(res, dfs(left - p * j, base, i + 1) + j);
                if(p == 0) break;
            }
        }
        return res;
    }
    bool solve() {
        ll N; cin >> N;
        cout << dfs(N, 9, 0) << endl;
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
