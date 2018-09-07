#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
const ll INFL = 1LL << 60;

struct Edge{
    int to;
    long long cost;
    Edge(int to,long long cost):to(to),cost(cost){}
};
using EdgeList = std::vector<std::vector<Edge>>;

//コストが負の平路を含む場合要素ゼロで返す
//ret[i] == INFならiには到達不可
vector<ll> bellmanford(int start, const EdgeList &G, vector<ll> dist = {}){
    int n = G.size();
    if(dist.size() == 0) {
        dist.resize(n, INFL);
        dist[start] = 0;
    }
    rep(cnt,n){
        bool updated = false;
        rep(i,n){
            for(Edge e : G[i]){
                if(dist[i] != INFL and dist[e.to] > dist[i] + e.cost){
                    dist[e.to] = dist[i] + e.cost;
                    updated = true;
                    // if( cnt == n-1 ) return {};
                }
            }
        }
        if(not updated) break;
    }
    return dist;
}

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        EdgeList E(N);
        rep(i, M) {
            int a, b, c; cin >> a >> b >> c;
            a--; b--; 
            E[a].push_back(Edge(b, -c));
        }
        auto res = bellmanford(0, E);
        auto res2 = bellmanford(0, E, res);
        if(res[N-1] != res2[N-1]) cout << "inf" << endl;
        else cout << -res[N - 1] << endl;
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
