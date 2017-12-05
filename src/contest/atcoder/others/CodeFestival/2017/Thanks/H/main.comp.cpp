#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

// Wighted Quick Find ?
struct QuickFind {
    vector<int> parent;
    vector<set<int>> group;
    QuickFind(int n) {
        rep(i, n) parent.push_back(i);
        rep(i, n) group.push_back({i});
    }
    int root(int x) {
        return parent[x] == x ? x : root(parent[x]);
    }
    void unite(int x, int y, function<void(const QuickFind&, int, int)> on_unite = nullptr) {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(group[x].size() < group[y].size()) swap(x, y);
        // x become parent
        if(on_unite) on_unite(*this, x, y);
        parent[y] = x;
        group[x].insert(all(group[y]));
        group[y].clear();
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    int q; cin >> q;
    map<int, map<int, vector<int>>> Q;
    rep(i, q) {
        int x, y; cin >> x >> y;
        x--; y--;
        Q[x][y].push_back(i);
        Q[y][x].push_back(i);
    }    
    vector<int> ans(q, -1);
    int step = 0;
    auto on_unite = [&] (const QuickFind &qf, int large, int small) {
        for(int x : qf.group[small]) {
            for(auto p : Q[x]) {
                int y = p.first;
                if(qf.group[large].count(y)) {
                    for(int idx : p.second) ans[idx] = step;
                }
            }
        }
    };
    QuickFind qf(N);
    rep(i, M) {
        step++;
        qf.unite(A[i], B[i], on_unite);
    }
    rep(i, q) cout << ans[i] << endl;
    
    return 0;
}
