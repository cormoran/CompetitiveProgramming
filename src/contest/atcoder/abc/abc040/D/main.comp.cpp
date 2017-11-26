#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

struct UnionFind{
    int n;
    vector<int> p;
    vector<int> num;
    UnionFind(int nn) {
        n = nn + 1; // 1-based safe
        p.resize(n);
        num.resize(n);
        rep(i, n) {
            p[i] = i;
            num[i] = 1;
        }
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) {
            p[y] = x;
            num[x] += num[y];
        }
    }
    int group_size(int x) {
        return num[root(x)];
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
};

struct Edge {
    int a, b, y;
    bool operator < (const Edge &r) const {
        return y > r.y;
    }
};
using Query = tuple<int, int, int>;

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<Edge> E;
        rep(m, M) {
            int a, b, y; cin >> a >> b >> y;
            E.push_back(Edge{a - 1, b - 1, y});
        }
        sort(all(E));
        // for(auto e : E) cerr << "E: " << e.a << " <-> " << e.b << " " << e.y << endl;

        UnionFind uf(N);

        int Q; cin >> Q;        
        vector<Query> query;
        rep(q, Q) {
            int v, w; cin >> v >> w;
            query.emplace_back(make_tuple(w, v - 1, q));
        }
        auto get_year = [] (const Query &q) { return get<0>(q); };
        auto get_town = [] (const Query &q) { return get<1>(q); };
        auto get_index = [] (const Query &q) { return get<2>(q); };        
        sort(all(query), greater<tuple<int, int, int>>());        
        
        vector<int> ans(Q);
        auto itr = begin(E);
        for(Query q : query) {
            // cerr << "Q: " << get_index(q) << " " << get_town(q) << " " << get_year(q) << endl;
            while(itr != end(E) and itr->y > get_year(q)) {
                uf.unite(itr->a, itr->b);
                itr++;
            }
            ans[get_index(q)] = uf.group_size(get_town(q));
        }
        rep(i, Q) cout << ans[i] << endl;
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
