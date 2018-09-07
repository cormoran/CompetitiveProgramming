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

struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn) {
        n = nn + 1; // 1-based safe
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
    map<int, vector<int>> get_group() {
        map<int, vector<int>> res;
        rep(i, p.size()) {
            res[root(i)].push_back(i);
        }
        return res;
    }
};

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<int> A(N), B(N);
        rep(i, N) cin >> A[i] >> B[i];
        vector<vector<int>> orgE(N);
        vector<pii> Es(M);
        rep(i, M) {
            int u, v; cin >> u >> v;
            u--; v--;
            orgE[u].push_back(v);
            orgE[v].push_back(u);
            Es[i] = pii(u, v);
        }
        vector<int> indices(N); rep(i, N) indices[i] = i;
        sort(all(indices), [&]( int i, int j ) { return A[i] < A[j]; });

        vector<int> indices_e(M); rep(i, M) indices_e[i] = i;
        sort(all(indices_e), [&]( int i, int j ) { return max(A[Es[i].first], A[Es[i].second]) < max(A[Es[j].first], A[Es[j].second]); });
        debug(indices);
        debug(indices_e);

        vector<vector<int>> E(N);
        UnionFind uf(N);
        for(int ie : indices_e) {
            if(uf.query(Es[ie].first, Es[ie].second)) continue;
            E[Es[ie].first].push_back(Es[ie].second);
            E[Es[ie].second].push_back(Es[ie].first);
            uf.unite(Es[ie].first, Es[ie].second);
        }
        // for(int now : indices) {
        //     for(int nxt : orgE[now]) {
        //         if(uf.query(now, nxt) or A[nxt] > A[now]) continue;
        //         E[now].push_back(nxt);
        //         E[nxt].push_back(now);
        //         uf.unite(now, nxt);
        //     }
        // }

        function<tuple<ll,ll>(int, int)> dfs = [&] (int now, int prev) {
            debug(now);
            vector<ll> sums, ress;
            vector<int> is;
            ll sum = 0;
            for(int nxt : E[now]) {
                if(nxt == prev) continue;
                ll c, r;
                tie(c, r) = dfs(nxt, now);
                sum += c;
                sums.push_back(c);
                ress.push_back(r);
                is.push_back(nxt);
            }
            ll res = sum + B[now];
            rep(i, sums.size()) {
                set_min(res, max<ll>(ress[i], A[is[i]]) + sum - sums[i]);
            }
            return make_tuple(sum + B[now], res);
        };
        ll ans;
        tie(ignore, ans) = dfs(indices.back(), -1);
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
