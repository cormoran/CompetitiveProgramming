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

template<class T>
struct Edge {
    int to;
    T capacity, cost, rev;
};

template<class T=ll, T T_INF=INFL>
struct Flow {
    int N;
    vector<vector<Edge<T>>> E;

    Flow(int n) : N(n) {
        E.resize(N);
    }
    void add_arc(int from, int to, T cap, T cost = 0) {
        E[from].push_back(Edge<T>{to, cap, cost, (ll)E[to].size()}); // E[to].size() は下で追加する逆辺
        E[to].push_back(Edge<T>{from, 0, -cost, (ll)E[from].size() - 1}); // 逆辺
    }
    // s -> t に f だけ流す時の最小費用を計算，流せない時 - 1
    // 流すとグラフが壊れる
    T min_cost_flow(int s, int t, T f) {
        auto bellmanford = [&] (int s, vector<int> &prev_v, vector<int> &prev_e) {
            vector<T> dist(N, T_INF);
            dist[s] = 0;
            bool updated = true;
            while(updated) {
                updated = false;
                rep(v, N) {
                    if(dist[v] >= T_INF) continue;
                    rep(i, E[v].size()) {
                        auto &e = E[v][i];
                        if(e.capacity > 0 and set_min(dist[e.to], dist[v] + e.cost)) {
                            prev_v[e.to] = v;
                            prev_e[e.to] = i;
                            updated = true;
                        }
                    }
                }
            }            
            return dist;
        };
        
        T res = 0;
        vector<int> prev_v(N), prev_e(N);
        while(f > 0) {
            auto dist = bellmanford(s, prev_v, prev_e);
            if(dist[t] == T_INF) return -1;
            T d = f;
            // s -> t の最小コスト経路上の，最小容量 d を求める
            for(int v = t; v != s; v = prev_v[v]) {
                d = min(d, E[prev_v[v]][prev_e[v]].capacity);
            }
            // d だけ流す            
            for(int v = t; v != s; v = prev_v[v]) {
                auto &e = E[prev_v[v]][prev_e[v]];
                e.capacity -= d;
                E[v][e.rev].capacity += d;
            }
            f -= d;
            res += d * dist[t]; // 流した費用
        }
        return res;
    }

    // s -> t の 最大流
    // bad O(F|E|)
    // Edge.cost は不使用，流すとグラフが壊れる
    T max_flow(int s, int t) {
        function<T(int ,int ,T, vector<char>&)> dfs = [&] (int v, int t, T f, vector<char> &used) {
            if(v == t) return f;
            used[v] = true;
            for(auto &e : E[v]) {
                if(not used[e.to] and e.capacity > 0) {
                    T d = dfs(e.to, t, min(f, e.capacity), used);
                    if(d > 0) {
                        e.capacity -= d;
                        E[e.to][e.rev].capacity += d;
                        return d;
                    }
                }
            }
            return (T)0;
        };
        T flow = 0;
        for(;;) {
            vector<char> used(N);
            T f = dfs(s, t, T_INF, used);
            if(f == 0) return flow;
            flow += f;
        }
    }
};
    
class Solver {
  public:
    bool solve() {
        int V, E; cin >> V >> E;
        Flow<> graph(V);
        rep(i, E) {
            int u, v, c; cin >> u >> v >> c;
            graph.add_arc(u, v, c);
        }
        cout << graph.max_flow(0, V - 1) << endl; 
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
