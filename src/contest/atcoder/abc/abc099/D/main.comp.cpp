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
        int N, C; cin >> N >> C;
        vector<vector<ll>> D(C, vector<ll>(C)); cin >> D;
        vector<vector<int>> G(N, vector<int>(N)); cin >> G;

        vector<vector<pair<ll, int>>> costs(3);
        rep(m, 3) {
            rep(c, C) {
                ll cost = 0;
                rep(y, N) {
                    rep(x, N) {
                        if((x + y) % 3 == m) {
                            cost += D[G[y][x] - 1][c];
                        }
                    }
                }
                costs[m].emplace_back(cost, c);
            }
            sort(all(costs[m]));
        }
        function<ll(int, set<int>&)> dfs = [&] (int m, set<int> &used) {
            if(m == 3) return 0ll;
            ll res = INFL;
            rep(i, 3) if(not used.count(costs[m][i].second)) {
                used.insert(costs[m][i].second);
                set_min(res, dfs(m + 1, used) + costs[m][i].first);
                used.erase(costs[m][i].second);
            }
            return res;
        };
        set<int> used;
        cout << dfs(0, used) << endl;
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
