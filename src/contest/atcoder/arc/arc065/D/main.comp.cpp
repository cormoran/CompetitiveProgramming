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

//0 to n-1 でも1 to nでもOK
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
    vector<set<int>> make_group() {
        vector<set<int>> tree(n);
        rep(i, n) tree[root(i)].insert(i);
        return tree;
    }
};


class Solver {
  public:
    bool solve() {
        int N, K, L; cin >> N >> K >> L;
        UnionFind road(N), train(N);
        rep(i, K) {
            int a, b; cin >> a >> b;
            road.unite(a - 1, b - 1);
        }
        rep(i, L) {
            int a, b; cin >> a >> b;
            train.unite(a - 1, b - 1);
        }
        vector<int> ans(N, -1);
        auto road_group = road.make_group();
        auto train_group = train.make_group();

        rep(i, N) {
            if(ans[i] >= 0) continue;
            int rr = road.root(i), tr = train.root(i);
            set<int> &gs = road_group[rr].size() <= train_group[tr].size() ? road_group[rr] : train_group[tr];
            set<int> &gl = road_group[rr].size() >  train_group[tr].size() ? road_group[rr] : train_group[tr];
            vector<int> u;
            for(int j : gs) {
                if(gl.count(j)) u.push_back(j);
            }
            for(int j : u) ans[j] = u.size();
        }
        rep(i, N) cout << ans[i] << (i == N - 1 ? "\n" : " ");
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
