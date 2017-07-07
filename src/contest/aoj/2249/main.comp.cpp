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

struct Edge {
    int to, dist, cost, index;
};

struct State {
    int index;
    ll cost;
    State(int i, ll c):index(i), cost(c) {}
    bool operator > (const State &r) const { return cost > r.cost; }
};

// O(ElogV)
vector<ll> dijkstra(const vector<vector<Edge>> &G, int start, int M) {
    priority_queue<State, vector<State>, greater<State>> que;
    vector<ll> dist(G.size(), INFL);
    que.emplace(start, 0);
    dist[start] = 0;
    while(not que.empty()) {
        State now = que.top(); que.pop();
        if(G[now.index].size() > 0) {
            Edge min_edge = G[now.index][0];
            for(Edge e : G[now.index]) {
                if(dist[e.to] > now.cost + e.dist) {
                    State nxt = State(e.to, now.cost + e.dist);
                    dist[e.to] = nxt.cost;
                    que.push(nxt);
                }
            }
        }
    }
    return dist;
}

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        if(N == 0) return 0;
        vector<vector<Edge>> E(N);
        vector<int> edge_cost(M);
        rep(i, M) {
            int u, v, d, c; cin >> u >> v >> d >> c;
            u--; v--;
            E[u].push_back(Edge{v, d, c, i});
            E[v].push_back(Edge{u, d, c, i});
            edge_cost[i] = c;
        }
        auto dist = dijkstra(E, 0, M);
        vector<char> used(M);
        ll ans = 0;
        repeat(i, 1, N) {
            ll min_c = INFL;
            Edge min_e;
            min_e.index = -1;
            for(Edge e : E[i]) {
                if(dist[e.to] + e.dist == dist[i]) {
                    if(set_min<ll>(min_c, e.cost)) min_e = e;
                }
            }
            if(not used[min_e.index]) ans += min_e.cost;
            used[min_e.index] = 1;
        }
        cout << ans << endl;
        return 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
