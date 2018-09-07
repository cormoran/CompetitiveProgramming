#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

struct UnionFind{
    int n;
    vector<int> p;
    vector<int> size;
    UnionFind(int nn) {
        n = nn + 1; // 1-based safe
        p.resize(n);
        size.resize(n);
        rep(i, n) p[i] = i;
        rep(i, n) size[i] = 1;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) {
            p[y] = x;
            size[x] += size[y];
        }
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
    int query_size(int x) {
        return size[root(x)];
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
    int Q; cin >> Q;
    vector<int> X(Q), Y(Q), Z(Q);
    rep(q, Q) {
        cin >> X[q] >> Y[q] >> Z[q];
        X[q]--; Y[q]--;
    }

    auto is_ok = [&] (int q, UnionFind &uf) {
        int a = uf.query_size(X[q]);
        int b = uf.query(X[q], Y[q]) ? 0 : uf.query_size(Y[q]);
        return a + b >= Z[q];
    };

    vector<pii> que, nxt_que;
    vector<int> l(Q, 0), r(Q, M); // (l, r]
    auto push = [&] (int q) {
     if(r[q] - l[q] > 1) nxt_que.emplace_back((l[q] + r[q]) / 2, q);
    };
    rep(q, Q) push(q);
    swap(que, nxt_que);
    while(que.size()) {
        nxt_que.clear();
        UnionFind uf(N);
        sort(begin(que), end(que));
        int pos = 0;
        rep(i, M) {
            uf.unite(E[i].first, E[i].second);
            while(pos < que.size() and que[pos].first == i + 1) {
                int m = que[pos].first;
                int q = que[pos].second;
                pos++;
                (is_ok(q, uf) ? r[q] : l[q]) = m;
                push(q);
            }
        }
        swap(nxt_que, que);        
    }
    rep(q, Q) cout << r[q] << endl;
    return 0;
}
