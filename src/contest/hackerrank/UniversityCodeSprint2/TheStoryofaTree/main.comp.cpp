#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

class Solver {
  public:
    vector<int> calc_parent(vector<vector<int>> &E, int root) {
        vector<int> parent(E.size());
        function<void(int, int)> f = [&](int now, int pre) {
            parent[now] = pre;
            for(int nxt : E[now]) {
                if(nxt != pre) f(nxt, now);
            }
        };
        f(root, -1);
        return parent;
    }
    int propagate_point(vector<vector<int>> &E, int root, vector<int> &point, int K) {
        int cnt = 0;
        function<void(int, int)> f = [&](int now, int pre) {
            if(pre >= 0) point[now] += point[pre];
            for(int nxt : E[now]) {
                if(nxt != pre) f(nxt, now);
            }
            // cerr << "@ " << now << " " << point[now] << endl;
            cnt += point[now] >= K;
            assert(point[now] >= 0);
        };
        f(root, -1);
        return cnt;
    }
    
    bool solve() {
        int Q; cin >> Q;
        rep(q, Q) {
            int N; cin >> N;
            vector<vector<int>> E(N);
            rep(i, N - 1) {
                int a, b; cin >> a >> b;
                a--; b--;
                E[a].push_back(b);
                E[b].push_back(a);
            }
            vector<int> parent = calc_parent(E, 0);
            
            int G, K; cin >> G >> K;            
            vector<int> node(N, 0);
            rep(g, G) {
                int u, v; cin >> u >> v;
                u--; v--;
                if(parent[v] == u) {
                    node[v]--;
                    node[0]++;
                } else if(parent[u] == v) {
                    node[u]++;
                } else {
                    assert(0);
                }
            }
            int ok = propagate_point(E, 0, node, K);
            int gg = ok > 0 ? gcd(ok, N) : N;
            cout << ok / gg << "/" << N / gg << endl;
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
