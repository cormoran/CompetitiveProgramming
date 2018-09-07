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
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

template <class T>
struct PersistentArray {
    int size;  // size of array
    int depth; // depth of subtree (-1 if leaf)
    T value;
    array<PersistentArray<T>*, 2> children = {};
    PersistentArray() = default;
    PersistentArray(const PersistentArray&) = default;
    PersistentArray(int arg_size) {
        size = arg_size;
        depth = 0;
        for(; 1 << depth < size; depth++);
        depth--;
    }
    const T& get(int i) const {
        if(depth == -1) return value;
        return children[local_index(i)]->get(child_index(i)); // TODO
    }
    T& get_mut(int i) {
        if(depth == -1) return value;
        auto &p = children[local_index(i)];
        p = p ? new PersistentArray(*p) : new PersistentArray(child_size());
        return p->get_mut(child_index(i)); // TODO
    }
    void set(int i, const T &val) {
        get_mut(i) = val;
    }
    int local_index(int i) const { return i >> depth; }
    int child_index(int i) const { return i & ((1 << depth) - 1); }
    int child_size() const { return 1 << depth; }
    T& operator [] (int i) { return get_mut(i); }
    const T& operator [] (int i) const { return get(i); }
};

struct PersistentUnionFind {
    PersistentArray<int> p; // if < 0 : root and -p[i] is size of tree
    PersistentUnionFind() = default;
    PersistentUnionFind(int n) : p(n) { // 0-indexed
        rep(i, n) p[i] = -1;
    }
    int root(int x) const {
        return p[x] == x ? x : root(p[x]);
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) {            
            if(query_size(x) < query_size(y)) swap(x, y);
            p[x] += p[y];
            p[y] = x;        
        }
    }
    bool query(int x,int y) const {
        return root(x) == root(y);
    }
    int query_size(int x) const {
        return p[root(x)] * -1;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    vector<pii> E(M);
    rep(i, M) {
        cin >> E[i].first >> E[i].second;
        E[i].first--; E[i].second--;
    }
    vector<PersistentUnionFind> ufs(M + 1);
    ufs[0] = PersistentUnionFind(N);
    rep(i, M) {
        ufs[i + 1] = ufs[i];
        ufs[i + 1].unite(E[i].first, E[i].second);
    }
    return 0;
    int Q; cin >> Q;
    vector<int> X(Q), Y(Q), Z(Q);
    rep(q, Q) {
        cin >> X[q] >> Y[q] >> Z[q];
        X[q]--; Y[q]--;
    }
    auto is_ok = [&] (int q, const PersistentUnionFind &uf) {
        int a = uf.query_size(X[q]);
        int b = uf.query(X[q], Y[q]) ? 0 : uf.query_size(Y[q]);
        return a + b >= Z[q];
    };

    rep(q, Q) {
        int l = 0, r = M;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            (is_ok(q, ufs[m]) ? r : l) = m;
        }
        cout << r << endl;
    }
    
    return 0;
}
