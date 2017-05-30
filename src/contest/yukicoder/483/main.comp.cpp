#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

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
};

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<vector<int>> E;
        {
            map<pii, int> mp;
            int cnt = 0;
            auto input = [&]() {
                pii p; cin >> p.first >> p.second;
                p.first--; p.second--;
                if(not mp.count(p)) mp[p] = cnt++;
                return mp[p];
            };
            rep(i, N) {
                int s = input(), e = input();
                E.resize(cnt);
                E[s].push_back(e);
                E[e].push_back(s);
            }
        }
        
        UnionFind uf(E.size());
        rep(i, E.size()) for(int j : E[i]) uf.unite(i, j);

        vector<bool> visited(E.size());
        bool ok = true;
        rep(i, E.size()) {
            if(visited[i]) continue;
            int v = 1, e = E[i].size();
            visited[i] = true;
            rep(j, E.size()) if(uf.query(i, j) and not visited[j]) {
                visited[j] = true;
                v++;
                e += E[j].size();
            }
            e /= 2;
            ok &= v - e >= 0;
            // cerr << v << " " << e << " " << v - e << endl;
        }
        cout << (ok ? "YES" : "NO") << endl;
        
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
