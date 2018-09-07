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
        n = nn;
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

struct Edge {
    int a, b;
    ll c;
    bool used;
};

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<ll> C(N); cin >> C;
        vector<vector<Edge>> E(M);
        rep(i, M) {
            Edge e; cin >> e.a >> e.b >> e.c;
            e.a--; e.b--;
            E[e.a].push_back(e);
            swap(e.a, e.b);
            E[e.b].push_back(e);
        }
        UnionFind uf(N);
        vector<ll> group_c = C;
        vector<int> group_ok(N);
        vector<int> visited(N);
        ll sum = 0;
        rep(i, N) {
            if(visited[i]) continue;
            ll c = group_c[uf.root(i)];
            bool ok = false;
            for(auto e : E[i]) {
                if(e.c < c and not uf.query(i, e.b)) {
                    set_min(group_c[uf.root(i)], group_c[uf.root(e.b)]);
                    set_min(group_c[uf.root(e.b)], group_c[uf.root(i)]);
                    if(group_ok[uf.root(e.b)]) group_ok[uf.root(i)] = true;
                    uf.unite(i, e.b);
                    sum += e.c;
                    ok = true;
                    break;
                }
            }
        }

        function<bool(int, ll&)> go = [&] (int now, ll &min_c) {
            set_min(min_c, C[now]);
            for(auto e: E[now]) {
                if(e.c < min_c and not uf.query(now, e.b)) {
                    bool res = is_ok[e.b];
                    uf.unite(now, e.b);
                    return go(e.b, min_c);
                }
            }
            return false;
        };
        rep(i, N) {

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
