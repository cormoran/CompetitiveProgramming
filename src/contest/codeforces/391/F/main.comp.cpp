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

// group の最小値を求める機能を加えたUF
template<class T>
struct UnionFind {
    int n;
    vector<int> p;
    vector<pair<T, int>> sdom; // sdom, node
    UnionFind(int n):n(n) {
        p.resize(n);
        sdom.resize(n);
        rep(i, n) sdom[i] = make_pair(INF, i);
        rep(i, n) p[i] = i;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) {
            p[y] = x;
            set_min(sdom[x], sdom[y]);
        }
    }
    void set_sdom(int x, T value) {
        assert(root(x) == x); // こうでない時に更新すると不整合が生じる
        sdom[x].first = value;
    }
    T get_min_sdom_on_path_of_root_to(int x) {
        return sdom[root(x)].first;
    }
    int get_min_sdom_node_on_path_of_root_to(int x) {
        return sdom[root(x)].second;
    }
};

using EdgeList = vector<vector<int>>;
// r を中心とするDominator Treeを作る
// (E, r) : rを中心とするflow graph (rから任意のnodeにいける)
EdgeList make_dominator_tree(const EdgeList &Eorg, int r) {
    int N = Eorg.size();    
    vector<int> parent(N, -1), index(N, -1), rindex(N);
    // index : org index -> local index
    // rindex : local index -> org index
    // parent: local index
    { // flow graph (E, r) に対し，dfs木を作る
        int cnt = 0;
        function<void(int, int)> dfs = [&] (int now, int pre) -> void {
            index[now] = cnt;            
            rindex[cnt++] = now;
            parent[index[now]] = index[pre];
            for(int nxt : Eorg[now]) {
                if(index[nxt] < 0) {
                    dfs(nxt, now);
                }
            }
        };
        dfs(r, -1);
        assert(cnt == N); // 全ての点を訪れた
        debug(index); debug(rindex);
    }    
    EdgeList E(N), rE(N);
    rep(i, N) for(int nxt : Eorg[i]) {
        E[index[i]].push_back(index[nxt]);
        rE[index[nxt]].push_back(index[i]);
    }
    // --- ここから全てlocal index ---
    vector<int> sdoms(N);
    vector<vector<int>> backet(N);
    vector<int> tmp(N); // あとで使う
    { //        
        UnionFind<int> uf(N);
        auto calc_sdom = [&](int w) {
            int sdom = INF;
            // v -> w であるv
            for(int v : rE[w]) set_min(sdom, v);
            // min[sdom(u) | u > w and (u->*v and v->w なるvが存在) ]
            for(int v : rE[w]) {
                set_min(sdom, uf.get_min_sdom_on_path_of_root_to(v));
            }
            assert(sdom < INF);
            return sdom;
        };
        for(int i = N - 1; i >= 0; i--) {
            int sdom = calc_sdom(i); // rindex
            backet[sdom].push_back(i);
            uf.set_sdom(i, sdom);
            for(int j : backet[i]) tmp[j] = i;
            uf.unite(parent[i], i);
            sdoms[i] = sdom;
        }
    }
    debug(sdoms);
    vector<int> idom(N);
    { // 
        rep(i, N) {
            idom[i] = sdoms[i] == sdoms[tmp[i]] ? sdoms[i] : idom[tmp[i]];
        }
    }
    EdgeList dominator_tree(N);
    rep(i, N) {
        dominator_tree[idom[i]].push_back(i);
    }
    debug(idom);
    return dominator_tree;
}

void print_tree(const EdgeList &E, int root, ostream &os = cerr) {
    function<void(int, int)> dfs = [&] (int now, int pre) {        
        for(int nxt : E[now]) if(nxt != pre) dfs(nxt, now);
        os << now << " ";
    };
    dfs(root, -1);
    os << endl;
}

class Solver {
  public:
    bool solve() {
        int N, M, S; cin >> N >> M >> S;
        S--;
        EdgeList E(N);
        rep(i, M) {
            int a, b, c; cin >> a >> b >> c;
            a--; b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        EdgeList dom = make_dominator_tree(E, S);
        print_tree(dom, 0);
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
