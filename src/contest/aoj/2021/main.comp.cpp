#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;

struct Edge{
    int to;
    int cost;
    int from; // from は使わないことも多い
    Edge(int to, int cost, int from = -1):to(to), cost(cost), from(from) {}
};

using EdgeList = vector<vector<Edge>>;

struct State {
    int index, cost, left;
    bool operator > (const State &r) const { return cost > r.cost; }
};

// O(ElogV)
vector<int> dijkstra(const EdgeList &G, const set<int> &frozen_city, int start, int M) {
    priority_queue<State, vector<State>, greater<State>> que;
    vector<vector<int>> dp(G.size(), vector<int>(M + 1, INF));
    que.push(State{start, 0, M});
    dp[start][M] = 0;
    while(not que.empty()){
        State now = que.top(); que.pop();
        for(Edge e : G[now.index]){
            if(now.left >= e.cost) {
                State nxt = State{ e.to, now.cost + e.cost, now.left - e.cost };
                if(frozen_city.count(e.to)) nxt.left = M;
                if(dp[e.to][nxt.left] > now.cost + e.cost) {
                    dp[e.to][nxt.left] = nxt.cost;
                    que.push(nxt);
                }
            }
        }
    }
    vector<int> dist(G.size(), INF);
    rep(i, G.size()) rep(j, M + 1) {
        set_min(dist[i], dp[i][j] + max(0, dp[i][j] - M));
    }
    return dist;
}

class Solver {
  public:
    bool solve() {
        int N, M, L, K, A, H; cin >> N >> M >> L >> K >> A >> H;
        if(N == 0) return false;
        set<int> froze_city;
        rep(i, L) {
            int a; cin >> a;
            froze_city.insert(a);
        }
        EdgeList E(N);
        rep(i, K) {
            int a, b, c; cin >> a >> b >> c;
            E[a].push_back(Edge(b, c));
            E[b].push_back(Edge(a, c));
        }
        int ans = dijkstra(E, froze_city, A, M)[H];
        if(ans < INF) cout << ans << endl;
        else cout << "Help!" << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
